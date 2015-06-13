#include "AddTransactionPresenter.h"
#include "ui_AddTransactionPresenter.h"

#include <QMessageBox>
#include <Utility/TransactionType.h>

AddTransactionPresenter::AddTransactionPresenter(CachedData *inCachedDataPointer, QWidget *parent) :
    QDialog(parent),
    ui(new Ui::AddTransactionPresenter)
{
    ui->setupUi(this);

    transactionDAO = new TransactionDAO(inCachedDataPointer);
    categoryDAO = new CategoryDAO(inCachedDataPointer);


    ui->dateEditDate->setDate(QDate::currentDate());
    ui->comboBoxType->addItem(TransactionTypeHelper::ToString(OUT_TRANSACTION), OUT_TRANSACTION);
    ui->comboBoxType->addItem(TransactionTypeHelper::ToString(IN_TRANSACTION), IN_TRANSACTION);

    QList<CategoryDTO> categoryList = categoryDAO->GetCategories();
    foreach(CategoryDTO category, categoryList)
    {
        ui->comboBoxCategory->addItem(category.description, category.id);
    }
}

AddTransactionPresenter::~AddTransactionPresenter()
{
    delete transactionDAO;
    delete categoryDAO;
    delete ui;
}

void AddTransactionPresenter::on_pushButtonCancel_clicked()
{
    reject();
    this->close();
}

void AddTransactionPresenter::on_pushButtonAdd_clicked()
{
    transactionDAO->AddTransaction(ui->dateEditDate->date(),
                                   ui->doubleSpinBoxAmount->value(),
                                   (TransactionType)ui->comboBoxType->currentData().toInt(),
                                   ui->comboBoxCategory->currentData().toString(),
                                   ui->lineEditComment->text());
    emit DataChanged();
    accept();
}
