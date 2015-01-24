#include "EditCategoriesPresenter.h"
#include "ui_EditCategoriesPresenter.h"

EditCategoriesPresenter::EditCategoriesPresenter(CachedData *cachedDataPointer, QWidget *parent) :
    QDialog(parent),
    ui(new Ui::EditCategoriesPresenter)
{
    ui->setupUi(this);
    dirty = false;

    connect(cachedDataPointer, SIGNAL(MarkDirty()), this, SLOT(MarkDirty()));
    categoryDAO = new CategoryDAO(cachedDataPointer);
    model = new EditCategoriesTableModel(categoryDAO, this);

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
        done(Accepted); //Changes Made and accepted
    }
    else
    {
        done(Rejected); //No Changes Made but still accepted
    }
}

void EditCategoriesPresenter::on_pushButtonCancel_clicked()
{
    done(Rejected);
}

void EditCategoriesPresenter::MarkDirty()
{
    dirty = true;
}
