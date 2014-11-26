#ifndef TRANSACTIONDTO_H
#define TRANSACTIONDTO_H

#include <QDate>
#include <Utility/TransactionType.h>
#include <Utility/Categories.h>

class TransactionDTO
{
public:
    TransactionDTO();

    /**
     * @brief LooseChangeDTO - Constructs a LooseChangeDTO
     * @param inId
     * @param inDate
     * @param inAmount
     * @param inType
     * @param inCategory
     * @param inComment
     */
    TransactionDTO(int inId, QDate inDate, double inAmount, TransactionType inTransactionTypeCode, Category inCategoryCode, QString inComment);

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
    void SetAmount(double amount)
    {
        this->amount = amount;
    }

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

#endif // TRANSACTIONDTO_H
