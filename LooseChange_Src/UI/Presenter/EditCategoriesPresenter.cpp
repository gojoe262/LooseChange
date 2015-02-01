#include "EditCategoriesPresenter.h"
#include "ui_EditCategoriesPresenter.h"

#include <QMessageBox>

EditCategoriesPresenter::EditCategoriesPresenter(CachedData *cachedDataPointer, QWidget *parent) :
    QDialog(parent),
    ui(new Ui::EditCategoriesPresenter)
{
    ui->setupUi(this);
    dirty = false;


    categoryDAO = new CategoryDAO(cachedDataPointer);
    transactionDAO = new TransactionDAO(cachedDataPointer);
    model = new EditCategoriesTableModel(categoryDAO, this);

    ///Connects any change from the model -> to marking the data a dirtied.
    connect(model, SIGNAL(dataChanged(QModelIndex,QModelIndex)), this, SLOT(MarkDirty()));

    ui->tableView->setModel(model);
    ui->tableView->hideColumn(0);
    ui->tableView->verticalHeader()->hide();
    ui->tableView->horizontalHeader()->hide();
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
        accept();// Changes were made
    }
    else
    {
        reject();// No changes were made, so we can just reject it.
    }
}

void EditCategoriesPresenter::on_pushButtonCancel_clicked()
{
    reject();
}

void EditCategoriesPresenter::MarkDirty()
{
    dirty = true;
}

void EditCategoriesPresenter::on_pushButtonAdd_clicked()
{
    categoryDAO->AddCategory();
    MarkDirty();
    Load();
}


/**
 * @brief EditCategoriesPresenter::on_pushButtonRemove_clicked
 * TODO: BREAK THIS INTO SMALLER SUB-FUNCTIONS
 */
void EditCategoriesPresenter::on_pushButtonRemove_clicked()
{
    QModelIndexList indexList = ui->tableView->selectionModel()->selectedIndexes();//selected rows
    bool changesMade = false;

    /// First get all the ids and put them into a list.
    QList<QString> categoryIdList;
    foreach(QModelIndex index, indexList)
    {
        QString categoryId = ui->tableView->model()->data(ui->tableView->model()->index(index.row(), 0)).toString();
        categoryIdList.append(categoryId);
    }

    /// Next, iterate thru the categoryIdList and remove categories
    /// with that id.
    foreach(QString categoryId, categoryIdList)
    {
        /// Check if its in transactions
        bool foundInTransactions = false;
        QList<TransactionDTO> transactionList = transactionDAO->GetTransactionList();
        foreach(TransactionDTO transaction, transactionList)
        {
            if(!foundInTransactions && transaction.categoryId == categoryId) /// Id matches a transaction that uses that category. Bad things will happen if deleted!!!
            {
                 QMessageBox::information(0, "Category Is In Use", "Cannot remove category '" + categoryDAO->GetCategoryById(categoryId).description + "\'. \nCategory is being used in a transaction." +
                                          "\n\n   " + "Transaction Details:" +
                                          "\n      " + transaction.date.toString("MM/dd/yyyy") +
                                          "\n      " + QString::number(transaction.amount, 'f', 2) +
                                          "\n      " + TransactionTypeHelper::ToString(transaction.transactionType) +
                                          "\n      " + categoryDAO->GetCategoryById(transaction.categoryId).description +
                                          "\n      " + transaction.comment);
                 foundInTransactions = true;
            }
        }

        ///If not in transactions allow removal
        if(!foundInTransactions)
        {
            bool change = categoryDAO->RemoveCategory(categoryId);
            if(change)
            {
                changesMade = true;
            }
        }
    }

    if(changesMade)
    {
        MarkDirty();
    }
    Load();
}
