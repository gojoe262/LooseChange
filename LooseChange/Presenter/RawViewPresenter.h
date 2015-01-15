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
//    RawViewPresenter();
    RawViewPresenter(QTableView *inTableView, CachedData *inCachedDataPointer, QWidget *parent = 0);

    ~RawViewPresenter();

    /**
     * @brief Load - Loads the data (from DAOs) to the table
     */
    void Load();

public slots:
    /**
     * @brief AddCategory
     * @param index
     */
    void AddCategory(QModelIndex index);

private:
    QTableView *tableView;
    RawViewTableModel *model;

    TransactionDAO *transactionDAO;
    CategoryDAO *categoryDAO;

    DateEditDelegate *dateEdit;
    DoubleSpinBoxDelegate *doubleSpinBox;
    TransactionTypeComboBoxDelegate *transactionTypeComboBox;
    CategoryComboBoxDelegate *categoryComboBox;
    CommentLineEditDelegate *commentLineEdit;

};

#endif // RAWVIEWPRESENTER_H
