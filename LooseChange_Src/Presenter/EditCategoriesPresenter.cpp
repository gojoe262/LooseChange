#include "EditCategoriesPresenter.h"
#include "ui_EditCategoriesPresenter.h"

EditCategoriesPresenter::EditCategoriesPresenter(CachedData *cachedDataPointer, QWidget *parent) :
    QDialog(parent),
    ui(new Ui::EditCategoriesPresenter)
{
    ui->setupUi(this);
    dirty = false;


    categoryDAO = new CategoryDAO(cachedDataPointer);
    model = new EditCategoriesTableModel(categoryDAO, this);
    connect(model, SIGNAL(dataChanged(QModelIndex,QModelIndex)), this, SLOT(MarkDirty()));

    ui->tableView->setModel(model);
    Load();
}

EditCategoriesPresenter::~EditCategoriesPresenter()
{
    delete categoryDAO;
    delete model;
    delete ui;
}

void EditCategoriesPresenter::Load()
{
    model->Refresh();
}

void EditCategoriesPresenter::on_pushButtonSave_clicked()
{
    if(dirty)
    {
        accept();
    }
    else
    {
        reject();//;done(QDialog::Rejected); //No Changes Made but still accepted
    }
}

void EditCategoriesPresenter::on_pushButtonCancel_clicked()
{
    reject();
}

void EditCategoriesPresenter::MarkDirty()
{
    emit DataChanged();
    dirty = true;
}

