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
            jsonCacher.init();
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

    return {
        init: init
    };
};
