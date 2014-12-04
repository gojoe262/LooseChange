#ifndef CATEGORYDAO_H
#define CATEGORYDAO_H

#include <Data/Objects/TransactionDTO.h>
#include <Data/Objects/CategoryDTO.h>
#include <Data/Cache/CachedData.h>

class CategoryDAO
{
public:
    CategoryDAO();
    CategoryDAO(CachedData *inCachedDataPointer);
    ~CategoryDAO();

    QList<CategoryDTO> GetCategories();

private:
    CachedData *cachedDataPointer;
};

#endif // CATEGORYDAO_H
