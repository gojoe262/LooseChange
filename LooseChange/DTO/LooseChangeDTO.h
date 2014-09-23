#ifndef LOOSECHANGEDTO_H
#define LOOSECHANGEDTO_H

#include <QDate>
#include <Utility/TransactionType.h>
#include <Utility/Categories.h>

class LooseChangeDTO
{
public:
    LooseChangeDTO();

    /**
     * @brief LooseChangeDTO - Constructs a LooseChangeDTO
     * @param inId
     * @param inDate
     * @param inAmount
     * @param inType
     * @param inCategory
     * @param inComment
     */
    LooseChangeDTO(int inId, QDate inDate, double inAmount, TransactionType inTransactionTypeCode, Category inCategoryCode, QString inComment);

    /**
     * @brief id - Unique Id of the Transaction
     */
    int id;

    /**
     * @brief date - Transaction Date
     */
    QDate date;

    /**
     * @brief amount - Transaction Amount
     */
    double amount;

    /**
     * @brief type - Transaction Type (in, out)
     */
    TransactionType transactionType;

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
