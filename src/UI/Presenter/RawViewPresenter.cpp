#include "RawViewPresenter.h"
#include "ui_RawViewPresenter.h"

RawViewPresenter::RawViewPresenter(CachedData *inCachedDataPointer, QWidget *parent) :
    QWidget(parent),
    ui(new Ui::RawViewPresenter)
{
    //Sets up UI
    ui->setupUi(this);

    //Initialize DAOs
    transactionDAO = new TransactionDAO(inCachedDataPointer);
    categoryDAO = new CategoryDAO(inCachedDataPointer);

    //Initialize Model
    model = new RawViewTableModel(transactionDAO, categoryDAO, this);

    connect(model, SIGNAL(dataChanged(QModelIndex,QModelIndex)), this, SLOT(MarkDirty()));

    //Set Model for tableView and allow sorting.
    ui->tableView->setModel(model);
    ui->tableView->setSortingEnabled(true);

    //Initialize Delegates
    dateEdit = new DateEditDelegate(this);
    doubleSpinBox = new DoubleSpinBoxDelegate(this);
    transactionTypeComboBox = new TransactionTypeComboBoxDelegate(this);
    categoryComboBox = new CategoryComboBoxDelegate(categoryDAO, this);
    commentLineEdit = new CommentLineEditDelegate(this);

    //Set Delegates for each column
    ui->tableView->setItemDelegateForColumn(1, dateEdit);
    ui->tableView->setItemDelegateForColumn(2, doubleSpinBox);
    ui->tableView->setItemDelegateForColumn(3, transactionTypeComboBox);
    ui->tableView->setItemDelegateForColumn(4, categoryComboBox);
    ui->tableView->setItemDelegateForColumn(5, commentLineEdit);

    //Hide the ID column
    ui->tableView->hideColumn(0);

    //Load cached data from the model to the table view
    Refresh();
}

RawViewPresenter::~RawViewPresenter()
{
    delete transactionDAO;
    delete categoryDAO;
    delete model;
    delete dateEdit;
    delete doubleSpinBox;
    delete transactionTypeComboBox;
    delete categoryComboBox;
    delete commentLineEdit;

    delete ui;
}

void RawViewPresenter::Refresh()
{
    model->Refresh();
}

void RawViewPresenter::MarkDirty()
{
    emit DataChanged();
}

void RawViewPresenter::on_pushButtonAddTransaction_clicked()
{
    transactionDAO->AddTransaction(QDate::currentDate(), 00.00, OUT_TRANSACTION, "", "");
    model->Refresh();
    ui->tableView->scrollToTop();
    ui->tableView->selectRow(0);
    MarkDirty();
}

void RawViewPresenter::on_pushButtonRemoveSelectedTransactions_clicked()
{
    if(ui->tableView->selectionModel()->selectedIndexes().count() != 0)
    {
        bool changesMade = false;

        int firstSelectedRow = ui->tableView->selectionModel()->selectedIndexes().first().row();

        /// First get the selected transactionIds and put them into a list.
        QList<QString> transactionIdList = GetSelectedTransactionsIds();

        /// Next, iterate thru the transactionIdList and remove transactions with that id.
        foreach(QString transactionId, transactionIdList)
        {
            bool change = transactionDAO->RemoveTransaction(transactionId);
            if(change)
            {
                changesMade = true;
            }
        }

        if(changesMade)
        {
            MarkDirty();
        }
        Refresh();
        ui->tableView->selectRow(firstSelectedRow - 1);
    }
}

QList<QString> RawViewPresenter::GetSelectedTransactionsIds()
{
    /// Get the selected indexes
    QModelIndexList indexList = ui->tableView->selectionModel()->selectedIndexes();

    /// Get all the transactionIds (contained in column zero) and put them into a list.
    QList<QString> transactionIdList;
    foreach(QModelIndex index, indexList)
    {
        QString transactionId = ui->tableView->model()->
                                data(ui->tableView->model()->index(index.row(), 0/*column zero*/))
                                .toString();
        /// Only append the transactionId if it's unique
        if(!transactionIdList.contains(transactionId))
        {
            transactionIdList.append(transactionId);
        }
    }
    return transactionIdList;
}
