#include "CachedData.h"

#include <Data/FileAccess/FileReader.h>
#include <Data/FileAccess/FileWriter.h>

CachedData::CachedData(QObject *parent) :
    QObject(parent)
{
}

CachedData::~CachedData()
{
    transactionList.clear();
}

void CachedData::ReadFile(QString fileLocation)
{
    FileReader reader;
    transactionList.clear();
    categoryList.clear();
    transactionList = reader.ReadFile(fileLocation);

    emit MarkClean();
}

void CachedData::WriteFile(QString fileLocation)
{
    FileWriter writer;
    writer.WriteFile(transactionList, fileLocation);
    emit MarkClean();
}

QList<TransactionDTO> CachedData::GetTransactionList()
{
    return transactionList;
}

QList<CategoryDTO> CachedData::GetCategoryList()
{
    return categoryList;
}

void CachedData::AddTransaction(TransactionDTO inTransactionDTO)
{
    transactionList.append(inTransactionDTO);
    emit MarkDirty();
}

void CachedData::UpdateTransactionAmount(int id, double amount)
{
    bool changesMade = false;
    for(int i = 0; i < transactionList.count(); i++)
    {
        if(transactionList.at(i).id == id)
        {
            if(transactionList[i].amount != amount)
            {
                transactionList[i].amount = amount;
                changesMade = true;
            }
        }
    }
    if(changesMade)
    {
        emit MarkDirty();
    }
}

void CachedData::UpdateTransactionDate(int id, QDate date)
{
    bool changesMade = false;
    for(int i = 0; i < transactionList.count(); i++)
    {
        if(transactionList.at(i).id == id)
        {
            if(transactionList[i].date != date)
            {
                transactionList[i].date = date;
                changesMade = true;
            }
        }
    }
    if(changesMade)
    {
        emit MarkDirty();
    }
}

void CachedData::UpdateTransactionType(int id, TransactionType type)
{
    bool changesMade = false;
    for(int i = 0; i < transactionList.count(); i++)
    {
        if(transactionList.at(i).id == id)
        {
            if(transactionList[i].transactionType != type)
            {
                transactionList[i].transactionType = type;
                changesMade = true;
            }
        }
    }
    if(changesMade)
    {
        emit MarkDirty();
    }
}

void CachedData::UpdateTransactionComment(int id, QString comment)
{
    bool changesMade = false;
    for(int i = 0; i < transactionList.count(); i++)
    {
        if(transactionList.at(i).id == id)
        {
            if(transactionList[i].comment != comment)
            {
                transactionList[i].comment = comment;
                changesMade = true;
            }
        }
    }
    if(changesMade)
    {
        emit MarkDirty();
    }
}
