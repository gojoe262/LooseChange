#ifndef CACHEDDATA_H
#define CACHEDDATA_H

#include <Data/DTO/TransactionDTO.h>
#include <Data/DTO/CategoryDTO.h>


class CachedData
{
public:
    CachedData();
    CachedData(const CachedData & other);
    ~CachedData();

    CachedData & operator =(const CachedData & other);

    void Clear();

    QList<TransactionDTO>   transactionList;
    QList<CategoryDTO>      categoryList;
};

#endif // CACHEDDDATA_H
