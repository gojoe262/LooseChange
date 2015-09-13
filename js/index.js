var index = function(){
    var jsonCacher, authorizer;

    function init(){
        authorizer = new gAuthorizer();
        authorizer.authorize({immediate: true})
            .done(function () {
                //If authorization successful, load jsonCacher and show the page
                $('#pageContent').show();
                $('#transactionTable').hide();
                jsonCacher = new gJsonCacher();
                jsonCacher.init()
                    .done(function () {
                        loadTable();
                    });

            }).fail(function () {
                //If authorization fail, redirect the user to the login page.
                sessionStorage.setItem('loose-change-redirect-origin', 'transaction-table.html');
                window.location.replace("login.html");
            });
    }

    /**
     * Set up footable on the html table.
     * Footable styles the table and makes it reactive.
     */
    function setupFootable(){
        $('#transactionTable').footable().show().trigger('footable_resize');
    }

    /**
     * Get the transactions and load them into the table.
     */
    function loadTable() {
        jsonCacher.getObject('Transactions')
            .done(function(name, transactions){
                setTable(transactions);
            })
            .fail(function(){
                //transactions object not found
            });
    }

    /**
     * Builds the HTML Table out of myList.
     * http://stackoverflow.com/questions/5180382/convert-json-data-to-a-html-table
     */
    function setTable(items) {
        var tableBody = '';

        for (var i = 0 ; i < items.length ; i++) {
            var row = items[i];
            var htmlRow =
            '<tr>' +
                '<td>' + row['date'] + '</td>' +
                '<td>' + row['amount'] + '</td>' +
                '<td>' + row['category'] + '</td>' +
                '<td>' + row['comment'] + '</td>' +
                '<td>' + "edit/remove" + '</td>' +
            '</tr>';
            tableBody += htmlRow;
        }
        $('#transactionTableBody').html(tableBody);
        setupFootable();
    }

    /**
     * Get the HTML Table and parse it into JSON
     * TODO This does the opposite of the setTable
     */
    function getTable(){

    }

//HTML ENCODERS START
    /**
     * http://stackoverflow.com/questions/24816/escaping-html-strings-with-jquery
     */
    var entityMap = {
        "&": "&amp;",
        "<": "&lt;",
        ">": "&gt;",
        '"': '&quot;',
        "'": '&#39;',
        "/": '&#x2F;'
    };
    function escapeHtml(string) {
        return String(string).replace(/[&<>"'\/]/g, function (s) {
            return entityMap[s];
        });
    }

    /**
     * http://bytes.com/topic/javascript/answers/469812-encoding-string-html-safe-characters
     */
    function htmlEncode(s)
    {
        return s.replace(/&(?!\w+([;\s]|$))/g, "&amp;")
                .replace(/</g, "&lt;").replace(/>/g, "&gt;");
    }
//HTML ENCODERS END

    return {
        init: init
    };
};
