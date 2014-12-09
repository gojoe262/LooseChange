#include "TransactionDTO.h"

TransactionDTO::TransactionDTO()
{
}

TransactionDTO::TransactionDTO(int inId, QDate inDate, double inAmount, TransactionType inTransactionType, int inCategoryId, QString inComment)
{
    id = inId;
    date = inDate;
    amount = inAmount;
    transactionType = inTransactionType;
    categoryId = inCategoryId;
    comment = inComment;
}
