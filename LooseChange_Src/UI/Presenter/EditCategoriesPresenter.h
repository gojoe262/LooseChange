#ifndef EDITCATEGORIESPRESENTER_H
#define EDITCATEGORIESPRESENTER_H

#include <QDialog>
#include <Data/Cache/CachedData.h>
#include <Data/DAO/CategoryDAO.h>
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

signals:
    void DataChanged() const;

private:
    Ui::EditCategoriesPresenter *ui;
    CategoryDAO *categoryDAO;
    EditCategoriesTableModel *model;
    bool dirty;



};

#endif // EDITCATEGORIESPRESENTER_H
