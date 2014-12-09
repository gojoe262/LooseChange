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
     * @brief Add - Adds the dto to the cached List
     * @param inDto
     * @return
     */
    void AddTransaction(TransactionDTO inTransaction);

    /**
     * @brief UpdateAmount - Updates the amount on the dto with the matching Id
     * @param id
     * @param amount
     */
    void UpdateAmount(int id, double amount);

    /**
     * @brief UpdateDate - Updates the date on the dto with the matching Id
     * @param id
     * @param date
     */
    void UpdateDate(int id, QDate date);

    /**
     * @brief UpdateType
     * @param id
     * @param type
     */
    void UpdateType(int id, TransactionType type);

    /**
     * @brief UpdateComment
     * @param id
     * @param comment
     */
    void UpdateComment(int id, QString comment);

    /**
     * @brief UpdateCategory
     * @param id
     * @param category
     */
    void UpdateCategory(int id, int categoryId);

private:

    /**
     * @brief cachedDataPointer
     */
    CachedData *cachedDataPointer;
};

#endif // TRANSACTIONDAO_H
