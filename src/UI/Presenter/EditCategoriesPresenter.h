#ifndef EDITCATEGORIESPRESENTER_H
#define EDITCATEGORIESPRESENTER_H

#include <QDialog>
#include <QMessageBox>
#include <Data/Cache/CachedData.h>
#include <Data/DAO/CategoryDAO.h>
#include <Data/DAO/TransactionDAO.h>
#include <UI/Models/EditCategoriesTableModel.h>

namespace Ui {
class EditCategoriesPresenter;
}


class EditCategoriesPresenter : public QDialog
{
    Q_OBJECT

public:
    explicit EditCategoriesPresenter(CachedData *cachedDataPointer, QWidget *parent = 0);
    ~EditCategoriesPresenter();

    /**
     * @brief Load - Load the data to the table
     */
    void Load();

private slots:
    void on_pushButtonSave_clicked();

    void on_pushButtonCancel_clicked();

    void MarkDirty();

    void on_pushButtonAdd_clicked();

    void on_pushButtonRemove_clicked();

signals:
    void DataChanged() const;

private:
    /**
     * @brief GetSelectedCategoriesIds
     * @return Gets the category Ids that is currently selected in ui->tableView
     */
    QList<QString> GetSelectedCategoriesIds();


    Ui::EditCategoriesPresenter *ui;

    CategoryDAO *categoryDAO;
    TransactionDAO *transactionDAO;
    EditCategoriesTableModel *model;
    bool dirty;



};

#endif // EDITCATEGORIESPRESENTER_H