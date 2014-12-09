#ifndef CATEGORYDAO_H
#define CATEGORYDAO_H

#include <Data/DTO/TransactionDTO.h>
#include <Data/DTO/CategoryDTO.h>
#include <Data/Cache/CachedData.h>

class CategoryDAO
{
public:
    CategoryDAO();
    CategoryDAO(CachedData *inCachedDataPointer);
    ~CategoryDAO();

    /**
     * @brief GetCategories
     * @return
     */
    QList<CategoryDTO> GetCategories();

    /**
     * @brief GetDescription
     * @param categoryId
     * @return
     */
    QString GetDescription(int categoryId);

    /**
     * @brief AddCategory
     * @param categoryDescription
     */
    void AddCategory(QString categoryDescription);

    /**
     * @brief GetNextId
     * @return
     */
    int GetNextId();

private:
    CachedData *cachedDataPointer;
};

#endif // CATEGORYDAO_H
