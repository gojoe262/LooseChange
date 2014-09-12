#include "LooseChangeDTO.h"

LooseChangeDTO::LooseChangeDTO()
{
}

LooseChangeDTO::LooseChangeDTO(int inId, QDate inDate, float inAmount, TransactionType inTransactionType, Category inCategory, QString inComment)
{
    id = inId;
    date = inDate;
    amount = inAmount;
    transactionType = inTransactionType;
    category = inCategory;
    comment = inComment;
}
