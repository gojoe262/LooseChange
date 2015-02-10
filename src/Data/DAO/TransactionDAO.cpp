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

//TransactionDAO::TransactionDAO()
//{
//}

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
    QList<TransactionDTO> *transactionList = &(cachedDataPointer->transactionList);
    bool changesMade = false;
    for(int i = 0; i < transactionList->count(); i++)
    {
        if(transactionList->at(i).id == id)
        {
            if(transactionList->at(i).amount != amount)
            {
                (*transactionList)[i].amount = amount;
                changesMade = true;
            }
        }
    }
    return changesMade;
}

bool TransactionDAO::UpdateDate(QString id, QDate date)
{
    QList<TransactionDTO> *transactionList = &(cachedDataPointer->transactionList);
    bool changesMade = false;
    for(int i = 0; i < transactionList->count(); i++)
    {
        if(transactionList->at(i).id == id)
        {
            if(transactionList->at(i).date != date)
            {
                (*transactionList)[i].date = date;
                changesMade = true;
            }
        }
    }
    return changesMade;
}

bool TransactionDAO::UpdateType(QString id, TransactionType type)
{
    QList<TransactionDTO> *transactionList = &(cachedDataPointer->transactionList);
    bool changesMade = false;
    for(int i = 0; i < transactionList->count(); i++)
    {
        if(transactionList->at(i).id == id)
        {
            if(transactionList->at(i).transactionType != type)
            {
                (*transactionList)[i].transactionType = type;
                changesMade = true;
            }
        }
    }
    return changesMade;
}

bool TransactionDAO::UpdateComment(QString id, QString comment)
{
    QList<TransactionDTO> *transactionList = &(cachedDataPointer->transactionList);
    bool changesMade = false;
    for(int i = 0; i < transactionList->count(); i++)
    {
        if(transactionList->at(i).id == id)
        {
            if(transactionList->at(i).comment != comment)
            {
                (*transactionList)[i].comment = comment;
                changesMade = true;
            }
        }
    }
    return changesMade;
}

bool TransactionDAO::UpdateCategory(QString id, QString categoryId)
{
    QList<TransactionDTO> *transactionList = &(cachedDataPointer->transactionList);
    bool changesMade = false;
    for(int i = 0; i < transactionList->count(); i++)
    {
        if(transactionList->at(i).id == id)
        {
            if(transactionList->at(i).categoryId != categoryId)
            {
                (*transactionList)[i].categoryId = categoryId;
                changesMade = true;
            }
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
