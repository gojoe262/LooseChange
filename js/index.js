var index = function(){
    var _jsonCacher, _authorizer, _transactionList, _yearMonth;

    function init(){
        NProgress.configure({showSpinner: false});
        NProgress.inc();
        _authorizer = new gAuthorizer();
        _authorizer.authorize({immediate: true})
        .done(function () {
            NProgress.set(.45);
            //If authorization successful, load jsonCacher and show the page
            console.debug("Authorization successful.");
            $('#pageContent').show();
            $('#transactionTable').hide();
            _jsonCacher = new gJsonCacher();
            _jsonCacher.init().done(function () {
                NProgress.set(.65);
                console.debug("_jsonCacher initialized successfully.");
                //Defaults to today's date
                setPageYearMonth($.datepicker.formatDate("yy-mm", new Date()))
                .done(function () {
                    initAddTransactionDialog();
                    initFooter();
                    NProgress.done();
                });
            });
        }).fail(function () {
            //If authorization fail, redirect the user to the login page.
            sessionStorage.setItem('loose-change-redirect-origin', 'index.html');
            window.location.replace("login.html");
        });
    }

    function transactionObjectName(){
        return 'Transaction_' + _yearMonth;
    }

    function setPageYearMonth(inYearMonth) {
        var deferred = $.Deferred();
        var fatalError = false;
        _yearMonth = inYearMonth;
        var transactionObjName = transactionObjectName();
        _jsonCacher.getObject(transactionObjName)
        .done(function(name, transactions){
            console.debug(transactionObjName + " downloaded. Setting up page...");
            _transactionList = transactions;
        }).fail(function(errorType, message){
            //transactions object not found
            if(errorType === "DOES_NOT_EXIST"){
                console.debug(transactionObjName + " not found. Setting up page for " + _yearMonth + "...");
                _transactionList = [];
            } else {
                console.error(message);
                fatalError = true;
            }
        }).always(function () {
            if(fatalError){
                deferred.reject();
            } else{
                $("#page-year-month").html(_yearMonth);
                refreshTable(_transactionList);
                deferred.resolve();
            }
        });

        return deferred.promise();
    }

    /**
     * Initialize the footer panel at the bottom of the page.
     */
    function initFooter() {
        $("#btn-add").bind("click", function () {
            clearErrorForAddTransactionInput();
            $('#add-transaction-dialog').modal('show');
        });

        $("#btn-prev").bind("click", function () {
            NProgress.set(.30);
            var date = $.datepicker.parseDate("yy-mm-dd", _yearMonth + "-01");
            date.setMonth(date.getMonth() - 1);
            setPageYearMonth($.datepicker.formatDate("yy-mm", date)).done(function () {
                NProgress.done();
            });
        });

        $("#btn-next").bind("click", function () {
            NProgress.set(.30);
            var date = $.datepicker.parseDate("yy-mm-dd", _yearMonth + "-01");
            date.setMonth(date.getMonth() + 1);
            setPageYearMonth($.datepicker.formatDate("yy-mm", date)).done(function () {
                NProgress.done();
            });
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
        var transactionYearMonth = $.datepicker.formatDate("yy-mm", $.datepicker.parseDate('yy-mm-dd', transaction["date"]));

        if(transactionYearMonth === _yearMonth){
            //Transaction yearMonth matches the page's yearMonth. Transaction can be added to this page.
            console.debug("Adding transaction.");
            _transactionList.push(transaction);
            setTimeout(function () {
                NProgress.set(0.1);
                _jsonCacher.uploadObject(transactionObjectName(), _transactionList)
                .progress(function () {
                    NProgress.set(0.75);
                    refreshTable(_transactionList);
                }).done(function (objectName) {
                    console.debug(transactionObjectName() + " saved.");
                    NProgress.done();
                });
            }, 0);
        } else {
            console.debug("Page not set to " + transactionYearMonth +".\nAttempting to switch page to " + transactionYearMonth + "...")
            setPageYearMonth(transactionYearMonth)
            .done(function () {
                //Recursive and try to add it again once the page is set to the correct yearMonth.
                addTransaction(transaction);
            }).fail(function () {
                console.error("Transaction not added.");
            });
        }
    }

    /**
     * Remove the transaction
     */
    function removeTransaction() {
        console.debug("Removing Transaction.");
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
                if(_transactionList.length === 0){
                    _jsonCacher.deleteObject(transactionObjectName())
                    .done(function () {
                        console.debug("No transactions in Transaction_" + transactionObjectName() + ".\nIn order to conserve space, Transaction_" + transactionObjectName() + " object has been deleted");
                    })
                    .fail(function () {
                        console.error("Unable to delete Transaction_" + transactionObjectName());
                    });
                } else {
                    _jsonCacher.uploadObject(transactionObjectName(), _transactionList)
                    .progress(function () {
                        NProgress.set(0.75)
                    }).done(function () {
                        console.debug(transactionObjectName() + " saved.");
                        NProgress.done();
                    })
                }
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
