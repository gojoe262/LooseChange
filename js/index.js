var index = function(){
    var _jsonCacher, _authorizer, _transactionList;

    function init(){
        NProgress.configure({showSpinner: false});
        NProgress.inc();
        _authorizer = new gAuthorizer();
        _authorizer.authorize({immediate: true})
        .done(function () {
            NProgress.set(0.55);
            //If authorization successful, load jsonCacher and show the page
            $('#pageContent').show();
            $('#transactionTable').hide();
            _jsonCacher = new gJsonCacher();
            _jsonCacher.init().done(function () {
                NProgress.set(.85);
                _jsonCacher.getObject('Transactions').done(function(name, transactions){
                    _transactionList = transactions;
                    refreshTable(_transactionList);
                    NProgress.done();
                    initAddTransactionDialog();
                    initFooter();
                }).fail(function(){
                    //transactions object not found
                    console.log("Could not get Transactions");
                });
            });
        }).fail(function () {
            //If authorization fail, redirect the user to the login page.
            sessionStorage.setItem('loose-change-redirect-origin', 'index.html');
            window.location.replace("login.html");
        });
    }

    /**
     * Initialize the footer panel at the bottom of the page.
     */
    function initFooter() {
        $("#btn-add").bind("click", function () {
            clearErrorForAddTransactionInput();
            $('#add-transaction-dialog').modal('show');
        });
    }

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
     * Initialize the Add Transaction Modal Dialog
     */
    function initAddTransactionDialog() {
        allowNumericInputOnly("#dialog-input-amount");
        // $('#dialog-input-amount').on("keyup", function () {
        //     return false;
        // });
        // $('#dialog-input-amount').on("keydown", function () {
        //     var previousVal = $('#dialog-input-amount').val();
        //     setTimeout(function () {
        //         var value = $('#dialog-input-amount').val();
        //         if(value != '.'){
        //             if(isNaN(value)){
        //                 $('#dialog-input-amount').val(previousVal);
        //             }
        //         }
        //     },0);
        // });

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
     * Clears any errors shown in the Add Transaction Dialog
     */
    function clearErrorForAddTransactionInput(){
        $('#dialog-input-date').removeClass("error");
        $('#dialog-input-amount').removeClass("error");
        $('#dialog-input-category').removeClass("error");
    }

    /**
     * Get the transactions and load them into the table.
     */
    function getTransactionsFromStorage() {
        var deferred = $.Deferred();
        _jsonCacher.getObject('Transactions')
            .done(function(name, transactions){
                deferred.resolve(transactions);
            })
            .fail(function(){
                //transactions object not found
                deferred.reject();
            });
        return deferred.promise();
    }

    /**
     * Builds the HTML Table out of items.
     * http://stackoverflow.com/questions/5180382/convert-json-data-to-a-html-table
     */
    function refreshTable(items) {
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
        _transactionList.push(transaction);
        setTimeout(function () {
            NProgress.set(0.1);
            _jsonCacher.uploadObject('Transactions', _transactionList)
            .progress(function () {
                NProgress.set(0.75);
                refreshTable(_transactionList);
            }).done(function () {
                NProgress.done();
            });
        }, 0);
    }

    /**
     * Remove the transaction
     */
    function removeTransaction() {
        var par = $(this).parent().parent();
        //If it is expanded, then delete the expanded data as well.
        if(par.next().hasClass('footable-row-detail')){
            par.next().fadeOut(400, function () { par.next().remove(); });
        }
        par.fadeOut(400, function () {
            par.remove();
            //Upload the update table
            setTimeout(function () {
                NProgress.set(0.1);
                _transactionList = getTransactionListFromTable();
                _jsonCacher.uploadObject('Transactions', _transactionList)
                .progress(function () {
                    NProgress.set(0.75)
                }).done(function () {
                    NProgress.done();
                })
            },2);
        });
    }

    function htmlStringEncode(string) {
        string = string.replace(/&/g, '&amp;');
        string = string.replace(/</g, '&lt;');
        string = string.replace(/>/g, '&gt;');
        string = string.replace(/"/g, '&quot;');
        string = string.replace(/'/g, "&#39;");
        string = string.replace(/\//g, '&#x2F;');
        return string;
    }

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
