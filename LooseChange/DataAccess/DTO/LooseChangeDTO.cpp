#include "LooseChangeDTO.h"

LooseChangeDTO::LooseChangeDTO()
{
}

LooseChangeDTO::LooseChangeDTO(int inId, QDate inDate, double inAmount, TransactionType inTransactionType, Category inCategory, QString inComment)
{
    id = inId;
    date = inDate;
    amount = inAmount;
    transactionType = inTransactionType;
    category = inCategory;
    comment = inComment;
}
