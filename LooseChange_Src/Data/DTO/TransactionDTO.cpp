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
