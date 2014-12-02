#ifndef RAWVIEWPRESENTER_H
#define RAWVIEWPRESENTER_H

#include <DataAccess/TransactionDAO.h>
#include <DataAccess/CategoryDAO.h>
#include <QTableWidget>

class RawViewPresenter : public QObject
{
    Q_OBJECT
public:
    RawViewPresenter();
    RawViewPresenter(QTableWidget *tableWidget, TransactionDAO *inTransactionDAO, CategoryDAO *inCategoryDAO, QWidget *parent = 0);
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
    TransactionDAO *transactionDAO;
    CategoryDAO *categoryDAO;
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

    /**
     * @brief ChangeCategory
     * @param category
     * @param index
     */
    void ChangeCategory(CategoryDTO category, QModelIndex index);

    /**
     * @brief ChangeComment
     * @param comment
     * @param index
     */
    void ChangeComment(QString comment, QModelIndex index);

    void AddCategory(QModelIndex index);
};

#endif // RAWVIEWPRESENTER_H
