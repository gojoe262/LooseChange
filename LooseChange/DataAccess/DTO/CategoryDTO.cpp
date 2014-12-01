#include "CategoryDTO.h"

CategoryDTO::CategoryDTO()
{
}

CategoryDTO::CategoryDTO(QString inCategory)
{
    category = inCategory;
}

QString CategoryDTO::ToString()
{
    return category;
}

