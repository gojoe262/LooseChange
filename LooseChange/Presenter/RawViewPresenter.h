#ifndef RAWVIEWPRESENTER_H
#define RAWVIEWPRESENTER_H

#include <Data/Accessors/TransactionDAO.h>
#include <Data/Accessors/CategoryDAO.h>
#include <QTableWidget>

class RawViewPresenter : public QObject
{
    Q_OBJECT
public:
    RawViewPresenter();
    RawViewPresenter(QTableWidget *tableWidget, CachedData *inCachedDataPointer, QWidget *parent = 0);

    ~RawViewPresenter();

    /**
     * @brief Load - Loads the data (from dao) to the table
     */
    void Load();


private:
    QTableWidget *table;
    CachedData *cachedDataPointer;

    TransactionDAO *transactionDAO;
    CategoryDAO *categoryDAO;

    /**
     * @brief GetIdFromModelIndex - Get the id from the table given the index
     * @param index
     * @return id
     */
    int GetIdFromModelIndex(QModelIndex index) const;


public slots:
    /**
     * @brief ChangeAmount - Changes the amount
     * @param value
     * @param index
     */
    void ChangeAmount(QModelIndex index, double amount);

    /**
     * @brief ChangeDate
     * @param date
     * @param index
     */
    void ChangeDate(QModelIndex index, QDate date);

    /**
     * @brief ChangeTransactionType
     * @param type
     * @param index
     */
    void ChangeTransactionType(QModelIndex index, TransactionType type);

    /**
     * @brief ChangeComment
     * @param comment
     * @param index
     */
    void ChangeComment(QModelIndex index, QString comment);
};

#endif // RAWVIEWPRESENTER_H
