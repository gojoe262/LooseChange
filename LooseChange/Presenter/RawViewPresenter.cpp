#include "RawViewPresenter.h"

#include <QInputDialog>

RawViewPresenter::RawViewPresenter()
{
}

RawViewPresenter::RawViewPresenter(QTableView *inTableView, CachedData *inCachedDataPointer, QWidget *parent) :
    QObject(parent)
{
    //Initialize DAOs
    transactionDAO = new TransactionDAO(inCachedDataPointer);
    categoryDAO = new CategoryDAO(inCachedDataPointer);

    //Initialize Model
    model = new RawViewTableModel(transactionDAO, categoryDAO, this);

    tableView = inTableView;
    tableView->setModel(model);

    dateEdit = new DateEditDelegate(this);
    doubleSpinBox = new DoubleSpinBoxDelegate(this);
    transactionTypeComboBox = new TransactionTypeComboBoxDelegate(this);
    categoryComboBox = new CategoryComboBoxDelegate(categoryDAO, this);
    commentLineEdit = new CommentLineEditDelegate(this);

    tableView->setItemDelegateForColumn(1, dateEdit);
    tableView->setItemDelegateForColumn(2, doubleSpinBox);
    tableView->setItemDelegateForColumn(3, transactionTypeComboBox);
    tableView->setItemDelegateForColumn(4, categoryComboBox);
    tableView->setItemDelegateForColumn(5, commentLineEdit);

    Load();




}

RawViewPresenter::~RawViewPresenter()
{
    delete transactionDAO;
    delete categoryDAO;
}


void RawViewPresenter::Load()
{
    model->Refresh();


    {
//    DateEditDelegate *dateEdit = new DateEditDelegate(this);
//    DoubleSpinBoxDelegate *doubleSpinBox = new DoubleSpinBoxDelegate(this);
//    TransactionTypeComboBoxDelegate *transactionTypeComboBox = new TransactionTypeComboBoxDelegate(this);
//    CategoryComboBoxDelegate *categoryComboBox = new CategoryComboBoxDelegate(categoryDAO, this);
//    CommentLineEditDelegate *commentLineEdit = new CommentLineEditDelegate(this);

//    table->setItemDelegateForColumn(1, dateEdit);
//    table->setItemDelegateForColumn(2, doubleSpinBox);
//    table->setItemDelegateForColumn(3, transactionTypeComboBox);
//    table->setItemDelegateForColumn(4, categoryComboBox);
//    table->setItemDelegateForColumn(5, commentLineEdit);



//    QList<TransactionDTO> transactionList = transactionDAO->GetTransactionList();
//    int count = transactionList.count();

//    table->clear();
//    table->setColumnCount(6);
//    table->setRowCount(count);




//    QObject::connect(dateEdit, SIGNAL(ValueChanged(QModelIndex,QDate)), this, SLOT(ChangeDate(QModelIndex,QDate)));
//    QObject::connect(doubleSpinBox, SIGNAL(ValueChanged(QModelIndex,double)), this, SLOT(ChangeAmount(QModelIndex,double)));
//    QObject::connect(transactionTypeComboBox, SIGNAL(ValueChanged(QModelIndex,TransactionType)), this, SLOT(ChangeTransactionType(QModelIndex,TransactionType)));
//    QObject::connect(categoryComboBox, SIGNAL(ValueChanged(QModelIndex,int)), this, SLOT(ChangeCategory(QModelIndex,int)));
//    QObject::connect(categoryComboBox, SIGNAL(AddCategoryRequested(QModelIndex)), this, SLOT(AddCategory(QModelIndex)));
//    QObject::connect(commentLineEdit, SIGNAL(ValueChanged(QModelIndex,QString)), this, SLOT(ChangeComment(QModelIndex,QString)));



//    ///ui->tableWidgetRawView->verticalHeaderItem(i)->setText(QString::number(dto.id));
//    for(int i = 0; i < count; i++)
//    {
//        TransactionDTO transactionDTO = transactionList.at(i);
//        QModelIndex index;
//        /// Column 0 - ID
//        table->setItem(i,0,new QTableWidgetItem(QString::number(transactionDTO.id)));

//        /// Column 1 - DATE
//        index = table->model()->index(i, 1, QModelIndex());
//        table->model()->setData(index, QVariant(transactionDTO.date));

//        /// Column 2 - AMOUNT
//        index = table->model()->index(i, 2, QModelIndex());
//        table->model()->setData(index, QVariant(transactionDTO.amount));

//        /// Column 3 - TRANSACTION TYPE
//        index = table->model()->index(i, 3, QModelIndex());
//        table->model()->setData(index, QVariant(TransactionTypeHelper::ToString(transactionDTO.transactionType)));

//        /// Column 4 - CATEGORY
//        index = table->model()->index(i, 4, QModelIndex());
//        table->model()->setData(index, QVariant(categoryDAO->GetDescription(transactionDTO.categoryId)));

//        /// Column 5 - COMMENT
//        index = table->model()->index(i, 5, QModelIndex());
//        table->model()->setData(index, QVariant(transactionDTO.comment));
//    }
    //table->hideColumn(0);
    //table->sortItems(1);
    //table->resizeColumnsToContents();
    }
}

int RawViewPresenter::GetIdFromModelIndex(QModelIndex index) const
{
   return table->model()->data(table->model()->index(index.row(),0)).toInt();
}

void RawViewPresenter::ChangeAmount(QModelIndex index, double amount)
{ 
    transactionDAO->UpdateAmount(GetIdFromModelIndex(index), amount);
}

void RawViewPresenter::ChangeDate(QModelIndex index, QDate date)
{
    transactionDAO->UpdateDate(GetIdFromModelIndex(index), date);
}

void RawViewPresenter::ChangeTransactionType(QModelIndex index, TransactionType type)
{
    transactionDAO->UpdateType(GetIdFromModelIndex(index), type);
}

void RawViewPresenter::ChangeComment(QModelIndex index, QString comment)
{
    transactionDAO->UpdateComment(GetIdFromModelIndex(index), comment);
}

void RawViewPresenter::ChangeCategory(QModelIndex index, int categoryId)
{
    transactionDAO->UpdateCategory(GetIdFromModelIndex(index), categoryId);
}

void RawViewPresenter::AddCategory(QModelIndex index)
{
    bool ok;
    QString categoryDescription = QInputDialog::getText(table, tr("Add New Category"),
                                              tr("Category:"), QLineEdit::Normal,
                                              QString(), &ok);
    if(ok && !categoryDescription.trimmed().isEmpty())
    {
        categoryDAO->AddCategory(categoryDescription);
    }
}
