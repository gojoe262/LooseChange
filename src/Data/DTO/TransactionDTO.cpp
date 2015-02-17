#include "TransactionDTO.h"

TransactionDTO::TransactionDTO()
{
}

TransactionDTO::TransactionDTO(QString inId, QDate inDate, double inAmount, TransactionType inTransactionType, QString inCategoryId, QString inComment)
{
    id = inId;
    date = inDate;
    amount = inAmount;
    transactionType = inTransactionType;
    categoryId = inCategoryId;
    comment = inComment;
}

TransactionDTO & TransactionDTO::operator =(const TransactionDTO & other)
{
    id = other.id;
    date = other.date;
    amount = other.amount;
    transactionType = other.transactionType;
    categoryId = other.categoryId;
    comment = other.comment;
    return *this;
}

