var index = function () {
    var jsonCacher, authorizer, gapiDialog;

    function init(){
        setupButtons();
        $('#logText').val('');

        authorizer = new gAuthorizer();

        authorize();
    }

    function authorize(){
        authorizer.authorize({
            immediate: true
        }).done(function () {
            //If authorized, load jsonCacher and show the page
            jsonCacher = new gJsonCacher();
            jsonCacher.init();
            $('#pageContent').show();
        }).fail(function () {
            //If authorization failed, redirect the user to the login page.
            sessionStorage.setItem('loose-change-redirect-origin', 'index.html');
            window.location.replace("login.html");
        });
    }

    function setupButtons() {
        //List objects
        $('#btnListObjects').click(function(){
            jsonCacher.getObjectList()
            .done(function (objectList) {
                var message = '';
                if(objectList.length !== 0){
                    $.each(objectList, function(index, value){
                        var object = value;
                        message = message.concat(index + '. ' + object.title + (index === objectList.length - 1 ? '' : '\n'));
                    });
                } else {
                    message = message.concat('Nothing found');
                }
                logMessage(message);
            });
        });

        //Insert Objects
        $('#btnUploadObjectCategories').click(function(){
            jsonCacher.insertObject('Categories', categories)
            .done(function(objName){
                logMessage('Succesfully inserted ' + objName + ' object');
            })
            .fail(function (errText) {
                logMessage(errText);
            });
        });

        $('#btnUploadObjectTransactions').click(function(){
            jsonCacher.insertObject('Transactions', transactions)
            .done(function(objName){
                logMessage('Succesfully inserted ' + objName + ' object');
            })
            .fail(function (errText) {
                logMessage(errText);
            });
        });

        //Get Objects
        $('#btnGetObject').click(function(){
            var objectNameInput = $('#txtbxGetObject').val();
            jsonCacher.getObject(objectNameInput)
            .done(function(objectName, object){
                logMessage('Successfully downloaded object ' + objectName + '\n '
                    + JSON.stringify(object));
            }).fail(function(errText){
                logMessage(errText);
            });
        });

        //Delete Objects
        $('#btnDeleteObject').click(function(){
            jsonCacher.deleteObject($('#txtbxDeleteObject').val())
            .done(function(objName){
                logMessage('Successfully delete object ' + objName);
            })
            .fail(function(errText){
                logMessage(errText);
            });
        });
    }

    function logMessage(message){
        $('#logText').val(message  + '\n\n' + $('#logText').val());
        $('#logText').scrollTop(0);
    }

    var categories =
        [
            {
                name: "Electronics",
                id: "M7QXzfVCXYYxMVm7zETUw5P8u2aXXH"
            },
            {
                name: "Gas/Travel ",
                id: "UUBrzuaIGxstACf2CshoJDUORO2fBq"
            }
        ];

    var transactions =
        [
            {
                amount: 18.71,
                category: "Electronics",
                comment: "McDons",
                date: "20150109",
                id: "6VDHBs6wyKhmp61JKsX0tmgj9klifr",
                transactionType: "IN"
            },
            {
                amount: 40.22,
                category: "Gas/Travel",
                comment: "McDons",
                date: "20150109",
                id: "6VDHBs6wyKhmp61JKsX0tmgj9klifr",
                transactionType: "IN"
            },
            {
                amount: 18.71,
                category: "Electronics",
                comment: "McDons",
                date: "20150109",
                id: "6VDHBs6wyKhmp61JKsX0tmgj9klifr",
                transactionType: "IN"
            },
            {
                amount: 18.71,
                category: "Electronics",
                comment: "McDons",
                date: "20150109",
                id: "6VDHBs6wyKhmp61JKsX0tmgj9klifr",
                transactionType: "IN"
            },
            {
                amount: 18.71,
                category: "Electronics",
                comment: "McDons",
                date: "20150109",
                id: "6VDHBs6wyKhmp61JKsX0tmgj9klifr",
                transactionType: "IN"
            },
            {
                amount: 18.71,
                category: "Electronics",
                comment: "McDons",
                date: "20150109",
                id: "6VDHBs6wyKhmp61JKsX0tmgj9klifr",
                transactionType: "IN"
            },
            {
                amount: 18.71,
                category: "Electronics",
                comment: "McDons",
                date: "20150109",
                id: "6VDHBs6wyKhmp61JKsX0tmgj9klifr",
                transactionType: "IN"
            },
            {
                amount: 18.71,
                category: "Electronics",
                comment: "McDons",
                date: "20150109",
                id: "6VDHBs6wyKhmp61JKsX0tmgj9klifr",
                transactionType: "IN"
            },
            {
                amount: 18.71,
                category: "Electronics",
                comment: "McDons",
                date: "20150109",
                id: "6VDHBs6wyKhmp61JKsX0tmgj9klifr",
                transactionType: "IN"
            },
            {
                amount: 18.71,
                category: "Electronics",
                comment: "McDons",
                date: "20150109",
                id: "6VDHBs6wyKhmp61JKsX0tmgj9klifr",
                transactionType: "IN"
            },
            {
                amount: 18.71,
                category: "Electronics",
                comment: "McDons",
                date: "20150109",
                id: "6VDHBs6wyKhmp61JKsX0tmgj9klifr",
                transactionType: "IN"
            },
            {
                amount: 18.71,
                category: "Electronics",
                comment: "McDons",
                date: "20150109",
                id: "6VDHBs6wyKhmp61JKsX0tmgj9klifr",
                transactionType: "IN"
            },
            {
                amount: 18.71,
                category: "Electronics",
                comment: "McDons",
                date: "20150109",
                id: "6VDHBs6wyKhmp61JKsX0tmgj9klifr",
                transactionType: "IN"
            },
            {
                amount: 18.71,
                category: "Electronics",
                comment: "McDons",
                date: "20150109",
                id: "6VDHBs6wyKhmp61JKsX0tmgj9klifr",
                transactionType: "IN"
            },
            {
                amount: 18.71,
                category: "Electronics",
                comment: "McDons",
                date: "20150109",
                id: "6VDHBs6wyKhmp61JKsX0tmgj9klifr",
                transactionType: "IN"
            },
            {
                amount: 18.71,
                category: "Electronics",
                comment: "McDons",
                date: "20150109",
                id: "6VDHBs6wyKhmp61JKsX0tmgj9klifr",
                transactionType: "IN"
            },
            {
                amount: 18.71,
                category: "Electronics",
                comment: "McDons",
                date: "20150109",
                id: "6VDHBs6wyKhmp61JKsX0tmgj9klifr",
                transactionType: "IN"
            },{
                amount: 18.71,
                category: "Electronics",
                comment: "McDons",
                date: "20150109",
                id: "6VDHBs6wyKhmp61JKsX0tmgj9klifr",
                transactionType: "IN"
            },{
                amount: 18.71,
                category: "Electronics",
                comment: "McDons",
                date: "20150109",
                id: "6VDHBs6wyKhmp61JKsX0tmgj9klifr",
                transactionType: "IN"
            },{
                amount: 18.71,
                category: "Electronics",
                comment: "McDons",
                date: "20150109",
                id: "6VDHBs6wyKhmp61JKsX0tmgj9klifr",
                transactionType: "IN"
            },{
                amount: 18.71,
                category: "Electronics",
                comment: "McDons",
                date: "20150109",
                id: "6VDHBs6wyKhmp61JKsX0tmgj9klifr",
                transactionType: "IN"
            },{
                amount: 18.71,
                category: "Electronics",
                comment: "McDons",
                date: "20150109",
                id: "6VDHBs6wyKhmp61JKsX0tmgj9klifr",
                transactionType: "IN"
            },{
                amount: 18.71,
                category: "Electronics",
                comment: "McDons",
                date: "20150109",
                id: "6VDHBs6wyKhmp61JKsX0tmgj9klifr",
                transactionType: "IN"
            },{
                amount: 18.71,
                category: "Electronics",
                comment: "McDons",
                date: "20150109",
                id: "6VDHBs6wyKhmp61JKsX0tmgj9klifr",
                transactionType: "IN"
            },{
                amount: 18.71,
                category: "Electronics",
                comment: "McDons",
                date: "20150109",
                id: "6VDHBs6wyKhmp61JKsX0tmgj9klifr",
                transactionType: "IN"
            },{
                amount: 18.71,
                category: "Electronics",
                comment: "McDons",
                date: "20150109",
                id: "6VDHBs6wyKhmp61JKsX0tmgj9klifr",
                transactionType: "IN"
            },{
                amount: 18.71,
                category: "Electronics",
                comment: "McDons",
                date: "20150109",
                id: "6VDHBs6wyKhmp61JKsX0tmgj9klifr",
                transactionType: "IN"
            },{
                amount: 18.71,
                category: "Electronics",
                comment: "McDons",
                date: "20150109",
                id: "6VDHBs6wyKhmp61JKsX0tmgj9klifr",
                transactionType: "IN"
            },{
                amount: 18.71,
                category: "Electronics",
                comment: "McDons",
                date: "20150109",
                id: "6VDHBs6wyKhmp61JKsX0tmgj9klifr",
                transactionType: "IN"
            },{
                amount: 18.71,
                category: "Electronics",
                comment: "McDons",
                date: "20150109",
                id: "6VDHBs6wyKhmp61JKsX0tmgj9klifr",
                transactionType: "IN"
            },{
                amount: 18.71,
                category: "Electronics",
                comment: "McDons",
                date: "20150109",
                id: "6VDHBs6wyKhmp61JKsX0tmgj9klifr",
                transactionType: "IN"
            },{
                amount: 18.71,
                category: "Electronics",
                comment: "McDons",
                date: "20150109",
                id: "6VDHBs6wyKhmp61JKsX0tmgj9klifr",
                transactionType: "IN"
            },{
                amount: 18.71,
                category: "Electronics",
                comment: "McDons",
                date: "20150109",
                id: "6VDHBs6wyKhmp61JKsX0tmgj9klifr",
                transactionType: "IN"
            },{
                amount: 18.71,
                category: "Electronics",
                comment: "McDons",
                date: "20150109",
                id: "6VDHBs6wyKhmp61JKsX0tmgj9klifr",
                transactionType: "IN"
            },{
                amount: 18.71,
                category: "Electronics",
                comment: "McDons",
                date: "20150109",
                id: "6VDHBs6wyKhmp61JKsX0tmgj9klifr",
                transactionType: "IN"
            },{
                amount: 18.71,
                category: "Electronics",
                comment: "McDons",
                date: "20150109",
                id: "6VDHBs6wyKhmp61JKsX0tmgj9klifr",
                transactionType: "IN"
            },{
                amount: 18.71,
                category: "Electronics",
                comment: "McDons",
                date: "20150109",
                id: "6VDHBs6wyKhmp61JKsX0tmgj9klifr",
                transactionType: "IN"
            },{
                amount: 18.71,
                category: "Electronics",
                comment: "McDons",
                date: "20150109",
                id: "6VDHBs6wyKhmp61JKsX0tmgj9klifr",
                transactionType: "IN"
            },{
                amount: 18.71,
                category: "Electronics",
                comment: "McDons",
                date: "20150109",
                id: "6VDHBs6wyKhmp61JKsX0tmgj9klifr",
                transactionType: "IN"
            },{
                amount: 18.71,
                category: "Electronics",
                comment: "McDons",
                date: "20150109",
                id: "6VDHBs6wyKhmp61JKsX0tmgj9klifr",
                transactionType: "IN"
            },{
                amount: 18.71,
                category: "Electronics",
                comment: "McDons",
                date: "20150109",
                id: "6VDHBs6wyKhmp61JKsX0tmgj9klifr",
                transactionType: "IN"
            },{
                amount: 18.71,
                category: "Electronics",
                comment: "McDons",
                date: "20150109",
                id: "6VDHBs6wyKhmp61JKsX0tmgj9klifr",
                transactionType: "IN"
            },{
                amount: 18.71,
                category: "Electronics",
                comment: "McDons",
                date: "20150109",
                id: "6VDHBs6wyKhmp61JKsX0tmgj9klifr",
                transactionType: "IN"
            },{
                amount: 18.71,
                category: "Electronics",
                comment: "McDons",
                date: "20150109",
                id: "6VDHBs6wyKhmp61JKsX0tmgj9klifr",
                transactionType: "IN"
            },{
                amount: 18.71,
                category: "Electronics",
                comment: "McDons",
                date: "20150109",
                id: "6VDHBs6wyKhmp61JKsX0tmgj9klifr",
                transactionType: "IN"
            },{
                amount: 18.71,
                category: "Electronics",
                comment: "McDons",
                date: "20150109",
                id: "6VDHBs6wyKhmp61JKsX0tmgj9klifr",
                transactionType: "IN"
            },{
                amount: 18.71,
                category: "Electronics",
                comment: "McDons",
                date: "20150109",
                id: "6VDHBs6wyKhmp61JKsX0tmgj9klifr",
                transactionType: "IN"
            },{
                amount: 18.71,
                category: "Electronics",
                comment: "McDons",
                date: "20150109",
                id: "6VDHBs6wyKhmp61JKsX0tmgj9klifr",
                transactionType: "IN"
            },{
                amount: 18.71,
                category: "Electronics",
                comment: "McDons",
                date: "20150109",
                id: "6VDHBs6wyKhmp61JKsX0tmgj9klifr",
                transactionType: "IN"
            },{
                amount: 18.71,
                category: "Electronics",
                comment: "McDons",
                date: "20150109",
                id: "6VDHBs6wyKhmp61JKsX0tmgj9klifr",
                transactionType: "IN"
            },{
                amount: 18.71,
                category: "Electronics",
                comment: "McDons",
                date: "20150109",
                id: "6VDHBs6wyKhmp61JKsX0tmgj9klifr",
                transactionType: "IN"
            },{
                amount: 18.71,
                category: "Electronics",
                comment: "McDons",
                date: "20150109",
                id: "6VDHBs6wyKhmp61JKsX0tmgj9klifr",
                transactionType: "IN"
            },{
                amount: 18.71,
                category: "Electronics",
                comment: "McDons",
                date: "20150109",
                id: "6VDHBs6wyKhmp61JKsX0tmgj9klifr",
                transactionType: "IN"
            },{
                amount: 18.71,
                category: "Electronics",
                comment: "McDons",
                date: "20150109",
                id: "6VDHBs6wyKhmp61JKsX0tmgj9klifr",
                transactionType: "IN"
            },{
                amount: 18.71,
                category: "Electronics",
                comment: "McDons",
                date: "20150109",
                id: "6VDHBs6wyKhmp61JKsX0tmgj9klifr",
                transactionType: "IN"
            },{
                amount: 18.71,
                category: "Electronics",
                comment: "McDons",
                date: "20150109",
                id: "6VDHBs6wyKhmp61JKsX0tmgj9klifr",
                transactionType: "IN"
            },{
                amount: 18.71,
                category: "Electronics",
                comment: "McDons",
                date: "20150109",
                id: "6VDHBs6wyKhmp61JKsX0tmgj9klifr",
                transactionType: "IN"
            },{
                amount: 18.71,
                category: "Electronics",
                comment: "McDons",
                date: "20150109",
                id: "6VDHBs6wyKhmp61JKsX0tmgj9klifr",
                transactionType: "IN"
            },{
                amount: 18.71,
                category: "Electronics",
                comment: "McDons",
                date: "20150109",
                id: "6VDHBs6wyKhmp61JKsX0tmgj9klifr",
                transactionType: "IN"
            },{
                amount: 18.71,
                category: "Electronics",
                comment: "McDons",
                date: "20150109",
                id: "6VDHBs6wyKhmp61JKsX0tmgj9klifr",
                transactionType: "IN"
            },{
                amount: 18.71,
                category: "Electronics",
                comment: "McDons",
                date: "20150109",
                id: "6VDHBs6wyKhmp61JKsX0tmgj9klifr",
                transactionType: "IN"
            },{
                amount: 18.71,
                category: "Electronics",
                comment: "McDons",
                date: "20150109",
                id: "6VDHBs6wyKhmp61JKsX0tmgj9klifr",
                transactionType: "IN"
            },{
                amount: 18.71,
                category: "Electronics",
                comment: "McDons",
                date: "20150109",
                id: "6VDHBs6wyKhmp61JKsX0tmgj9klifr",
                transactionType: "IN"
            },{
                amount: 18.71,
                category: "Electronics",
                comment: "McDons",
                date: "20150109",
                id: "6VDHBs6wyKhmp61JKsX0tmgj9klifr",
                transactionType: "IN"
            },{
                amount: 18.71,
                category: "Electronics",
                comment: "McDons",
                date: "20150109",
                id: "6VDHBs6wyKhmp61JKsX0tmgj9klifr",
                transactionType: "IN"
            },{
                amount: 18.71,
                category: "Electronics",
                comment: "McDons",
                date: "20150109",
                id: "6VDHBs6wyKhmp61JKsX0tmgj9klifr",
                transactionType: "IN"
            },{
                amount: 18.71,
                category: "Electronics",
                comment: "McDons",
                date: "20150109",
                id: "6VDHBs6wyKhmp61JKsX0tmgj9klifr",
                transactionType: "IN"
            },{
                amount: 18.71,
                category: "Electronics",
                comment: "McDons",
                date: "20150109",
                id: "6VDHBs6wyKhmp61JKsX0tmgj9klifr",
                transactionType: "IN"
            },{
                amount: 18.71,
                category: "Electronics",
                comment: "McDons",
                date: "20150109",
                id: "6VDHBs6wyKhmp61JKsX0tmgj9klifr",
                transactionType: "IN"
            },{
                amount: 18.71,
                category: "Electronics",
                comment: "McDons",
                date: "20150109",
                id: "6VDHBs6wyKhmp61JKsX0tmgj9klifr",
                transactionType: "IN"
            },{
                amount: 18.71,
                category: "Electronics",
                comment: "McDons",
                date: "20150109",
                id: "6VDHBs6wyKhmp61JKsX0tmgj9klifr",
                transactionType: "IN"
            },{
                amount: 18.71,
                category: "Electronics",
                comment: "McDons",
                date: "20150109",
                id: "6VDHBs6wyKhmp61JKsX0tmgj9klifr",
                transactionType: "IN"
            },{
                amount: 18.71,
                category: "Electronics",
                comment: "McDons",
                date: "20150109",
                id: "6VDHBs6wyKhmp61JKsX0tmgj9klifr",
                transactionType: "IN"
            },{
                amount: 18.71,
                category: "Electronics",
                comment: "McDons",
                date: "20150109",
                id: "6VDHBs6wyKhmp61JKsX0tmgj9klifr",
                transactionType: "IN"
            },{
                amount: 18.71,
                category: "Electronics",
                comment: "McDons",
                date: "20150109",
                id: "6VDHBs6wyKhmp61JKsX0tmgj9klifr",
                transactionType: "IN"
            },{
                amount: 18.71,
                category: "Electronics",
                comment: "McDons",
                date: "20150109",
                id: "6VDHBs6wyKhmp61JKsX0tmgj9klifr",
                transactionType: "IN"
            },{
                amount: 18.71,
                category: "Electronics",
                comment: "McDons",
                date: "20150109",
                id: "6VDHBs6wyKhmp61JKsX0tmgj9klifr",
                transactionType: "IN"
            },{
                amount: 18.71,
                category: "Electronics",
                comment: "McDons",
                date: "20150109",
                id: "6VDHBs6wyKhmp61JKsX0tmgj9klifr",
                transactionType: "IN"
            },{
                amount: 18.71,
                category: "Electronics",
                comment: "McDons",
                date: "20150109",
                id: "6VDHBs6wyKhmp61JKsX0tmgj9klifr",
                transactionType: "IN"
            },{
                amount: 18.71,
                category: "Electronics",
                comment: "McDons",
                date: "20150109",
                id: "6VDHBs6wyKhmp61JKsX0tmgj9klifr",
                transactionType: "IN"
            },{
                amount: 18.71,
                category: "Electronics",
                comment: "McDons",
                date: "20150109",
                id: "6VDHBs6wyKhmp61JKsX0tmgj9klifr",
                transactionType: "IN"
            },{
                amount: 18.71,
                category: "Electronics",
                comment: "McDons",
                date: "20150109",
                id: "6VDHBs6wyKhmp61JKsX0tmgj9klifr",
                transactionType: "IN"
            },{
                amount: 18.71,
                category: "Electronics",
                comment: "McDons",
                date: "20150109",
                id: "6VDHBs6wyKhmp61JKsX0tmgj9klifr",
                transactionType: "IN"
            },{
                amount: 18.71,
                category: "Electronics",
                comment: "McDons",
                date: "20150109",
                id: "6VDHBs6wyKhmp61JKsX0tmgj9klifr",
                transactionType: "IN"
            },{
                amount: 18.71,
                category: "Electronics",
                comment: "McDons",
                date: "20150109",
                id: "6VDHBs6wyKhmp61JKsX0tmgj9klifr",
                transactionType: "IN"
            },{
                amount: 18.71,
                category: "Electronics",
                comment: "McDons",
                date: "20150109",
                id: "6VDHBs6wyKhmp61JKsX0tmgj9klifr",
                transactionType: "IN"
            },{
                amount: 18.71,
                category: "Electronics",
                comment: "McDons",
                date: "20150109",
                id: "6VDHBs6wyKhmp61JKsX0tmgj9klifr",
                transactionType: "IN"
            },{
                amount: 18.71,
                category: "Electronics",
                comment: "McDons",
                date: "20150109",
                id: "6VDHBs6wyKhmp61JKsX0tmgj9klifr",
                transactionType: "IN"
            },{
                amount: 18.71,
                category: "Electronics",
                comment: "McDons",
                date: "20150109",
                id: "6VDHBs6wyKhmp61JKsX0tmgj9klifr",
                transactionType: "IN"
            },{
                amount: 18.71,
                category: "Electronics",
                comment: "McDons",
                date: "20150109",
                id: "6VDHBs6wyKhmp61JKsX0tmgj9klifr",
                transactionType: "IN"
            },{
                amount: 18.71,
                category: "Electronics",
                comment: "McDons",
                date: "20150109",
                id: "6VDHBs6wyKhmp61JKsX0tmgj9klifr",
                transactionType: "IN"
            },{
                amount: 18.71,
                category: "Electronics",
                comment: "McDons",
                date: "20150109",
                id: "6VDHBs6wyKhmp61JKsX0tmgj9klifr",
                transactionType: "IN"
            },{
                amount: 18.71,
                category: "Electronics",
                comment: "McDons",
                date: "20150109",
                id: "6VDHBs6wyKhmp61JKsX0tmgj9klifr",
                transactionType: "IN"
            },{
                amount: 18.71,
                category: "Electronics",
                comment: "McDons",
                date: "20150109",
                id: "6VDHBs6wyKhmp61JKsX0tmgj9klifr",
                transactionType: "IN"
            },{
                amount: 18.71,
                category: "Electronics",
                comment: "McDons",
                date: "20150109",
                id: "6VDHBs6wyKhmp61JKsX0tmgj9klifr",
                transactionType: "IN"
            },{
                amount: 18.71,
                category: "Electronics",
                comment: "McDons",
                date: "20150109",
                id: "6VDHBs6wyKhmp61JKsX0tmgj9klifr",
                transactionType: "IN"
            },{
                amount: 18.71,
                category: "Electronics",
                comment: "McDons",
                date: "20150109",
                id: "6VDHBs6wyKhmp61JKsX0tmgj9klifr",
                transactionType: "IN"
            },{
                amount: 18.71,
                category: "Electronics",
                comment: "McDons",
                date: "20150109",
                id: "6VDHBs6wyKhmp61JKsX0tmgj9klifr",
                transactionType: "IN"
            },{
                amount: 18.71,
                category: "Electronics",
                comment: "McDons",
                date: "20150109",
                id: "6VDHBs6wyKhmp61JKsX0tmgj9klifr",
                transactionType: "IN"
            },{
                amount: 18.71,
                category: "Electronics",
                comment: "McDons",
                date: "20150109",
                id: "6VDHBs6wyKhmp61JKsX0tmgj9klifr",
                transactionType: "IN"
            },{
                amount: 18.71,
                category: "Electronics",
                comment: "McDons",
                date: "20150109",
                id: "6VDHBs6wyKhmp61JKsX0tmgj9klifr",
                transactionType: "IN"
            },{
                amount: 18.71,
                category: "Electronics",
                comment: "McDons",
                date: "20150109",
                id: "6VDHBs6wyKhmp61JKsX0tmgj9klifr",
                transactionType: "IN"
            },{
                amount: 18.71,
                category: "Electronics",
                comment: "McDons",
                date: "20150109",
                id: "6VDHBs6wyKhmp61JKsX0tmgj9klifr",
                transactionType: "IN"
            },{
                amount: 18.71,
                category: "Electronics",
                comment: "McDons",
                date: "20150109",
                id: "6VDHBs6wyKhmp61JKsX0tmgj9klifr",
                transactionType: "IN"
            },{
                amount: 18.71,
                category: "Electronics",
                comment: "McDons",
                date: "20150109",
                id: "6VDHBs6wyKhmp61JKsX0tmgj9klifr",
                transactionType: "IN"
            },{
                amount: 18.71,
                category: "Electronics",
                comment: "McDons",
                date: "20150109",
                id: "6VDHBs6wyKhmp61JKsX0tmgj9klifr",
                transactionType: "IN"
            },{
                amount: 18.71,
                category: "Electronics",
                comment: "McDons",
                date: "20150109",
                id: "6VDHBs6wyKhmp61JKsX0tmgj9klifr",
                transactionType: "IN"
            },{
                amount: 18.71,
                category: "Electronics",
                comment: "McDons",
                date: "20150109",
                id: "6VDHBs6wyKhmp61JKsX0tmgj9klifr",
                transactionType: "IN"
            },{
                amount: 18.71,
                category: "Electronics",
                comment: "McDons",
                date: "20150109",
                id: "6VDHBs6wyKhmp61JKsX0tmgj9klifr",
                transactionType: "IN"
            },{
                amount: 18.71,
                category: "Electronics",
                comment: "McDons",
                date: "20150109",
                id: "6VDHBs6wyKhmp61JKsX0tmgj9klifr",
                transactionType: "IN"
            },{
                amount: 18.71,
                category: "Electronics",
                comment: "McDons",
                date: "20150109",
                id: "6VDHBs6wyKhmp61JKsX0tmgj9klifr",
                transactionType: "IN"
            },{
                amount: 18.71,
                category: "Electronics",
                comment: "McDons",
                date: "20150109",
                id: "6VDHBs6wyKhmp61JKsX0tmgj9klifr",
                transactionType: "IN"
            },{
                amount: 18.71,
                category: "Electronics",
                comment: "McDons",
                date: "20150109",
                id: "6VDHBs6wyKhmp61JKsX0tmgj9klifr",
                transactionType: "IN"
            },
        ];

    return {
        init: init
    };
};
