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
     * @brief GetCategory
     * @param inCategoryId
     * @return
     */
    CategoryDTO GetCategory(int inCategoryId);

    /**
     * @brief AddCategory
     * @param categoryDescription
     */
    void AddCategory(QString categoryDescription);

    /**
     * @brief UpdateDescription
     * @param categorDescription
     * @return
     */
    bool UpdateDescription(int categoryId, QString categoryDescription);

    /**
     * @brief IsUniqueCategory
     * @param categoryDescription
     * @return
     */
    bool IsUniqueCategory(QString categoryDescription);

    /**
     * @brief GetCategoryId
     * @param categoryDescription
     * @return
     */
    int GetCategoryId(QString categoryDescription);

    /**
     * @brief GetNextId
     * @return
     */
    int GetNextId();

    /**
     * @brief GetDescription
     * @param categoryId
     * @return
     */
    QString GetDescription(int categoryId);

    /**
     * @brief Count
     * @return
     */
    int Count();

private:
    CachedData *cachedDataPointer;
};

#endif // CATEGORYDAO_H
