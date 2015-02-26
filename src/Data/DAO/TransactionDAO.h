#ifndef TRANSACTIONDAO_H
#define TRANSACTIONDAO_H


#include <Data/DTO/TransactionDTO.h>
#include <Data/Cache/CachedData.h>
#include <QtAlgorithms>
#include <QObject>


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
     * @brief AddTransaction - Appends a transaction to the start of the list
     * @param inDate
     * @param inAmount
     * @param inTransactionType
     * @param inCategoryId
     * @param inComment
     */
    void AddTransaction(QDate inDate, double inAmount, TransactionType inTransactionType, QString inCategoryId, QString inComment);

    /**
     * @brief RemoveTransaction
     * @param transactionId
     */
    bool RemoveTransaction(QString transactionId);

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
     * ascending or descending order. Sort Implemented by hand.
     * @param order
     */
    void SortTransactionListByCategory(Qt::SortOrder order = Qt::AscendingOrder);

    /**
     * @brief SortTransactionListByComment - Sorts the Transaction List by comment in either
     * ascending or descending order.
     * @param order
     */
    void SortTransactionListByComment(Qt::SortOrder order = Qt::AscendingOrder);


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
     * @brief IsLessThanByCategory - Compares the transactionDTOs by category.
     * @param t1
     * @param t2
     * @return
     */
    bool IsLessThanByCategory(const TransactionDTO &t1, const TransactionDTO &t2);
    bool IsGreaterThanByCategory(const TransactionDTO &t1, const TransactionDTO &t2);

    /**
     * @brief IsLessThanByComment - Compares the transactionDTOs by comment.
     * @param t1
     * @param t2
     * @return
     */
    static bool IsLessThanByComment(const TransactionDTO &t1, const TransactionDTO &t2);
    static bool IsGreaterThanByComment(const TransactionDTO &t1, const TransactionDTO &t2);

    /**
     * @brief FindTransactionById - Find the transaciton with the given transactionId
     * @param id
     * @return Returns a pointer to the transaction.
     */
    TransactionDTO* FindTransactionById(QString id);

    /**
     * @brief GenerateUniqueKey - Generates a unique key. Check uniqueness against the current transaction list.
     * @return
     */
    QString GenerateUniqueKey();

    /**
     * @brief cachedDataPointer
     */
    CachedData *cachedDataPointer;

};

#endif // TRANSACTIONDAO_H
