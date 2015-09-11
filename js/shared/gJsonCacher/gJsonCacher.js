/**
 * gJsonCacher
 * Can get, insert, update, & delete JSON objects (json files).
 * Objects must in such a format so they can be used in JSON.stringify and JSON.parse.
 * Objects are stored in the user's Google Drive - Application Data folder.
 * The Application Data folder is hidden from the user.
 */
var gJsonCacher = function(config){
    var self = this;

	/**
     * Load Google Client/Drive Load
     */
    function init(){
        var deferred = $.Deferred();
        gapi.load('client', {
            'callback': function(){
                gapi.client.load('drive', 'v2', function(){
                    deferred.resolve();
                });
            }
        });
        return deferred.promise();
    }

    /**
     * Get object from Google Drive Application Data folder.
     * @param inObjectName
     * @return promise: done(objectName, object), fail(errorText)
     */
    function getObject(inObjectName) {
        //deferred - allows use for .done(), .fail(), & .always()
        var deferred = $.Deferred();

        getObjectList()
        .done(function(objectList){
            if(objectList.length !== 0)
            {
                $.each(objectList, function(index, value){
                    var objectName = this.title;
                    var objectDownloadUrl = this.downloadUrl;

                    //Find the file that matches the object name
                    if(objectName === inObjectName + ".json") {
                        //Call to download the object
                        promisedAjaxCall({
                            url: objectDownloadUrl,
                            type: 'GET',
                        }).done(function(object){
                            deferred.resolve(inObjectName, object);
                        }).fail(function(request, status, error){
                            deferred.reject(status + ' ' + error.message);
                        });
                        return false;//break out of each loop
                    } else if(index === objectList.length - 1){
                        deferred.reject(inObjectName + ' not found');
                    }
                });
            }
            else {
                deferred.reject(inObjectName + ' not found');
            }
        });

        return deferred.promise();
    }

    /**
     * Insert object to Google Drive Application Data folder.
     * @param inObjectName, inObject
     * @return promise: done(inObjectName), fail(errorText)
     */
    function insertObject(inObjectName, inObject){
        var deferred = $.Deferred();
        //Create metadata
        var metadata = {
            title: inObjectName + '.json',
            mimeType: "application/json",
            parents: [{id: 'appdata'}]
        };

        //Stringify the data
        var strMetadata = JSON.stringify(metadata);
        var strObject = JSON.stringify(inObject);

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
            deferred.resolve(inObjectName);
        }).fail(function(request, status, error){
            deferred.reject(status + ' ' + error.message);
        });

        return deferred.promise();
    }

    /**
     * Delete object from Google Drive Application Data folder.
     * @param inObjectName
     * @return promise: done(inObjectName), fail(errorText)
     */
    function deleteObject(inObjectName){
        var deferred = $.Deferred();

        getObjectList().done(function(objectList){
            if(objectList.length !== 0)
            {
                $.each(objectList, function(index, value){
                    var objectName = this.title;
                    var objectId = this.id;
                    //Find the object that matches the name
                    if(objectName === inObjectName + '.json') {
                        //Call to delete the object
                        var requestDelete = gapi.client.drive.files.delete({
                            'fileId': objectId
                        });
                        requestDelete.execute(function(resp) {
                            deferred.resolve(inObjectName);
                        });
                        return false;//Break out of each loop. This will only delete the first occurence of the object.
                    } else if(index === objectList.length - 1){
                        deferred.reject(inObjectName + ' not found');
                    }
                });
            } else {
                deferred.reject(inObjectName + ' not found');
            }
        });

        return deferred.promise();
    }

    /**
     * Gets a list of objects stored in the Application Data folder.
     * @return promise: done(objList)
     * TODO Convert each object in resp.items to be simpler.
     *      Ex: {name: "name", object: {\object stuff here\}}
     */
    function getObjectList(){
        var deferred = $.Deferred();
        var request = gapi.client.drive.files.list({
            'q': '\'appdata\' in parents'
        });
        request.execute(function(resp) {
            deferred.resolve(resp.items);
        });
        return deferred.promise();
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
            headers: {'Authorization': 'Bearer ' + accessToken}
        };

        return $.ajax($.extend(defaultOptions, options));
    }

    /**
     * Public functions/variables inside return statement
     */
	return {
        init: init,

        getObjectList: getObjectList,
        getObject: getObject,
        insertObject: insertObject,
        deleteObject: deleteObject
	};
};
