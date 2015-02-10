#include "CachedData.h"

#include <Data/FileAccess/FileReader.h>
#include <Data/FileAccess/FileWriter.h>


CachedData::CachedData(QObject *parent) :
    QObject(parent)
{
}

CachedData::CachedData(const CachedData &other):
    QObject(0)
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

CachedData & CachedData::operator =(const CachedData & other)
{
    categoryList = other.categoryList;
    transactionList = other.transactionList;
    return *this;
}
