#ifndef TRANSACTION_TYPE_H
#define TRANSACTION_TYPE_H

#include <QString>
enum TransactionType
{
    OUT = 0,
    IN = 1
};

class TransactionTypeHelper
{
public:
    QString static ToString(TransactionType type)
    {
        if(type == IN)
            return "IN";
        else if(type == OUT)
            return "OUT";
        else
            return "";
    }

    TransactionType static FromString(QString strType)
    {
        if(strType == "OUT")
            return OUT;
        else if(strType == "IN")
            return IN;

    }
};








#endif // TRANSACTION_TYPE_H
