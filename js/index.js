var index = function(){
    var _transactionDAO, _date;

    /**
     * Initializer for index.js
     */
    function init(){
        NProgress.configure({ showSpinner: false });
        NProgress.inc();
        _transactionDAO = new transactionDAO();
        _transactionDAO.init()
        .done(function () {
            $('#pageContent').show();
            $('#transactionTable').hide();
            NProgress.set(.70);
            loadTableWithTransactions(new Date())
            .done(function () {
                initAddTransactionDialog();
                initTableUtils();
                NProgress.done();
            });
        }).fail(function () {
            //If authorization fail, redirect the user to the login page.
            sessionStorage.setItem('loose-change-redirect-origin', 'index.html');
            window.location.replace("login.html");
        });
    }

    /**
     * Initialize the table utilities
     */
    function initTableUtils() {
        $("#btn-add").bind("click", function () {
            clearErrorForAddTransactionInput();
            $('#add-transaction-dialog').modal('show');
        });
        //Previous month
        $("#btn-prev").bind("click", function () {
            NProgress.set(.70);
            var date = _date;
            date.setMonth(date.getMonth() - 1);
            loadTableWithTransactions(date)
            .done(function () {
                NProgress.done();
            });
        });
        //Next month
        $("#btn-next").bind("click", function () {
            NProgress.set(.70);
            var date = _date;
            date.setMonth(date.getMonth() + 1);
            loadTableWithTransactions(date)
            .done(function () {
                NProgress.done();
            });
        });
    }

    /**
     * Initialize the Add Transaction Modal Dialog
     */
    function initAddTransactionDialog() {
        allowNumericInputOnly("#dialog-input-amount");

        $("#dialog-input-date").datepicker({
            dateFormat: 'D, d M yy'
            // ISO Standard: yy-mm-dd
        });

        $("#add-transaction-button").click(function () {
            //Validate
            var errorFound = validateAddTransactionInput();
            if(!errorFound){
                //Convert date to ISO 8601 Format "yy-mm-dd"
                var date = $.datepicker.formatDate("yy-mm-dd", ($.datepicker.parseDate('D, d M yy', $.trim($('#dialog-input-date').val()))));
                var amount = Number($.trim($('#dialog-input-amount').val()));
                var category = $.trim($('#dialog-input-category').val());
                var comment = $.trim($('#dialog-input-comment').val());
                //Hide Dialog
                $('#add-transaction-dialog').modal('hide');
                //Reset input textboxes
                $('#dialog-input-date').val('');
                $('#dialog-input-amount').val('');
                $('#dialog-input-category').val('');
                $('#dialog-input-comment').val('');
                //Add transaction
                setTimeout(function () {
                    addTransaction({
                        date: date,
                        amount: amount,
                        category: category,
                        comment: comment});
                }, 0);
            }
        });
    }

    /**
     * Validates the input when adding a transaction.
     */
    function validateAddTransactionInput(){
        var errorFound = false;
        clearErrorForAddTransactionInput();
        if($.trim($('#dialog-input-date').val()) == ""){
            $('#dialog-input-date').addClass("error");
            errorFound = true;
        }

        if($.trim($('#dialog-input-amount').val()) == "" || isNaN(Number($('#dialog-input-amount').val()))){
            $('#dialog-input-amount').addClass("error");
            errorFound = true;
        }

        if($.trim($('#dialog-input-category').val()) == ""){
            $('#dialog-input-category').addClass("error");
            errorFound = true;
        }
        return errorFound;
    }

    /**
     * Sets up an input to only accept numeric inputs
     */
    function allowNumericInputOnly(selector) {
        $(selector).on("keyup", function () {
            return false;
        });
        $(selector).on("keydown", function () {
            var previousVal = $(selector).val();
            var inputbox = this;
            var prevCaretPos = inputbox.selectionStart;
            setTimeout(function () {
                var value = $(selector).val();
                if(value != '.' && isNaN(value)){
                    $(selector).val(previousVal);
                    inputbox.selectionStart = prevCaretPos;
                    inputbox.selectionEnd = prevCaretPos;
                }
            },0);
        });
    }

    /**
     * Clears any errors shown in the Add Transaction Dialog
     */
    function clearErrorForAddTransactionInput(){
        $('#dialog-input-date').removeClass("error");
        $('#dialog-input-amount').removeClass("error");
        $('#dialog-input-category').removeClass("error");
    }

    /**
     * Builds the HTML Table out of items.
     * http://stackoverflow.com/questions/5180382/convert-json-data-to-a-html-table
     */
    function setDataTableItems(items) {
        var tableBody = '';
        for (var i = 0 ; i < items.length ; i++) {
            var row = items[i];
            var htmlRow =
            '<tr>' +
                '<td>' + htmlStringEncode(row['date']) + '</td>' +
                '<td style="text-align: right;">' + htmlStringEncode(accounting.formatMoney(row['amount'])) + '</td>' +
                '<td>' + htmlStringEncode(row['category']) + '</td>' +
                '<td>' + htmlStringEncode(row['comment']) + '</td>' +
                '<td>' +
                        '<button type="button" class="btn btn-danger btn-remove">' +
                        '<span class="glyphicon glyphicon-trash" aria-hidden="true"></span>' +
                        '<span class="sr-only">Delete</span>' +
                        '</button>' +
                        '<button type="button" class="btn btn-info btn-edit">' +
                        '<span class="glyphicon glyphicon-pencil" aria-hidden="true"></span>' +
                        '<span class="sr-only">Edit</span>' +
                        '</button>' +
                '</td>' +
            '</tr>';
            tableBody += htmlRow;
        }
        $('#transactionTableBody').html(tableBody);
        setTimeout(function () {
            $('.btn-remove').bind("click", removeTransaction);
        }, 0);
        setupFootable();
    }

    /**
     * Set up footable on the html table.
     * Footable styles the table and makes it reactive.
     */
    function setupFootable(){
        $('#transactionTable').footable().show();
        $('#transactionTable').trigger('footable_resize');
        $('#transactionTable').trigger('footable_redraw');
    }

    /**
     * Load the table with the transactions for the given date.
     * This will load the full month of transactions.
     */
    function loadTableWithTransactions(inDate){
        var deferred = $.Deferred();
        console.debug("Loading table with transactions from " + $.datepicker.formatDate('M yy', inDate) + "...");
        _transactionDAO.getTransactionsForDate({ date:inDate })
        .done(function (transactions) {
            _date = inDate;
            $("#page-selected-date").html($.datepicker.formatDate('M yy', _date));
            setDataTableItems(transactions);
            console.debug("Successfully loaded table with transactions from " + $.datepicker.formatDate('M yy', inDate) + "...");
            deferred.resolve();
        })
        .fail(function (message) {
            console.error(message);
            deferred.reject();
        });
        return deferred.promise();
    }

    /**
     * Get the HTML Table and return it as an array
     */
    function getTransactionListFromTable(){
        var rows = $('#transactionTableBody tr[class!="footable-row-detail"]'); //Get all table rows <tr>
        var items = [];
        for(var i = 0; i < rows.length; i++){
            var dateText = $(rows[i]).children("td:nth-child(1)").text();
            var amountText = $(rows[i]).children("td:nth-child(2)").text();
            var categoryText = $(rows[i]).children("td:nth-child(3)").text();
            var commentText = $(rows[i]).children("td:nth-child(4)").text();

            items.push({
                date: htmlStringDecode(dateText),
                amount: Number(accounting.unformat(htmlStringDecode(amountText))),
                category: htmlStringDecode(categoryText),
                comment: htmlStringDecode(commentText)
            });
        }
        return items;
    }

    /**
     * Add a transaction
     */
    function addTransaction(transaction) {
        NProgress.set(.30);
        var transactionDate = $.datepicker.parseDate('yy-mm-dd', transaction["date"]);
        _transactionDAO.getTransactionsForDate({ date: transactionDate, forceRefresh: true })
        .done(function (transactions) {
            console.debug("Adding transaction...");
            transactions.push(transaction);
            NProgress.set(.75);
            _transactionDAO.setTransactionsForDate(transactionDate, transactions)
            .done(function () {
                loadTableWithTransactions(transactionDate);
                NProgress.done();
                console.debug("Successfully added transaction.");
            });
        }).fail(function (errMsg) {
            console.error(errMsg);
        });
    }

    /**
     * Remove the transaction
     */
    function removeTransaction() {
        console.debug("Removing transaction...");
        NProgress.inc();
        var par = $(this).parent().parent();
        //If it is expanded, then delete the expanded data as well.
        if(par.next().hasClass('footable-row-detail')){
            par.next().fadeOut(400, function () { par.next().remove(); });
        }
        par.fadeOut(400, function () {
            par.remove();
            NProgress.set(.70);
            //Upload the update table
            setTimeout(function () {
                var transactions = getTransactionListFromTable();
                if(transactions.length === 0){
                    _transactionDAO.deleteTransactionForDate(_date)
                    .done(function () {
                        console.debug("Successfully removed transaction.");
                        NProgress.done();
                    });
                } else {
                    _transactionDAO.setTransactionsForDate(_date, transactions)
                    .done(function () {
                        console.debug("Successfully removed transaction.");
                        NProgress.done();
                    });
                }
            },2);
        });
    }

    /**
     * Encode html safe string
     */
    function htmlStringEncode(string) {
        string = string.replace(/&/g, '&amp;');
        string = string.replace(/</g, '&lt;');
        string = string.replace(/>/g, '&gt;');
        string = string.replace(/"/g, '&quot;');
        string = string.replace(/'/g, "&#39;");
        string = string.replace(/\//g, '&#x2F;');
        return string;
    }

    /**
     * Decode html safe string
     */
    function htmlStringDecode(string){
        string = string.replace(/&amp;/g, '&');
        string = string.replace(/&lt;/g, '<');
        string = string.replace(/&gt;/g, '>');
        string = string.replace(/&quot;/g, '"');
        string = string.replace(/&#39;/g, "'");
        string = string.replace(/&#x2F;/g, '/');
        return string;
    }

    return {
        init: init
    };
};
