#ifndef RAWVIEWPRESENTER_H
#define RAWVIEWPRESENTER_H

#include <DAO/LooseChangeDAO.h>
#include <QTableWidget>

class RawViewPresenter : public QObject
{
    Q_OBJECT
public:
    RawViewPresenter();
    RawViewPresenter(QTableWidget *tableWidget, LooseChangeDAO *inDAO, QWidget *parent = 0);
    ~RawViewPresenter();

    /**
     * @brief Load - Loads the data (from dao) to the table
     */
    void Load();

private:
    /**
     * @brief GetIdFromModelIndex - Get the id from the table given the index
     * @param index
     * @return id
     */
    int GetIdFromModelIndex(QModelIndex index) const;

    QTableWidget *table;
    LooseChangeDAO *dao;

public slots:
    /**
     * @brief ChangeAmount - Changes the amount
     * @param value
     * @param index
     */
    void ChangeAmount(double value, QModelIndex index);

    /**
     * @brief ChangeDate
     * @param date
     * @param index
     */
    void ChangeDate(QDate date, QModelIndex index);

    /**
     * @brief ChangeTransactionType
     * @param type
     * @param index
     */
    void ChangeTransactionType(TransactionType type, QModelIndex index);
};

#endif // RAWVIEWPRESENTER_H
