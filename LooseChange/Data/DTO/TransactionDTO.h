#ifndef TRANSACTIONDTO_H
#define TRANSACTIONDTO_H

#include <QDate>
#include <Utility/TransactionType.h>
#include <Data/DTO/CategoryDTO.h>

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
    TransactionDTO(int inId, QDate inDate, double inAmount, TransactionType inTransactionTypeCode, int inCategoryId, QString inComment);

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
     * @brief categoryId
     */
    int categoryId;

    /**
     * @brief comment - Transation Comment
     */
    QString comment;

};

#endif // TRANSACTIONDTO_H
