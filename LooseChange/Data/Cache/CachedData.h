#ifndef CACHEDDTOLIST_H
#define CACHEDDTOLIST_H

#include <Data/DTO/TransactionDTO.h>

class CachedData : public QObject
{
    Q_OBJECT
public:
    CachedData(QObject *parent = 0);

    ~CachedData();

    /**
     * @brief ReadFile
     * @param fileLocation
     */
    void ReadFile(QString fileLocation);

    /**
     * @brief WriteFile
     * @param fileLocation
     */
    void WriteFile(QString fileLocation);


    /**
     * @brief GetTransactionList
     * @return
     */
    QList<TransactionDTO> GetTransactionList();

    /**
     * @brief AddTransaction
     * @param transactionDTO
     */
    void AddTransaction(TransactionDTO inTransactionDTO);

    /**
     * @brief UpdateTransactionAmount
     * @param id
     * @param amount
     */
    void UpdateTransactionAmount(int id, double amount);

    /**
     * @brief UpdateTransactionDate
     * @param id
     * @param date
     * @return
     */
    void UpdateTransactionDate(int id, QDate date);

    /**
     * @brief UpdateTransactionType
     * @param id
     * @param type
     */
    void UpdateTransactionType(int id, TransactionType type);

    /**
     * @brief UpdateTransactionComment
     * @param id
     * @param comment
     */
    void UpdateTransactionComment(int id, QString comment);

signals:
    void MarkDirty() const;
    void MarkClean() const;

private:
    QList<TransactionDTO>   transactionList;


};

#endif // CACHEDDTOLIST_H
