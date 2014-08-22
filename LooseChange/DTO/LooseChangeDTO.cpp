#include "LooseChangeDTO.h"

LooseChangeDTO::LooseChangeDTO()
{
}

LooseChangeDTO::LooseChangeDTO(QDate inDate, float inAmount, Type inType, Category inCategory, QString inComment)
{
    date = inDate;
    amount = inAmount;
    type = inType;
    category = inCategory;
    comment = inComment;
}
