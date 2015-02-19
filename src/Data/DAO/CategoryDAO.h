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

    /**
     * @brief AddCategory
     * Adds a category to the categoryList in cachedDataPointer
     */
    void AddCategory();

    /**
     * @brief RemoveCategory
     * @param categoryId
     * @return return true if removed, false otherwise
     */
    bool RemoveCategory(QString categoryId);

    /**
     * @brief SortCategories
     * @param order
     * @return
     */
    void SortCategories(Qt::SortOrder order = Qt::AscendingOrder);

private:
    /**
     * @brief IsLessThanByDate - Compares the categoryDTOs by date.
     * @param t1
     * @param t2
     * @return True if c1.description is less than c2.description, otherwise false.
     */
    static bool IsLessThanByDescription(const CategoryDTO& c1, const CategoryDTO& c2);
    static bool IsGreaterThanByDescription(const CategoryDTO& c1, const CategoryDTO& c2);

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
