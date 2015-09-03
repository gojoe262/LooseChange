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
                'immediate': true //Skip Authorization Popup. To Skip = true. To Show = false.
            }, handleAuthResult);
        }});
    }

    /**
     * Checks if the Google API authroization was successful.
     */
    function handleAuthResult(authResult) {
        if (authResult && !authResult.error) {
            //Success
            config.oauthToken = authResult.access_token;
            loadGoogleDriveAPI();
        } else {
            //Authorization Failed. Show popup.
            gapi.auth.authorize({
                'client_id': clientId,
                'scope': scope,
                'immediate': false //Show Authorization Popup. To Skip = true. To Show = false.
            }, handleAuthResult);
        }
    }

    /**
     * Load Google Client/Drive Load
     */
    function loadGoogleDriveAPI(){
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
                if(typeof options.mimeTypes != 'undefined'){
                    view.setMimeTypes(options.mimeTypes);
                }
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
     * Download a file from Google Drive.
     * @param options: fileId, onSuccess(resp), onFail()
     */
    function getData(options) {
        var accessToken = gapi.auth.getToken().access_token;
        var request = gapi.client.drive.files.get({
          'fileId': options.fileId
        });

        request.execute(function(resp){
            promisedAjaxCall({
                url: resp.downloadUrl,
                type: 'GET',
                dataType: 'json',
                headers: {'Authorization': 'Bearer ' + accessToken}
            }).done(function(resp){
                if(typeof options.onSuccess == 'function') options.onSuccess(resp);
            }).fail(function(){
                if(typeof options.onFail == 'function') options.onFail();
            });
        });
    }




    /**
     * Upload json data to Google Drive. Stored in Google Drive as text file.
     * @param options: metadata {title}, data, onSuccess, onFail
     */
    function uploadData(options){
        var accessToken = gapi.auth.getToken().access_token;
        //Create metadata
        var defaultMetadata = {
            title: 'LooseChange',
            mimeType: "application/json",
            //parents: [{id: 'appdata'}]
        };
        defaultMetadata = $.extend(defaultMetadata, options.metadata);

        //Stringify the data
        var strMetadata = JSON.stringify(defaultMetadata);
        var strData = JSON.stringify(options.data);

        //Create request form. (Combine metadata and )
        data = new FormData();
        data.append("metadata", new Blob([ strMetadata ], { type: "application/json" }));
        data.append("file", new Blob([ strData ], { type: "appliction/json" }));

        //var up = (typeof options.fileId != 'undefined') ? '/' + options.fileId : '';
        promisedAjaxCall({
            url: "https://www.googleapis.com/upload/drive/v2/files?uploadType=multipart",
            data: data,
            headers: {'Authorization': 'Bearer ' + accessToken},
            contentType: false,
            processData: false,
            type: 'POST' //POST to insert, PUT to update
        }).done(function(resp){
            if(typeof options.onSuccess == 'function') options.onSuccess(resp);
        }).fail(function(){
            if(typeof options.onFail == 'function') options.onFail();
        });
    }

    /**
     * Update/Upload file in Application Data Folder
     * @param options: metadata, data,
     */
    function updateFile(options){
        var accessToken = gapi.auth.getToken().access_token;
        var metadata;
        if(typeof options.fileId != 'undefined'){

            var request = gapi.client.drive.files.get({
              'fileId': options.fileId
            });

            request.execute(function(resp){

            });



            //Create metadata
            var defaultMetadata = {
                mimeType: "application/json",
                parents: [{id: 'appdata'}]
            };
            defaultMetadata = $.extend(defaultMetadata, options.metadata);
            var jsonMetadata = JSON.stringify(defaultMetadata);
        }

        //Create json data string
        var jsonData = JSON.stringify(options.data);

        //Create request form. (Combine metadata and )
        data = new FormData();
        data.append("metadata", new Blob([ jsonMeta ], { type: "application/json" }));
        data.append("file", new Blob([ jsonData ], { type: "appliction/json" }));

        var up = (typeof options.fileId != 'undefined') ? '/' + options.fileId : '';
        promisedAjaxCall({
            url: "https://www.googleapis.com/upload/drive/v2/files" + up + "?uploadType=multipart",
            data: data,
            headers: {'Authorization': 'Bearer ' + accessToken},
            contentType: false,
            processData: false,
            type: (typeof options.fileId != 'undefined') ? 'PUT' : 'POST'
        }).done(function(resp){
            if(typeof options.onSuccess == 'function') options.onSuccess(resp);
        }).fail(function(){
            if(typeof options.onFail == 'function') options.onFail();
        });
    }

    function promisedAjaxCall(options){
        var defaultOptions = {
            cache: false,
        };

        return $.ajax($.extend(defaultOptions, options));
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
        //other external functions/variables here
		authorize: authorize,
        picker: picker,
        getData: getData,
        //getFileListInApplicationDataFolder: getFileListInApplicationDataFolder,
        uploadData: uploadData,
        //promisedAjaxCall: promisedAjaxCall

	};
};
