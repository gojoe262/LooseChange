#include "CachedData.h"

CachedData::CachedData()
{
}

CachedData::CachedData(const CachedData &other)
{
    this->operator =(other);
}

void CachedData::Clear()
{
    transactionList.clear();
    categoryList.clear();
}

CachedData::~CachedData()
{
    Clear();
}

CachedData & CachedData::operator =(const CachedData & other)
{
    categoryList = other.categoryList;
    transactionList = other.transactionList;
    return *this;
}
