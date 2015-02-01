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
    return cachedDataPointer->categoryList;
}

CategoryDTO CategoryDAO::GetCategoryById(QString inCategoryId)
{
    QList<CategoryDTO> categoryList = cachedDataPointer->categoryList;
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
    QList<CategoryDTO> *categoryList = &(cachedDataPointer->categoryList);
    bool changesMade = false;
    for(int i = 0; i < categoryList->count(); i++)
    {
        if(categoryList->at(i).id == categoryId)
        {
            if(categoryList->at(i).description != categoryDescription)
            {
                (*categoryList)[i].description = categoryDescription;
                changesMade = true;
            }
        }
    }
    return changesMade;
}

void CategoryDAO::AddCategory()
{
    QList<CategoryDTO> *categoryList = &(cachedDataPointer->categoryList);
    UniqueKeyGenerator generator;
    QList<QString> prevUsedIds;
    foreach(CategoryDTO category, cachedDataPointer->categoryList)
    {
        prevUsedIds.append(category.id);
    }

    categoryList->append(CategoryDTO(generator.GenerateUniqueKey(prevUsedIds), "New Category"));
}

bool CategoryDAO::RemoveCategory(QString categoryId)
{
    QList<CategoryDTO> *categoryList = &(cachedDataPointer->categoryList);
    bool changesMade = false;
    for(int i = 0; i < categoryList->count(); i++)
    {
        if(categoryList->at(i).id == categoryId)
        {
            categoryList->removeAt(i);
            changesMade = true;
        }
    }
    return changesMade;
}
