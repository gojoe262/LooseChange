#ifndef TRANSACTIONDAO_H
#define TRANSACTIONDAO_H


#include <Data/DTO/TransactionDTO.h>
#include <Data/Cache/CachedData.h>


class TransactionDAO : public QObject
{
    Q_OBJECT
public:
    TransactionDAO();
    TransactionDAO(CachedData *inCachedDataPointer, QWidget *parent = 0);

    ~TransactionDAO();

    /**
     * @brief GetTransactionList
     * @return
     */
    QList<TransactionDTO> GetTransactionList();

    /**
     * @brief UpdateAmount - Updates the amount on the dto with the matching Id
     * @param id
     * @param amount
     */
    bool UpdateAmount(QString id, double amount);

    /**
     * @brief UpdateDate - Updates the date on the dto with the matching Id
     * @param id
     * @param date
     */
    bool UpdateDate(QString id, QDate date);

    /**
     * @brief UpdateType
     * @param id
     * @param type
     */
    bool UpdateType(QString id, TransactionType type);

    /**
     * @brief UpdateComment
     * @param id
     * @param comment
     */
    bool UpdateComment(QString id, QString comment);

    /**
     * @brief UpdateCategory
     * @param id
     * @param category
     */
    bool UpdateCategory(QString id, QString categoryId);

    /**
     * @brief GetTransactionsThatUseCategory
     * @param categoryId
     * @return
     */
    QList<TransactionDTO> GetTransactionsByCategoryId(QString categoryId);

private:

    /**
     * @brief cachedDataPointer
     */
    CachedData *cachedDataPointer;
};

#endif // TRANSACTIONDAO_H
