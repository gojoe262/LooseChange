#include "EditCategoriesPresenter.h"
#include "ui_EditCategoriesPresenter.h"

EditCategoriesPresenter::EditCategoriesPresenter(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::EditCategoriesPresenter)
{
    ui->setupUi(this);
}

EditCategoriesPresenter::~EditCategoriesPresenter()
{
    delete ui;
}
