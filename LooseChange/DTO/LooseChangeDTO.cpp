#include "LooseChangeDTO.h"

LooseChangeDTO::LooseChangeDTO()
{
}

LooseChangeDTO::LooseChangeDTO(QDate inDate, float inAmount, TransactionType inTransactionType, Category inCategory, QString inComment)
{
    date = inDate;
    amount = inAmount;
    transactionType = inTransactionType;
    category = inCategory;
    comment = inComment;
}
