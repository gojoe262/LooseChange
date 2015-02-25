#ifndef ADDTRANSACTIONPRESENTER_H
#define ADDTRANSACTIONPRESENTER_H

#include <QDialog>
#include <Data/Cache/CachedData.h>
#include <Data/DAO/TransactionDAO.h>
#include <Data/DAO/CategoryDAO.h>


namespace Ui {
class AddTransactionPresenter;
}

/**
 * @brief The AddTransactionPresenter class - Allows the user to add a transaction to the cachedData
 */
class AddTransactionPresenter : public QDialog
{
    Q_OBJECT

public:
    explicit AddTransactionPresenter(CachedData *inCachedDataPointer, QWidget *parent = 0);
    ~AddTransactionPresenter();

signals:
    void DataChanged();

private slots:
    /**
     * @brief on_pushButtonCancel_clicked - Returns the Rejected status code and closes the window.
     */
    void on_pushButtonCancel_clicked();

    /**
     * @brief on_pushButtonAdd_clicked - Returns the Accepted status code and closes the window.
     */
    void on_pushButtonAdd_clicked();

private:
    Ui::AddTransactionPresenter *ui;

    TransactionDAO *transactionDAO;
    CategoryDAO *categoryDAO;


};

#endif // ADDTRANSACTIONPRESENTER_H
