/**
 * http://www.codeproject.com/Articles/636699/JavaScript-Design-Patterns
 * Revealing Module Pattern
 */
gdrive = function(config){
    var self = this;

	var defaults = {
		developerKey: '',
		clientId: "",
		appId: "",
		scope: '',
		oauthToken: ''
	};

	config = $.extend(defaults, config);

	/**
     * Handle google api javascript load
     */
    function handleGoogleApiLoad(){
        //Set up Authorization for Google API
        gapi.load('auth', {'callback': function(){
            gapi.auth.authorize({
                'client_id': clientId,
                'scope': scope,
                'immediate': false
            }, handleAuthResult);
        }});
    }

    /**
     * Checks if the Google API authroization was successful.
     */
    function handleAuthResult(authResult) {
        if (authResult && !authResult.error) {
            config.oauthToken = authResult.access_token;

            //If successful, load the rest of the google api stuff.
            handleGoogleDrivePickerLoad();
            handleGoogleClientLoad();
        } else {
            console.log('Google API NOT authorized');
        }
    }

    /**
     * Handle Google Client/Drive Load
     */
    function handleGoogleClientLoad(){
        gapi.load('client', {'callback': function(){
            gapi.client.load('drive', 'v2');
        }})
    }

    /**
     * Handle google drive picker load.
     */
    function handleGoogleDrivePickerLoad(){
        gapi.load('picker', {'callback': function(){
            if (config.oauthToken) {
                var view = new google.picker.View(google.picker.ViewId.DOCS);
                //view.setMimeTypes("image/png,image/jpeg,image/jpg");
                var picker = new google.picker.PickerBuilder()
                    .enableFeature(google.picker.Feature.NAV_HIDDEN)
                    // .enableFeature(google.picker.Feature.MULTISELECT_ENABLED)
                    .setAppId(appId)
                    .setOAuthToken(config.oauthToken)
                    .addView(view)
                    .addView(new google.picker.DocsUploadView())
                    //.setDeveloperKey(developerKey)
                    .setCallback(onGoogleDrivePickerFilePicked)
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
    function onGoogleDrivePickerFilePicked(data) {
        if (data.action == google.picker.Action.PICKED) {
            var fileId = data.docs[0].id;
            showFileText(fileId);
        }
    }

    /**
    * Dowload a file from Google Drive and display it's text.
    */
    function showFileText(fileId) {
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

    /**
     * Public functions/variables inside return statement
     */
	return {
		handleGoogleApiLoad: handleGoogleApiLoad,
		//other external functions/variables here
	};
};
