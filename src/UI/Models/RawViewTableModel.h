#ifndef RAWVIEWTABLEMODEL_H
#define RAWVIEWTABLEMODEL_H

#include <QAbstractTableModel>
#include <Data/DAO/TransactionDAO.h>
#include <Data/DAO/CategoryDAO.h>

class RawViewTableModel : public QAbstractTableModel
{
    Q_OBJECT
public:
     RawViewTableModel(TransactionDAO *inTransactionDAOPointer,
                       CategoryDAO *inCategoryDAOPointer, QObject * parent = 0);
    ~RawViewTableModel();

     /**
     * @brief rowCount
     * @param index
     * @return
     */
    int rowCount(const QModelIndex &index) const;

    /**
     * @brief columnCount
     * @param index
     * @return
     */
    int columnCount(const QModelIndex &index) const;

    /**
     * @brief data
     * @param index
     * @param role
     * @return This shows the data to be seen in the table view
     */
    QVariant data(const QModelIndex &index, int role = Qt::DisplayRole) const;

    bool setData(const QModelIndex &index, const QVariant &value, int role=Qt::EditRole);

    Qt::ItemFlags flags(const QModelIndex &index) const;

    /**
     * @brief sort - Allows the user to sort by a column. This is
     * used when the user click on a column header.
     * @param column
     * @param order
     */
    void sort(int column, Qt::SortOrder order = Qt::AscendingOrder);

    /**
     * @brief Refresh - Forces a re-retreive from the cached data
     */
    void Refresh();

private:
    CategoryDAO *categoryDAO;
    TransactionDAO *transactionDAO;
};

#endif // RAWVIEWTABLEMODEL_H
