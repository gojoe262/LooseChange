#include "LooseChangeDTO.h"

LooseChangeDTO::LooseChangeDTO()
{
}

LooseChangeDTO::LooseChangeDTO(QDate inDate, float inAmount, Type inType, QString inComment)
{
    date = inDate;
    amount = inAmount;
    type = inType;
    comment = inComment;
}
