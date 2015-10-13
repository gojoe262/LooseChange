var index = function(){
    var jsonCacher, authorizer;

    function init(){

        NProgress.configure({showSpinner: false});
        NProgress.inc();
        // $('#btnSave').click(function () {
        //     $('#btnSave').prop('disabled', true);
        //     var items = getTable();
        //     jsonCacher.uploadObject('TestingGetJson', items).done(function () {
        //         $('#btnSave').prop('disabled', false);
        //     });
        // });
        authorizer = new gAuthorizer();
        authorizer.authorize({immediate: true})
            .done(function () {
                NProgress.set(0.55);
                //If authorization successful, load jsonCacher and show the page
                $('#pageContent').show();
                $('#transactionTable').hide();
                jsonCacher = new gJsonCacher();
                jsonCacher.init()
                    .done(function () {
                        NProgress.set(.85)
                        loadTable().done(function () {
                            NProgress.done();
                            setupFooter();
                        });
                    });
            }).fail(function () {
                //If authorization fail, redirect the user to the login page.
                sessionStorage.setItem('loose-change-redirect-origin', 'index.html');
                window.location.replace("login.html");
            });
        $('#datePickerTest').pickadate();
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
     * Set up the footer panel at the bottom of the page.
     */
    function setupFooter() {
        $("#btn-add").bind("click", function () {
            BootstrapDialog.show({
                size: BootstrapDialog.SIZE_LARGE,
                title: "Add Transaction",
                message: $("#add-transaction-dialog").html().replace(/Template/g, ''),
                buttons: [
                    {
                        label: 'Cancel',
                        action: function(dialogItself){
                            dialogItself.close();
                        }
                    },
                    {
                        label: 'Add',
                        cssClass: 'btn-success',
                        icon: 'glyphicon glyphicon-plus',
                        action: function(dialogItself){
                            //Validate and add the trasnaction
                            var date = $('#dialog-input-date').attr('data-value');
                            var amount = Number($('#dialog-input-amount').val().replace(/,/g, ''));
                            var category = $('#dialog-input-category').val();
                            var comment = $('#dialog-input-comment').val();

                            dialogItself.close();
                            setTimeout(function () {
                                addTransaction({
                                    date: date,
                                    amount: amount,
                                    category: category,
                                    comment: comment});
                            }, 0);
                        }
                    }
                ],
                onshown: function(dialogRef){
                    $('#dialog-input-amount').mask("#,##0.00", {reverse: true, placeholder: "0.00"});
                    //https://github.com/amsul/pickadate.js/issues/481
                    //http://jsfiddle.net/J92K6/
                    var $input = $("#date-picker").pickadate({
                        format: 'ddd, dd mmm yyyy',
                        onClose: function () {
                            //Copy the date to the actual input box that is inside the dialog box.
                            $('#dialog-input-date').val($('#date-picker').val());
                            $('#dialog-input-date').attr('data-value', this.get('select', 'yyyy-mm-dd'));
                        }
                    });
                    var picker = $input.pickadate('picker');
                    $('#dialog-input-date').on('focus', function(event) {
                        event.stopPropagation();
                        picker.open();
                    });
                },
            });
        });
    }

    /**
     * Get the transactions and load them into the table.
     */
    function loadTable() {
        var deferred = $.Deferred();
        jsonCacher.getObject('Transactions')
            .done(function(name, transactions){
                setTable(transactions);
                deferred.resolve();
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
    function setTable(items) {
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
     * Get the HTML Table and return it as an array
     */
    function getTable(){
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
    function addTransaction(transaction){
        var transactionList = getTable();
        transactionList.push(transaction);
        setTimeout(function () {
            NProgress.set(0.1);
            jsonCacher.uploadObject('Transactions', transactionList)
            .progress(function () {
                NProgress.set(0.75);
            }).done(function () {
                NProgress.done();
                setTable(transactionList);
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
                var items = getTable();
                jsonCacher.uploadObject('Transactions', items)
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
