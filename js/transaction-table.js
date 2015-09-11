var transactionTable = function(){
    var jsonCacher, authorizer;
    function init(){
        setupTable();
        authorizer = new gAuthorizer();

        authorize();
    }

    function authorize(){
        authorizer.authorize({
            immediate: true
        }).done(function(){
            //If authorization successful, load jsonCacher and show the page
            jsonCacher = new gJsonCacher();
            jsonCacher.init().done(function () {
                loadTable();
            });
            $('#pageContent').show();

        }).fail(function(){
            //If authorization fail, redirect the user to the login page.
            sessionStorage.setItem('loose-change-redirect-origin', 'transaction-table.html');
            window.location.replace("login.html");
        });
    }

    function setupTable(){
        $('#transactionTable').footable();
        setTimeout(function () {
            $('#transactionTable').trigger('footable_resize');
        },10);
    }

    function loadTable() {
        jsonCacher.getObject('Transactions')
            .done(function(name, transactions){
                buildHtmlTable(transactions);
                setupTable();
            })
            .fail(function(){
                //transactions object not found
            });
    }


    // Builds the HTML Table out of myList.
    // http://stackoverflow.com/questions/5180382/convert-json-data-to-a-html-table
    function buildHtmlTable(items) {
        var tableBody = '';

        for (var i = 0 ; i < items.length ; i++) {
            var row = items[i];
            var htmlRow =
            '<tr>' +
                '<td>' + row['date'] + '</td>' +
                '<td>' + row['transactionType'] + '</td>' +
                '<td>' + row['amount'] + '</td>' +
                '<td>' + row['category'] + '</td>' +
                '<td>' + row['comment'] + '</td>' +
                '<td>' + "edit/remove" + '</td>' +
                '<td>' + row['id'] + '</td>' +
            '</tr>';
            tableBody += htmlRow;
        }
        $('#transactionTableBody').html(tableBody);
    }

    return {
        init: init
    };
};
