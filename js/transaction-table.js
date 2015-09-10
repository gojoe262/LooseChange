var transactionTable = function(){
    var jsonCacher;
    function init(){
        setupTable();
        jsonCacher = new gJsonCacher();
        authorize(true);//Skip popup
    }

    function authorize(skipPopup){
        jsonCacher.authorize({
            immediate: skipPopup
        }).done(function(){
            $('#pageContent').show();
        }).fail(function(){
            $('#gapiDialog').dialog({
                modal: true,
                width: 'auto',
                height: 'auto',
                buttons: [
                    {
                        text: "Login with Google",
                        icons: {primary: "ui-icon-triangle-1-e"},
                        click: function(){
                            authorize(false);
                            $(this).dialog('close');
                        }
                    },
                    {
                        text: "Cancel",
                        click: function(){
                            $(this).dialog('close');
                        }
                    }
                ]
            }).dialog('open');
        });
    }

    function onResize() {
        $("#gapiDialog").dialog("option", "position", {my: "center", at: "center", of: window});
    }

    function setupTable(){
        $('#transactionTable').footable();
        setTimeout(function () {
            $('#transactionTable').trigger('footable_resize');
        },10);
    }

    return {
        init: init,
        onResize: onResize
    };
};
