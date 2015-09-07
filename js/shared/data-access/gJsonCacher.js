/**
 * http://www.codeproject.com/Articles/636699/JavaScript-Design-Patterns
 * Revealing Module Pattern
 *
 * gJsonCacher
 * Can get, insert, update, & delete JSON objects (json files).
 * Objects are stored in the user's Google Drive - Application Data folder.
 * The Application Data folder is hidden from the user.
 */
gJsonCacher = function(config){
    var self = this;

    var defaults = {
        // The Browser API key obtained from the Google Developers Console.
        // Replace with your own Browser API key, or your own key.
        developerKey: 'AIzaSyCAR6UKdY5VGl2oCCbD9tJi5IfI7TK7WPs',
        // The Client ID obtained from the Google Developers Console. Replace with your own Client ID.
        clientId: "759406020708-acqg5ibu2gh81lestg0t8vea08nqsh9l.apps.googleusercontent.com",
        // Replace with your own App ID. (Its the first number in your Client ID)
        appId: "759406020708",
        // Scope to access application data folder.
        scope: ['https://www.googleapis.com/auth/drive.appfolder'],
        // Token used to access Google Drive. This value is set when successfully authorized.
		oauthToken: ''
	};

	config = $.extend(defaults, config);

	/**
     * Loads Google API authorization.
     */
    function authorize(options){
        //Set up Authorization for Google API
        gapi.load('auth', {
            'callback': function(){
                gapi.auth.authorize({
                    'client_id': config.clientId,
                    'scope': config.scope,
                    'immediate': true //Skip Authorization Popup. To Skip = true. To Show = false.
                }, function(authResult){
                    handleAuthResult(authResult, options)
                });
            }
        });
    }

    /**
     * Checks if the Google API authroization was successful.
     * If not, show the popup.
     */
    function handleAuthResult(authResult, options) {
        if (authResult && !authResult.error) {
            //Success
            config.oauthToken = authResult.access_token;
            loadGoogleDriveAPI();
            if(typeof options.onSuccess == 'function') options.onSuccess();
        } else {
            //Authorization Failed. Show popup.
            gapi.auth.authorize({
                'client_id': config.clientId,
                'scope': config.scope,
                'immediate': false //Show Authorization Popup. To Skip = true. To Show = false.
            }, function(authResult){
                handleAuthResult(authResult, options);
            });
        }
    }

    /**
     * Load Google Client/Drive Load
     */
    function loadGoogleDriveAPI(){
        gapi.load('client', {
            'callback': function(){
                gapi.client.load('drive', 'v2');
            }
        })
    }

    /**
     * Get object from Google Drive Application Data folder.
     * @param options: name, onSuccess(object), onFail(errorText), always()
     */
    function getObject(options) {
        //Get the list of objects in application data folder.
        var request = gapi.client.drive.files.list({
            'q': '\'appdata\' in parents'
        });

        request.execute(function(resp) {
            var objectList = resp.items;
            $.each(objectList, function(index, value){
                var objectName = this.title;
                var objectDownloadUrl = this.downloadUrl;

                //Find the file that matches the object name
                if(objectName === options.name + ".json") {
                    //Call to download the object
                    promisedAjaxCall({
                        url: objectDownloadUrl,
                        type: 'GET',
                    }).done(function(object){
                        if(typeof options.onSuccess == 'function') options.onSuccess(objectName, object);
                    }).fail(function(request, status, error){
                        if(typeof options.onFail == 'function') options.onFail(status + ' ' + error.message);
                    }).always(function(){
                        if(typeof options.always == 'function') options.always();
                    });
                }
            });
        });
    }

    /**
     * Insert object to Google Drive Application Data folder.
     * @param options: name, object, onSuccess(objectName), onFail(errorText)
     * TODO check if the object already exists!
     */
    function insertObject(options){
        //Create metadata
        var metadata = {
            title: options.name + '.json',
            mimeType: "application/json",
            parents: [{id: 'appdata'}]
        };

        //Stringify the data
        var strMetadata = JSON.stringify(metadata);
        var strObject = JSON.stringify(options.object);

        //Create full file. (Combine metadata and data)
        var fullFile = new FormData();
        fullFile.append("metadata", new Blob([ strMetadata ], { type: "application/json" }));
        fullFile.append("file", new Blob([ strObject ], { type: "text/plain" }));

        promisedAjaxCall({
            url: "https://www.googleapis.com/upload/drive/v2/files?uploadType=multipart",
            data: fullFile,
            processData: false, // Don't process the files
            contentType: false, // Set content type to false as jQuery will tell the server its a query string request
            type: 'POST' //POST to insert, PUT to update
        }).done(function(){
            if(typeof options.onSuccess == 'function') options.onSuccess(options.name);
        }).fail(function(request, status, error){
            if(typeof options.onFail == 'function') options.onFail(status + ' ' + error.message);
        });
    }

    /**
     * Delete object from Google Drive Application Data folder.
     * @param options: name, onSuccess(objectName)
     * TODO 1. Object Does not exist!
     *      2. onFail(errorText)
     */
    function deleteObject(options){
        //Get the list of objects
        var request = gapi.client.drive.files.list({
            'q': '\'appdata\' in parents'
        });

        request.execute(function(resp) {
            var objectList = resp.items;
            $.each(objectList, function(index, value){
                var objectName = this.title;
                var objectId = this.id;
                //Find the object that matches the name
                if(objectName === options.name + '.json') {
                    //Call to delete the object
                    var requestDelete = gapi.client.drive.files.delete({
                        'fileId': objectId
                    });
                    requestDelete.execute(function(resp) {
                        if(typeof options.onSuccess == 'function') options.onSuccess(objectName);
                    });
                }
            });
        });
    }

    /**
     * Executes an ajax call with the given options.
     * Automatically creates the Authorization header that contains the
     * gapi accessToken.
     */
    function promisedAjaxCall(options){
        var accessToken = gapi.auth.getToken().access_token;
        var defaultOptions = {
            cache: false,
            //dataType: 'json',
            headers: {'Authorization': 'Bearer ' + accessToken}
        };

        return $.ajax($.extend(defaultOptions, options));
    }

    /**
     * Gets a list of objects stored in the Application Data folder.
     * @param callback function
     * TODO Convert each object in resp.items to be simpler.
     *      Ex: {name: "name", object: {\object stuff here\}}
     */
    function getObjectList(callback){
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
        getObjectList: getObjectList,
        getObject: getObject,
        insertObject: insertObject,
        deleteObject: deleteObject
	};
};
