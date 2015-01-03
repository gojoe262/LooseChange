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

    DateEditDelegate *dateEdit;
    DoubleSpinBoxDelegate *doubleSpinBox;
    TransactionTypeComboBoxDelegate *transactionTypeComboBox;
    CategoryComboBoxDelegate *categoryComboBox;
    CommentLineEditDelegate *commentLineEdit;


    /**
     * @brief GetIdFromModelIndex - Get the id from the table given the index
     * @param index
     * @return id
     */
    int GetIdFromModelIndex(QModelIndex index) const;


public slots:

    /**
     * @brief AddCategory
     * @param index
     */
    void AddCategory(QModelIndex index);

};

#endif // RAWVIEWPRESENTER_H
