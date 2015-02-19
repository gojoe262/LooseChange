#include "EditCategoriesPresenter.h"
#include "ui_EditCategoriesPresenter.h"

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
    LoadDataToView();
}

EditCategoriesPresenter::~EditCategoriesPresenter()
{
    delete categoryDAO;
    delete model;
    delete ui;
}

void EditCategoriesPresenter::LoadDataToView()
{
    model->Refresh();
}

void EditCategoriesPresenter::on_pushButtonSave_clicked()
{
    if(dirty)
    {
        categoryDAO->SortCategories();
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
    LoadDataToView();
}

void EditCategoriesPresenter::on_pushButtonRemove_clicked()
{
    bool changesMade = false;

    /// First get the selected categoryIds and put them into a list.
    QList<QString> categoryIdList = GetSelectedCategoriesIds();

    /// Next, iterate thru the categoryIdList and remove categories with that id.
    foreach(QString categoryId, categoryIdList)
    {
        /// If Category is used in a transaction, DO NOT REMOVE THE CATEGORY.
        QList<TransactionDTO> matchedTransactionList = transactionDAO->GetTransactionsByCategoryId(categoryId);
        if(matchedTransactionList.count() <= 0)
        {
            bool change = categoryDAO->RemoveCategory(categoryId);
            if(change)
            {
                changesMade = true;
            }
        }
        else
        {
            //Let the user know that the category is in use
            QString transactionDetails = "";
            foreach(TransactionDTO transaction, matchedTransactionList)
            {
                transactionDetails.append("    " + transaction.date.toString("MM/dd/yyyy") + " - " +
                                          QString::number(transaction.amount, 'f', 2) + " - " +
                                          TransactionTypeHelper::ToString(transaction.transactionType) + " - " +
                                          categoryDAO->GetCategoryById(transaction.categoryId).description + " - " +
                                          transaction.comment + "\n");
            }

            QMessageBox::information(0, "Category Is In Use",
                                     "Cannot remove category '" + categoryDAO->GetCategoryById(categoryId).description + "\'." + "\n" +
                                     "Category is being used in these transactions:" +
                                     "\n" + transactionDetails);
        }
    }

    if(changesMade)
    {
        MarkDirty();
    }
    LoadDataToView();
}

QList<QString> EditCategoriesPresenter::GetSelectedCategoriesIds()
{
    /// Get the selected indexes
    QModelIndexList indexList = ui->tableView->selectionModel()->selectedIndexes();

    /// Get all the categoryIds (contained in column zero) and put them into a list.
    QList<QString> categoryIdList;
    foreach(QModelIndex index, indexList)
    {
        QString categoryId = ui->tableView->model()->
                                data(ui->tableView->model()->index(index.row(), 0/*column zero*/))
                                .toString();
        /// Only append the categoryId if it's unique
        if(!categoryIdList.contains(categoryId))
        {
            categoryIdList.append(categoryId);
        }
    }
    return categoryIdList;
}
