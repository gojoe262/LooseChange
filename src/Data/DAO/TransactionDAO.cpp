#include "TransactionDAO.h"

#include <QTextStream>
#include <QStringList>
#include <QFileDialog>
#include <QObject>
#include <QFile>
#include <Utility/TransactionType.h>
#include <Data/FileAccess/FileReader.h>
#include <Data/FileAccess/FileWriter.h>
#include <QMessageBox>

TransactionDAO::TransactionDAO(CachedData *inCachedDataPointer, QWidget *parent) : QObject(parent)
{
    cachedDataPointer = inCachedDataPointer;
}

TransactionDAO::~TransactionDAO()
{
    //cachedDataPointer to be deleted elsewhere because it is passed in.
}

QList<TransactionDTO> TransactionDAO::GetTransactionList()
{
    return cachedDataPointer->transactionList;
}

bool TransactionDAO::UpdateAmount(QString id, double amount)
{
    TransactionDTO *transaction = FindTransactionById(id);
    bool changesMade = false;
    if(transaction != NULL)
    {
        if(transaction->amount != amount)
        {
            transaction->amount = amount;
            changesMade = true;
        }
    }
    return changesMade;
}

bool TransactionDAO::UpdateDate(QString id, QDate date)
{
    TransactionDTO *transaction = FindTransactionById(id);
    bool changesMade = false;
    if(transaction != NULL)
    {
        if(transaction->date != date)
        {
            transaction->date = date;
            changesMade = true;
        }
    }
    return changesMade;
}

bool TransactionDAO::UpdateType(QString id, TransactionType type)
{
    TransactionDTO *transaction = FindTransactionById(id);
    bool changesMade = false;
    if(transaction != NULL)
    {
        if(transaction->transactionType != type)
        {
            transaction->transactionType = type;
            changesMade = true;
        }
    }
    return changesMade;
}

bool TransactionDAO::UpdateComment(QString id, QString comment)
{
    TransactionDTO *transaction = FindTransactionById(id);
    bool changesMade = false;
    if(transaction != NULL)
    {
        if(transaction->comment != comment)
        {
            transaction->comment = comment;
            changesMade = true;
        }
    }
    return changesMade;
}

bool TransactionDAO::UpdateCategory(QString id, QString categoryId)
{
    TransactionDTO *transaction = FindTransactionById(id);
    bool changesMade = false;
    if(transaction != NULL)
    {
        if(transaction->categoryId != categoryId)
        {
            transaction->categoryId = categoryId;
            changesMade = true;
        }
    }
    return changesMade;
}

QList<TransactionDTO> TransactionDAO::GetTransactionsByCategoryId(QString categoryId)
{
    QList<TransactionDTO> transactionList = cachedDataPointer->transactionList;
    QList<TransactionDTO> retTransactionList;
    foreach(TransactionDTO transaction, transactionList)
    {
        if(transaction.categoryId == categoryId)
        {
            retTransactionList.append(transaction);
        }
    }
    return retTransactionList;
}

TransactionDTO* TransactionDAO::FindTransactionById(QString id)
{
    QList<TransactionDTO> *transactionList = &(cachedDataPointer->transactionList);
    for(int i = 0; i < transactionList->count(); i++)
    {
        if(transactionList->at(i).id == id)
        {
            return &(*transactionList)[i];
        }
    }
    return NULL;
}

void TransactionDAO::SortTransactionListByDate(Qt::SortOrder order)
{
    if(order == Qt::AscendingOrder)
    {
        qSort(cachedDataPointer->transactionList.begin(),
              cachedDataPointer->transactionList.end(),
              TransactionDTO::IsLessThanByDate);
    }
    else if(order == Qt::DescendingOrder)
    {
        qSort(cachedDataPointer->transactionList.begin(),
              cachedDataPointer->transactionList.end(),
              TransactionDTO::IsGreaterThanByDate);
    }
}
