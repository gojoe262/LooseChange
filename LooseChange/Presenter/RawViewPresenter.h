#ifndef RAWVIEWPRESENTER_H
#define RAWVIEWPRESENTER_H

#include <Data/DAO/TransactionDAO.h>
#include <Data/DAO/CategoryDAO.h>
#include <Models/RawViewTableModel.h>
#include <Delegates/DateEditDelegate.h>
#include <Delegates/DoubleSpinBoxDelegate.h>
#include <Delegates/TransactionTypeComboBoxDelegate.h>
#include <Delegates/CategoryComboBoxDelegate.h>
#include <Delegates/CommentLineEditDelegate.h>
#include <QTableWidget>

class RawViewPresenter : public QObject
{
    Q_OBJECT
public:
    RawViewPresenter();
    RawViewPresenter(QTableView *inTableView, CachedData *inCachedDataPointer, QWidget *parent = 0);

    ~RawViewPresenter();

    /**
     * @brief Load - Loads the data (from dao) to the table
     */
    void Load();


private:
    QTableWidget *table;
    QTableView *tableView;
    RawViewTableModel *model;
    CachedData *cachedDataPointer;

    TransactionDAO *transactionDAO;
    CategoryDAO *categoryDAO;

    DateEditDelegate *dateEdit;// = new DateEditDelegate(this);
    DoubleSpinBoxDelegate *doubleSpinBox;// = new DoubleSpinBoxDelegate(this);
    TransactionTypeComboBoxDelegate *transactionTypeComboBox;// = new TransactionTypeComboBoxDelegate(this);
    CategoryComboBoxDelegate *categoryComboBox;// = new CategoryComboBoxDelegate(categoryDAO, this);
    CommentLineEditDelegate *commentLineEdit;// = new CommentLineEditDelegate(this);


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

    /**
     * @brief ChangeCategory
     * @param index
     * @param categoryId
     */
    void ChangeCategory(QModelIndex index, int categoryId);

    /**
     * @brief AddCategory
     * @param index
     */
    void AddCategory(QModelIndex index);

};

#endif // RAWVIEWPRESENTER_H
