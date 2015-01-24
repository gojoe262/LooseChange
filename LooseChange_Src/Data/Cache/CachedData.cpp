#include "CachedData.h"

#include <Data/FileAccess/FileReader.h>
#include <Data/FileAccess/FileWriter.h>

CachedData::CachedData(QObject *parent) :
    QObject(parent)
{
}

CachedData::CachedData(const CachedData &other)
{
    this->operator =(other);
}

CachedData::~CachedData()
{
    transactionList.clear();
    categoryList.clear();
}

void CachedData::ReadFile(QString fileLocation)
{
    FileReader reader;
    transactionList.clear();
    categoryList.clear();
    reader.ReadFile(fileLocation, transactionList, categoryList);

    emit MarkClean();
}

void CachedData::WriteFile(QString fileLocation)
{
    FileWriter writer;
    writer.WriteFile(transactionList, categoryList,fileLocation);
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

bool CachedData::UpdateTransactionAmount(int id, double amount)
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
    return changesMade;
}

bool CachedData::UpdateTransactionDate(int id, QDate date)
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

    return changesMade;
}

bool CachedData::UpdateTransactionType(int id, TransactionType type)
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
    return changesMade;
}

bool CachedData::UpdateTransactionComment(int id, QString comment)
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
    return changesMade;
}

bool CachedData::UpdateTransactionCategory(int id, int categoryId)
{
    bool changesMade = false;
    for(int i = 0; i < transactionList.count(); i++)
    {
        if(transactionList.at(i).id == id)
        {
            if(transactionList[i].categoryId != categoryId)
            {
                transactionList[i].categoryId = categoryId;
                changesMade = true;
            }
        }
    }
    if(changesMade)
    {
        emit MarkDirty();
    }
    return changesMade;
}

bool CachedData::UpdateCategoryDescription(int categoryId, QString categoryDescription)
{
    bool changesMade = false;
    for(int i = 0; i < categoryList.count(); i++)
    {
        if(categoryList.at(i).id == categoryId)
        {
            if(categoryList[i].description != categoryDescription)
            {
                categoryList[i].description = categoryDescription;
                changesMade = true;
            }
        }
    }
    if(changesMade)
    {
        emit MarkDirty();
    }
    return changesMade;
}

void CachedData::AddCategory(CategoryDTO inCategory)
{
    categoryList.append(inCategory);
    emit MarkDirty();
}

CachedData & CachedData::operator =(const CachedData & other)
{
    categoryList = other.categoryList;
    transactionList = other.transactionList;
    return *this;
}
