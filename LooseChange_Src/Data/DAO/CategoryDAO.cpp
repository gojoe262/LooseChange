#include "CategoryDAO.h"
#include <Utility/UniqueKeyGenerator.h>

CategoryDAO::CategoryDAO()
{
}

CategoryDAO::CategoryDAO(CachedData *inCachedDataPointer)
{
    cachedDataPointer = inCachedDataPointer;
}

CategoryDAO::~CategoryDAO()
{
    //cachedDataPointer to be deleted elsewhere because it is passed in.
}

QList<CategoryDTO> CategoryDAO::GetCategories()
{
    return cachedDataPointer->GetCategoryList();
}

CategoryDTO CategoryDAO::GetCategory(QString inCategoryId)
{
    QList<CategoryDTO> categoryList = cachedDataPointer->GetCategoryList();
    foreach(CategoryDTO category, categoryList)
    {
        if(category.id == inCategoryId)
        {
            return category;
        }
    }
    throw CategoryNotFoundException(inCategoryId);
}

bool CategoryDAO::UpdateDescription(QString categoryId, QString categoryDescription)
{
    return cachedDataPointer->UpdateCategoryDescription(categoryId, categoryDescription);
}

bool CategoryDAO::IsUniqueCategory(QString categoryDescription)
{
    QList<CategoryDTO> categoryList = cachedDataPointer->GetCategoryList();
    foreach(CategoryDTO category, categoryList)
    {
        if(category.description == categoryDescription)
        {
            return false;
        }
    }
    return true;
}
