#ifndef TRANSACTION_TYPE_H
#define TRANSACTION_TYPE_H

#include <QString>
enum TransactionType
{
    OUT_TRANSACTION = 0,
    IN_TRANSACTION = 1
};

class TransactionTypeHelper
{
public:
    TransactionTypeHelper()
    {

    }

    QString static ToString(TransactionType type)
    {
        if(type == IN_TRANSACTION)
            return "IN";
        else if(type == OUT_TRANSACTION)
            return "OUT";
        else
            return "";
    }

    TransactionType static FromString(QString strType)
    {
        if(strType == "OUT")
            return OUT_TRANSACTION;
        else
            return IN_TRANSACTION;
    }
};








#endif // TRANSACTION_TYPE_H
