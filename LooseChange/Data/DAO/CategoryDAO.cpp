#include "CategoryDAO.h"

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

CategoryDTO CategoryDAO::GetCategory(int inCategoryId)
{
    QList<CategoryDTO> categoryList = cachedDataPointer->GetCategoryList();
    foreach(CategoryDTO category, categoryList)
    {
        if(category.id == inCategoryId)
        {
            return category;
        }
    }
}

QString CategoryDAO::GetDescription(int categoryId)
{
    QList<CategoryDTO> categoryList = cachedDataPointer->GetCategoryList();
    foreach(CategoryDTO category, categoryList)
    {
        if(category.id == categoryId)
        {
            return category.description;
        }
    }
}

void CategoryDAO::AddCategory(QString categoryDescription)
{
    cachedDataPointer->AddCategory(CategoryDTO(GetNextId(), categoryDescription));
}

int CategoryDAO::GetNextId()
{
    int maxId = -1;
    QList<CategoryDTO> categoryList = cachedDataPointer->GetCategoryList();
    foreach(CategoryDTO category, categoryList)
    {
        if(maxId < category.id)
        {
            maxId = category.id;
        }
    }
    return (maxId + 1);
}
