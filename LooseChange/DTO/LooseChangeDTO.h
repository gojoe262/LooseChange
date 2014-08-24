#ifndef LOOSECHANGEDTO_H
#define LOOSECHANGEDTO_H

#include <QDate>
#include <Utility/Type.h>
#include <Utility/Categories.h>

class LooseChangeDTO
{
public:
    LooseChangeDTO();

    /**
     * @brief LooseChangeDTO - Constructs a LooseChangeDTO
     * @param inDate
     * @param inAmount
     * @param inType
     * @param inCategory
     * @param inComment
     */
    LooseChangeDTO(QDate inDate, float inAmount, Type inTransactionType, Category inCategory, QString inComment);


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
     * @brief category - Transaction Category
     */
    Category category;

    /**
     * @brief comment - Transation Comment
     */
    QString comment;


};

#endif // LOOSECHANGEDTO_H
