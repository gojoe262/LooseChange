///http://coursesweb.net/javascript/create-use-class-javascript
///
///http://www.hacksparrow.com/how-to-create-class-in-javascript.html
///
/// public variables and functions prefaced with "this."
/// private variables and functions prefaced with "var "


gdriveAccessor = function(){
    //private variables
    var privateVariableOneExample = 1;

    //public variables
    this.developerKey = '';
    this.clientId = "";
    this.appId = "";
    this.scope = '';
    this.oauthToken = '';


    /**
     * Handle google api javascript load
     */
    this.handleGoogleApiLoad = function(){
        //Set up Authorization for Google API
        gapi.load('auth', {'callback': function(){
            gapi.auth.authorize({
                'client_id': clientId,
                'scope': scope,
                'immediate': false
            }, this.handleAuthResult);
        }});
    }

    /**
     * Checks if the Google API authroization was successful.
     */
    this.handleAuthResult = function(authResult) {
        if (authResult && !authResult.error) {
            this.oauthToken = authResult.access_token;

            //If successful, load the rest of the google api stuff.
            this.handleGoogleDrivePickerLoad();
            this.handleGoogleClientLoad();
        } else {
            console.log('Google API NOT authorized');
        }
    }

    /**
     * Handle Google Client/Drive Load
     */
    this.handleGoogleClientLoad = function(){
        gapi.load('client', {'callback': function(){
            gapi.client.load('drive', 'v2');
        }})
    }

    /**
     * Handle google drive picker load.
     */
    this.handleGoogleDrivePickerLoad = function(){
        gapi.load('picker', {'callback': function(){
            if (this.oauthToken) {
                var view = new google.picker.View(google.picker.ViewId.DOCS);
                //view.setMimeTypes("image/png,image/jpeg,image/jpg");
                var picker = new google.picker.PickerBuilder()
                    .enableFeature(google.picker.Feature.NAV_HIDDEN)
                    // .enableFeature(google.picker.Feature.MULTISELECT_ENABLED)
                    .setAppId(appId)
                    .setOAuthToken(this.oauthToken)
                    .addView(view)
                    .addView(new google.picker.DocsUploadView())
                    //.setDeveloperKey(developerKey)
                    .setCallback(this.onGoogleDrivePickerFilePicked)
                    .build();

                picker.setVisible(true);
                // console.log('Google Drive Picker API loaded successfully');
            }
            else {
                console.log('Unable to load Google Drive Picker API');
            }
        }});
    }

    /**
     * Callback for Google Drive Picker. Called when a file is picked.
     */
    this.onGoogleDrivePickerFilePicked = function(data) {
        if (data.action == google.picker.Action.PICKED) {
            var fileId = data.docs[0].id;
            this.showFileText(fileId);
        }
    }

    /**
    * Dowload a file from Google Drive and display it's text.
    */
    this.showFileText = function(fileId) {
        var accessToken = gapi.auth.getToken().access_token;
        var request = gapi.client.drive.files.get({
          'fileId': fileId
        });

        request.execute(function(resp){
            console.log('Downloading File\n' +
                        '    Title: ' + resp.title + '\n' +
                        '    Description: ' + resp.description + '\n' +
                        '    MIME type: ' + resp.mimeType + '\n' +
                        '    DownloadURL: ' + resp.downloadUrl);

            $.ajax({
                url: resp.downloadUrl,
                type: 'GET',
                dataType: 'text',
                cache: false,
                headers: {'Authorization': 'Bearer ' + accessToken },
            }).done(function(text){
                $('#documentText').html(text);
            }).fail(function(){
                console.log('Unable to download selected file\n' +
                             '    Title: ' + resp.title + '\n' +
                             '    Description: ' + resp.description + '\n' +
                             '    MIME type: ' + resp.mimeType);
            });
        });
    }
}
