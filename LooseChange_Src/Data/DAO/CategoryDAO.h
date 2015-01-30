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
    CategoryDTO GetCategoryById(QString inCategoryId);

    /**
     * @brief UpdateDescription
     * @param categorDescription
     * @return
     */
    bool UpdateDescription(QString categoryId, QString categoryDescription);

private:
    CachedData *cachedDataPointer;  
};




class CategoryNotFoundException
{
public :
    CategoryNotFoundException()
    {
        categoryId = "";
    }
    CategoryNotFoundException(QString inCategoryId)
    {
        categoryId = inCategoryId;
    }


    QString Message()
    {
        if(categoryId != "")
        {
            return "Category Not Found! Category: " + categoryId + ".";
        }
        return "Category Not Found!";
    }
private:
    QString categoryId;
};

#endif // CATEGORYDAO_H
