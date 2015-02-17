#ifndef TRANSACTIONDAO_H
#define TRANSACTIONDAO_H


#include <Data/DTO/TransactionDTO.h>
#include <Data/Cache/CachedData.h>
#include <QtAlgorithms>


class TransactionDAO : public QObject
{
    Q_OBJECT
public:
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

    /**
     * @brief SortTransactionList - Sorts the Transaction List by date in either
     * ascending or descending order.
     */
    void SortTransactionListByDate(Qt::SortOrder order = Qt::AscendingOrder);

    /**
     * @brief SortTransactionListByAmount - Sorts the Transaction List by amount in either
     * ascending or descending order.
     * @param order
     */
    void SortTransactionListByAmount(Qt::SortOrder order = Qt::AscendingOrder);

    /**
     * @brief SortTransactionListByType - Sorts the Transaction List by type in either
     * ascending or descending order.
     * @param order
     */
    void SortTransactionListByTransactionType(Qt::SortOrder order = Qt::AscendingOrder);

    /**
     * @brief SortTransactionListByCategory - Sorts the Transaction List by type in either
     * ascending or descending order.
     * @param order
     */
    void SortTransactionListByCategory(Qt::SortOrder order = Qt::AscendingOrder);



private:

    /**
     * @brief IsLessThanByDate - Compares the transactionDTOs by date.
     * @param t1
     * @param t2
     * @return True if t1.date is less than t2.date, otherwise false.
     */
    static bool IsLessThanByDate(const TransactionDTO& t1, const TransactionDTO& t2);
    static bool IsGreaterThanByDate(const TransactionDTO& t1, const TransactionDTO& t2);

    /**
     * @brief IsLessThanByAmount - Compares the transactionDTOs by amount.
     * @param t1
     * @param t2
     * @return
     */
    static bool IsLessThanByAmount(const TransactionDTO& t1, const TransactionDTO& t2);
    static bool IsGreaterThanByAmount(const TransactionDTO& t1, const TransactionDTO& t2);

    /**
     * @brief IsLessThanByTransactionType - Compares the transactionDTOs by transactionType.
     * @param t1
     * @param t2
     * @return
     */
    static bool IsLessThanByTransactionType(const TransactionDTO &t1, const TransactionDTO &t2);
    static bool IsGreaterThanByTransactionType(const TransactionDTO &t1, const TransactionDTO &t2);

    /**
     * @brief IsLessThanByCategory
     * @param t1
     * @param t2
     * @return
     */
    bool IsLessThanByCategory(const TransactionDTO &t1, const TransactionDTO &t2);
    bool IsGreaterThanByCategory(const TransactionDTO &t1, const TransactionDTO &t2);

    /**
     * @brief SortByCategory - Sorts the transaction List by category
     * @param order
     */
    void SortByCategory(Qt::SortOrder order = Qt::AscendingOrder);

    /**
     * @brief FindTransactionById - Find the transaciton with the given transactionId
     * @param id
     * @return Returns a pointer to the transaction.
     */
    TransactionDTO* FindTransactionById(QString id);

    /**
     * @brief cachedDataPointer
     */
    CachedData *cachedDataPointer;

};

#endif // TRANSACTIONDAO_H
