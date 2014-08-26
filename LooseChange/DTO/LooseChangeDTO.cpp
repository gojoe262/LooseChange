#include "LooseChangeDTO.h"

LooseChangeDTO::LooseChangeDTO()
{
}

LooseChangeDTO::LooseChangeDTO(QDate inDate, float inAmount, Type inTransactionType, Category inCategory, QString inComment)
{
    date = inDate;
    amount = inAmount;
    transactionType = inTransactionType;
    category = inCategoryCode;
    comment = inComment;
}
