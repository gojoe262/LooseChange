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
     * @brief RetriveAndLoadCachedData - Retrives and Load the cached
     */
    void RetriveAndLoadCachedData();

private slots:
    void MarkDirty();

signals:
    void DataChanged();

private:
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
