var transactionDAO = function (){
    var _authorizer, _jsonCacher, _date, _transactions;

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

    function getTransactionsForDate(inDate, forceRefresh){
        var deferred = $.Deferred();

        forceRefresh = forceRefresh !== 'undefined' ? forceRefresh : true;

        //If the date is different, then we have to force the refresh.
        if(inDate.getMonth() !== _date.getMonth() ||
             inDate.getYear() !== _date.getYear()){
            forceRefresh = true;
        }

        if(forceRefresh){
            _jsonCacher.getObject(getObjectName(inDate))
            .done(function(name, transactions){
                _transactions = transactions;
                _date = inDate;
                deferred.resolve(transactions);
            }).fail(function(errorType, message){
                //transactions object not found
                if(errorType === "DOES_NOT_EXIST"){
                    _transactions = [];
                    _date = inDate;
                    deferred.resolve([]);
                } else {
                    deferred.reject(message);
                }
            });
        } else {
            deferred.resolve(_transactions);
        }

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
