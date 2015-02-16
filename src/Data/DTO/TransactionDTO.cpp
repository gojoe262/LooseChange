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

bool TransactionDTO::IsLessThanByDate(const TransactionDTO &t1, const TransactionDTO &t2)
{
    return t1.date < t2.date;
}

bool TransactionDTO::IsGreaterThanByDate(const TransactionDTO &t1, const TransactionDTO &t2)
{
    return t1.date > t2.date;
}
