#include "RawViewPresenter.h"

#include <QInputDialog>

RawViewPresenter::RawViewPresenter(QTableView *inTableView, CachedData *inCachedDataPointer, QWidget *parent) :
    QObject(parent)
{
    //Initialize DAOs
    transactionDAO = new TransactionDAO(inCachedDataPointer);
    categoryDAO = new CategoryDAO(inCachedDataPointer);

    //Initialize Model
    model = new RawViewTableModel(transactionDAO, categoryDAO, this);

    //Set Model for tableView
    tableView = inTableView;
    tableView->setModel(model);

    //Initialize Delegates
    dateEdit = new DateEditDelegate(this);
    doubleSpinBox = new DoubleSpinBoxDelegate(this);
    transactionTypeComboBox = new TransactionTypeComboBoxDelegate(this);
    categoryComboBox = new CategoryComboBoxDelegate(categoryDAO, this);
    commentLineEdit = new CommentLineEditDelegate(this);

    //Set Delegates for each column
    tableView->setItemDelegateForColumn(1, dateEdit);
    tableView->setItemDelegateForColumn(2, doubleSpinBox);
    tableView->setItemDelegateForColumn(3, transactionTypeComboBox);
    tableView->setItemDelegateForColumn(4, categoryComboBox);
    tableView->setItemDelegateForColumn(5, commentLineEdit);

    //Hide the ID column
    tableView->hideColumn(0);

    //Load cached data from the model to the table view
    Load();
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

    //Table View is not delete because it is a GUI Element
}


void RawViewPresenter::Load()
{
    model->Refresh();
}


