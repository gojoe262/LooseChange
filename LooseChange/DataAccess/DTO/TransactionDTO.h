#ifndef TRANSACTIONDTO_H
#define TRANSACTIONDTO_H

#include <QDate>
#include <Utility/TransactionType.h>
#include <DataAccess/DTO/CategoryDTO.h>

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
    TransactionDTO(int inId, QDate inDate, double inAmount, TransactionType inTransactionTypeCode, CategoryDTO inCategory, QString inComment);

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
     * @brief category - Category
     */
    CategoryDTO category;

    /**
     * @brief comment - Transation Comment
     */
    QString comment;

};

#endif // TRANSACTIONDTO_H
