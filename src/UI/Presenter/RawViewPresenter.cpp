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

    //Set Model for tableView
    ui->tableView->setModel(model);
    ui->tableView->setSortingEnabled(true);
    //ui->tableView->sortByColumn(0);

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
    RetriveAndLoadCachedData();
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

void RawViewPresenter::RetriveAndLoadCachedData()
{
    model->Refresh();
}

void RawViewPresenter::MarkDirty()
{
    emit DataChanged();
}
