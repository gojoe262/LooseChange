/**
 * gAuthorizer - Simple javascript to authorize a user to a specific
 * Google API Scope.
 *
 * Please note that this does not set up any other APIs. It only authorizes the
 * user.
 */
var gAuthorizer = function (config) {
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
     * @param options: immediate [true/false] Skip authorization popup.
     * @return promise: done()
     */
    function authorize(options){
        //Set up Authorization for Google API
        var deferred = $.Deferred();

        gapi.load('auth', {
            'callback': function(){
                setTimeout(function () {
                    gapi.auth.authorize({
                        'client_id': config.clientId,
                        'scope': config.scope,
                        //Skip Authorization Popup. To Skip = true. To Show = false.
                        'immediate': (typeof options && typeof options.immediate) ? options.immediate : false
                    }, function(authRslt){
                        handleAuthResult(authRslt, deferred);
                    });
                },5);
            }
        });

        return deferred.promise();
    }

    /**
     * Checks if the Google API authroization was successful.
     */
    function handleAuthResult(authResult, deferred) {
        if (authResult && !authResult.error) {
            console.debug("Successfully authorized gAuthorizer.");
            deferred.resolve();
        } else {
            deferred.reject();
        }
    }

    return {
        authorize: authorize
    };
};
