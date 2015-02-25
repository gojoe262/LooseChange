#ifndef RAWVIEWPRESENTER_H
#define RAWVIEWPRESENTER_H

#include <QWidget>
#include <Data/Cache/CachedData.h>
#include <Data/DAO/TransactionDAO.h>
#include <Data/DAO/CategoryDAO.h>
#include <UI/Models/RawViewTableModel.h>
#include <UI/Delegates/DateEditDelegate.h>
#include <UI/Delegates/DoubleSpinBoxDelegate.h>
#include <UI/Delegates/TransactionTypeComboBoxDelegate.h>
#include <UI/Delegates/CategoryComboBoxDelegate.h>
#include <UI/Delegates/CommentLineEditDelegate.h>

namespace Ui {
class RawViewPresenter;
}

/**
 * @brief The RawViewPresenter class.
 * Shows cachedData in a simple table view. DAOs are used to
 * access/modify the data. Delegates are used to enhance
 * the tableView.
 */
class RawViewPresenter: public QWidget
{
    Q_OBJECT

public:
    explicit RawViewPresenter(CachedData *inCachedDataPointer, QWidget *parent = 0);
    ~RawViewPresenter();

    /**
     * @brief Refresh - Retrives and loads the cached data
     */
    void Refresh();

private slots:
    void MarkDirty();

    /**
     * @brief on_pushButtonAddTransaction_clicked - Add a transaction to the end of the list
     */
    void on_pushButtonAddTransaction_clicked();

    /**
     * @brief on_pushButtonRemoveSelectedTransactions_clicked - Removes the selected transactions
     */
    void on_pushButtonRemoveSelectedTransactions_clicked();

signals:
    void DataChanged();

private:

    QList<QString> GetSelectedTransactionsIds();

    Ui::RawViewPresenter *ui;

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
