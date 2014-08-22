#ifndef LOOSECHANGEDTO_H
#define LOOSECHANGEDTO_H

#include <QDate>
#include <Utility/Type.h>

class LooseChangeDTO
{
public:
    LooseChangeDTO();

    /**
     * @brief LooseChangeDTO - Constructs a LooseChangeDTO
     * @param inDate
     * @param inAmount
     * @param inType
     * @param inComment
     */
    LooseChangeDTO(QDate inDate, float inAmount, Type inType, QString inComment);

    /**
     * @brief date - Transaction Date
     */
    QDate date;

    /**
     * @brief amount - Transaction Amount
     */
    float amount;

    /**
     * @brief type - Transaction Type (in, out)
     */
    Type type;

    /**
     * @brief comment - Transation Comment
     */
    QString comment;

    //QString category??



};

#endif // LOOSECHANGEDTO_H
