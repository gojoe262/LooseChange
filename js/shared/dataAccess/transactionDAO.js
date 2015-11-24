var transactionDAO = function (){
    var _authorizer, _jsonCacher;

    function init(){
        var deferred = $.Deferred();
        _authorizer = new gAuthorizer();
        _authorizer.authorize({immediate: true})
        .done(function () {
            console.debug("Authorization successful.");
            _jsonCacher = new gJsonCacher();
            _jsonCacher.init().done(function () {
                console.debug("_jsonCacher initialized successfully.");
                deferred.resolve();
            });
        }).fail(function () {
            deferred.reject();
        });
        return deferred.promise();
    }

    function getObjectName(inDate){
        return 'Transaction_' + $.datepicker.formatDate("yy-mm", inDate);
    }

    function getTransactionsForDate(inDate){
        var deferred = $.Deferred();

        _jsonCacher.getObject(getObjectName(inDate))
        .done(function(name, transactions){
            deferred.resolve(transactions);
        }).fail(function(errorType, message){
            //transactions object not found
            if(errorType === "DOES_NOT_EXIST"){
                deferred.resolve([]);
            } else {
                deferred.reject(message);
            }
        });

        return deferred.promise();
    }

    function setTransactionsForDate(inDate, transactions){
        var deferred = $.Deferred();
        _jsonCacher.uploadObject(getObjectName(inDate), transactions)
        .done(function (objectName) {
            deferred.resolve();
        });

        return deferred.promise();
    }

    function deleteTransactionForDate(inDate) {
        var deferred = $.Deferred();
        _jsonCacher.deleteObject(getObjectName(inDate))
        .done(function () {
            deferred.resolve();
        })
        .fail(function (errType, errMsg) {
            deferred.reject(errMsg);
        });

        return deferred.promise();
    }

    return {
        init: init,
        getTransactionsForDate: getTransactionsForDate,
        setTransactionsForDate: setTransactionsForDate,
        deleteTransactionForDate: deleteTransactionForDate
    }
}
