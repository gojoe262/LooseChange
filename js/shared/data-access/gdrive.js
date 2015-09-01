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
     * Loads Google API
     */
    function authorize(){
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
            loadGoogleClient();
        } else {
            console.log('Unable to authorize Google API');
        }
    }

    function viewResults(){
        listFilesInApplicationDataFolder(function(results){
            var r = results;
        });
    }

    /**
     * Load Google Client/Drive Load
     */
    function loadGoogleClient(){
        gapi.load('client', {'callback': function(){
            gapi.client.load('drive', 'v2');
        }})
    }

    /**
     * Open Google Drive Picker.
     * @param options: onSelected(fileId), onCanceled(), onLoaded()
     */
    function picker(options){
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
                    .setCallback(function(data){
                        if(data.action == google.picker.Action.PICKED && (typeof options.onSelected == 'function')){
                            var fileId = data.docs[0].id;
                            options.onSelected(fileId);
                        } else if(data.action == google.picker.Action.CANCEL && (typeof options.onCanceled == 'function')){
                            options.onCanceled();
                        } else if(data.action == google.picker.Action.LOADED && (typeof options.onLoaded == 'function')){
                            options.onLoaded();
                        }
                    })
                    .build();

                picker.setVisible(true);
            }
            else {
                console.log('Unable to load Google Drive Picker API');
            }
        }});
    }

    /**
     * Callback for Google Drive Picker. Called when a file is picked.
     */
    // function onGoogleDrivePickerFilePicked(data) {
    //     if (data.action == google.picker.Action.PICKED) {
    //         var fileId = data.docs[0].id;
    //         showFileText(fileId);
    //     }
    // }

    /**
     * Dowload a file from Google Drive.
     * @param options: fileId, dataType, onSuccess(resp), onFail()
     */
    function getFileContent(options) {
        var accessToken = gapi.auth.getToken().access_token;
        var request = gapi.client.drive.files.get({
          'fileId': options.fileId
        });

        request.execute(function(resp){
            console.log('Downloading File\n' +
                        '    Title: ' + resp.title + '\n' +
                        '    Description: ' + resp.description + '\n' +
                        '    MIME type: ' + resp.mimeType);

            promisedAjaxCall({
                url: resp.downloadUrl,
                type: 'GET',
                dataType: (typeof options.dataType == 'undefined') ? 'json' : options.dataType,
                headers: {'Authorization': 'Bearer ' + accessToken}
            }).done(function(resp){
                if(typeof options.onSuccess == 'function') options.onSuccess(resp);
            }).fail(function(){
                if(typeof options.onFail == 'function') options.onFail();
            });
        });
    }

    function promisedAjaxCall(options){
        var defaultOptions = {
            cache: false,
        };

        return $.ajax($.extend(defaultOptions, options));
    }

    function uploadSampleFile(fileId){
        var metadata = {
            title: "LooseChange UploadSampleFile",
            mimeType: 'application/json',
            parents: [{id: 'appdata'}]
        }


        var fileData = {
            id: 123456,
            value: 44.45,
            type: "IN",
            category: "Gas"
        };

        data = new FormData();
        data.append("metadata", new Blob([ JSON.stringify(metadata) ], { type: "application/json" }));
        data.append("file", new Blob([ JSON.stringify(fileData) ], { type: "appliction/json" }));

        var accessToken = gapi.auth.getToken().access_token;
        var up = fileId === undefined ? '' : '/' + fileId;
        var promise = promisedAjaxCall({
            url: "https://www.googleapis.com/upload/drive/v2/files" + up + "?uploadType=multipart",
            data: data,
            headers: {Authorization: 'Bearer ' + accessToken},
            contentType: false,
            processData: false,
            type: fileId === undefined ? 'POST' : 'PUT'
        });




    }

    function getFileListInApplicationDataFolder(callback){
        var request = gapi.client.drive.files.list({
            'q': '\'appdata\' in parents'
        });
        request.execute(function(resp) {
            if(typeof callback == 'function') callback(resp.items);
        });
    }

    /**
     * Public functions/variables inside return statement
     */
	return {
		authorize: authorize,
        picker: picker,
        getFileContent: getFileContent,
        //getFileListInApplicationDataFolder: getFileListInApplicationDataFolder,
        //uploadSampleFile: uploadSampleFile,
        //promisedAjaxCall: promisedAjaxCall
		//other external functions/variables here
	};
};
