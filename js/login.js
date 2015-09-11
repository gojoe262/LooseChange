var login = function(){
    function init() {
        setupButtons();
        setTimeout(function () {
            $('#pageContent').fadeIn('slow');
        },100);
    }

    function setupButtons() {
        $('#btn-google').click(function(){
            setTimeout(function(){
                var authorizer = new gAuthorizer();
                authorizer.authorize({immediate: false})
                    .done(function () {
                        var locactionToReturnTo = sessionStorage.getItem('loose-change-redirect-origin');
                        if(locactionToReturnTo){
                            window.location.href = locactionToReturnTo;
                        }
                        else{
                            window.location.replace('index.html');
                        }
                    });
            },10);
        });
    }

    return {
        init: init
    };
};
