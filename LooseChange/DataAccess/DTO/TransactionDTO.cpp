#include "TransactionDTO.h"

TransactionDTO::TransactionDTO()
{
}

TransactionDTO::TransactionDTO(int inId, QDate inDate, double inAmount, TransactionType inTransactionType, CategoryDTO inCategory, QString inComment)
{
    id = inId;
    date = inDate;
    amount = inAmount;
    transactionType = inTransactionType;
    category = inCategory;
    comment = inComment;
}
