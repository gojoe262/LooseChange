#include "TransactionDAO.h"

#include <QTextStream>
#include <QStringList>
#include <QFileDialog>
#include <QObject>
#include <QFile>
#include <Utility/TransactionType.h>
#include <Data/DAO/CategoryDAO.h>
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

bool TransactionDAO::IsLessThanByDate(const TransactionDTO &t1, const TransactionDTO &t2)
{
    return t1.date < t2.date;
}

bool TransactionDAO::IsGreaterThanByDate(const TransactionDTO &t1, const TransactionDTO &t2)
{
    return t1.date > t2.date;
}

bool TransactionDAO::IsLessThanByAmount(const TransactionDTO &t1, const TransactionDTO &t2)
{
    return t1.amount < t2.amount;
}

bool TransactionDAO::IsGreaterThanByAmount(const TransactionDTO &t1, const TransactionDTO &t2)
{
    return t1.amount > t2.amount;
}

bool TransactionDAO::IsLessThanByTransactionType(const TransactionDTO &t1, const TransactionDTO &t2)
{
    return ((int) t1.transactionType) < ((int) t2.transactionType);
}

bool TransactionDAO::IsGreaterThanByTransactionType(const TransactionDTO &t1, const TransactionDTO &t2)
{
    return ((int) t1.transactionType) > ((int) t2.transactionType);
}

bool TransactionDAO::IsLessThanByCategory(const TransactionDTO &t1, const TransactionDTO &t2)
{
    CategoryDAO *c = new CategoryDAO(cachedDataPointer);
    QString str1 = c->GetCategoryById(t1.categoryId).description;
    QString str2 = c->GetCategoryById(t2.categoryId).description;
    delete c;
    return (str1.toUpper() < str2.toUpper());
}

bool TransactionDAO::IsGreaterThanByCategory(const TransactionDTO &t1, const TransactionDTO &t2)
{
    CategoryDAO *c = new CategoryDAO(cachedDataPointer);
    QString str1 = c->GetCategoryById(t1.categoryId).description;
    QString str2 = c->GetCategoryById(t2.categoryId).description;
    delete c;
    return (str1.toUpper() > str2.toUpper());
}

void TransactionDAO::SortTransactionListByDate(Qt::SortOrder order)
{
    if(order == Qt::AscendingOrder)
    {
        qSort(cachedDataPointer->transactionList.begin(),
              cachedDataPointer->transactionList.end(),
              TransactionDAO::IsLessThanByDate);
    }
    else if(order == Qt::DescendingOrder)
    {
        qSort(cachedDataPointer->transactionList.begin(),
              cachedDataPointer->transactionList.end(),
              TransactionDAO::IsGreaterThanByDate);
    }
}

void TransactionDAO::SortTransactionListByAmount(Qt::SortOrder order)
{
    if(order == Qt::AscendingOrder)
    {
        qSort(cachedDataPointer->transactionList.begin(),
              cachedDataPointer->transactionList.end(),
              TransactionDAO::IsLessThanByAmount);
    }
    else if(order == Qt::DescendingOrder)
    {
        qSort(cachedDataPointer->transactionList.begin(),
              cachedDataPointer->transactionList.end(),
              TransactionDAO::IsGreaterThanByAmount);
    }
}

void TransactionDAO::SortTransactionListByTransactionType(Qt::SortOrder order)
{
    if(order == Qt::AscendingOrder)
    {
        qSort(cachedDataPointer->transactionList.begin(),
              cachedDataPointer->transactionList.end(),
              TransactionDAO::IsLessThanByTransactionType);
    }
    else if(order == Qt::DescendingOrder)
    {
        qSort(cachedDataPointer->transactionList.begin(),
              cachedDataPointer->transactionList.end(),
              TransactionDAO::IsGreaterThanByTransactionType);
    }
}

void TransactionDAO::SortTransactionListByCategory(Qt::SortOrder order)
{
    SortByCategory(order);
}

void TransactionDAO::SortByCategory(Qt::SortOrder order)
{
    TransactionDTO tmp;
    int i, j, minIndex;
    int n = cachedDataPointer->transactionList.size();

    for (i = 0; i < n - 1; i++)
    {
        minIndex = i;

        for (j = i + 1; j < n; j++)
        {
            if(order == Qt::DescendingOrder)
            {
                if (IsGreaterThanByCategory(cachedDataPointer->transactionList.at(j), cachedDataPointer->transactionList.at(minIndex)))
                {
                    minIndex = j;
                }
            }
            else
            {
                if (IsLessThanByCategory(cachedDataPointer->transactionList.at(j), cachedDataPointer->transactionList.at(minIndex)))
                {
                    minIndex = j;
                }
            }
        }
        if (minIndex != i)
        {
            tmp = cachedDataPointer->transactionList[i];
            cachedDataPointer->transactionList[i] = cachedDataPointer->transactionList[minIndex];
            cachedDataPointer->transactionList[minIndex] = tmp;
        }
    }
}
