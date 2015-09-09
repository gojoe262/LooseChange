var index = function () {
    var jsonCacher;

    function init(){
        jsonCacher = new gJsonCacher();
        jsonCacher.authorize().done(function () {
            $('#buttons').show();
        });

        $('#logText').val('');

        setupButtons();
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

    var categories = {
        categories: [
            {
                name: "Electronics",
                id: "M7QXzfVCXYYxMVm7zETUw5P8u2aXXH"
            },
            {
                name: "Gas/Travel ",
                id: "UUBrzuaIGxstACf2CshoJDUORO2fBq"
            }
        ]
    };

    var transactions = {
        transactions: [
            {
                amount: 18.71,
                categoryId: "9TCH3YOVBcD5RxCJFrLyIZxuhJDHY9",
                comment: "McDons",
                date: "20150109",
                id: "6VDHBs6wyKhmp61JKsX0tmgj9klifr",
                transactionType: "IN"
            },
            {
                amount: 40.22,
                categoryId: "9TCH3YOVBcD5RxCJFrLyIZxuhJDHY9",
                comment: "McDons",
                date: "20150109",
                id: "6VDHBs6wyKhmp61JKsX0tmgj9klifr",
                transactionType: "IN"
            }
        ]
    };

    return {
        init: init
    };
};
