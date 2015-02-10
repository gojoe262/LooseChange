#ifndef TRANSACTIONDTO_H
#define TRANSACTIONDTO_H

#include <QDate>
#include <Utility/TransactionType.h>

//https://github.com/vpiotr/decimal_for_cpp -- For Decimals???

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
    TransactionDTO(QString inId, QDate inDate, double inAmount, TransactionType inTransactionTypeCode, QString inCategoryId, QString inComment);

    /**
     * @brief id - Unique Id of the Transaction
     */
    QString id;

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
     * @brief categoryId
     */
    QString categoryId;

    /**
     * @brief comment - Transation Comment
     */
    QString comment;

};

#endif // TRANSACTIONDTO_H
