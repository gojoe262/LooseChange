#ifndef EDITCATEGORIESPRESENTER_H
#define EDITCATEGORIESPRESENTER_H

#include <QDialog>

namespace Ui {
class EditCategoriesPresenter;
}

class EditCategoriesPresenter : public QDialog
{
    Q_OBJECT

public:
    explicit EditCategoriesPresenter(QWidget *parent = 0);
    ~EditCategoriesPresenter();

private:
    Ui::EditCategoriesPresenter *ui;
};

#endif // EDITCATEGORIESPRESENTER_H
