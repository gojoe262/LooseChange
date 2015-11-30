/**
 * Retrive and edit transactions. Transactions can be accessed for a given year and month.
 */
var transactionDAO = function (){
    var _authorizer, _jsonCacher, _date, _transactions;

    /**
     * Initialize transactionDAO
     */
    function init(){
        var deferred = $.Deferred();
        _authorizer = new gAuthorizer();
        _authorizer.authorize({immediate: true})
        .done(function () {
            _jsonCacher = new gJsonCacher();
            _jsonCacher.init().done(function () {
                console.debug("Successfully initialized transactionDAO.")
                deferred.resolve();
            });
        }).fail(function () {
            deferred.reject();
        });
        return deferred.promise();
    }

    /**
     * Get the object name (Ex: "Transaction_2015-11")
     */
    function getObjectName(inDate){
        return 'Transaction_' + $.datepicker.formatDate("yy-mm", inDate);
    }

    /**
     * Get transactions for the given date (year and month).
     */
    function getTransactionsForDate(options){
        var deferred = $.Deferred();

        var refresh = options.forceRefresh !== undefined ? options.forceRefresh : true;

        //If the date is different, then we have to force the refresh.
        if(_date !== undefined){
            if(options.date.getMonth() !== _date.getMonth() ||
               options.date.getYear() !== _date.getYear()){
                 refresh = true;
            }
        }

        if(refresh){
            _jsonCacher.getObject(getObjectName(options.date))
            .done(function(name, transactions){
                _transactions = transactions;
                _date = options.date;
                deferred.resolve(_transactions);
            }).fail(function(errorType, message){
                //transactions object not found
                if(errorType === "DOES_NOT_EXIST"){
                    _transactions = [];
                    _date = options.date;
                    deferred.resolve(_transactions);
                } else {
                    deferred.reject(message);
                }
            });
        } else {
            deferred.resolve(_transactions);
        }
        return deferred.promise();
    }

    /**
     * Set the transactions for a given date (year and month).
     */
    function setTransactionsForDate(inDate, transactions){
        var deferred = $.Deferred();
        _jsonCacher.uploadObject(getObjectName(inDate), transactions)
        .done(function (objectName) {
            _transactions = transactions;
            _date = inDate;
            deferred.resolve();
        });
        return deferred.promise();
    }

    /**
     * Delete all transactions for a given date (year and month).
     */
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
