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

bool CategoryDAO::UpdateDescription(int categoryId, QString categoryDescription)
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

int CategoryDAO::GetCategoryId(QString categoryDescription)
{
    QList<CategoryDTO> categoryList = cachedDataPointer->GetCategoryList();
    foreach(CategoryDTO category, categoryList)
    {
        if(category.description == categoryDescription)
        {
            return category.id;
        }
    }
    return -1;
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

int CategoryDAO::Count()
{
    return cachedDataPointer->GetCategoryList().count();
}
