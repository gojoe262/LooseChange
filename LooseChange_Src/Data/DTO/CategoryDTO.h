#ifndef CATEGORYDTO_H
#define CATEGORYDTO_H

#include <QString>

class CategoryDTO
{
public:
    CategoryDTO();

    CategoryDTO(int inId, QString inDescription);

    /**
     * @brief id - Unique id for a category
     */
    int     id;

    /**
     * @brief description - The category description string
     */
    QString description;

};

#endif // CATEGORYDTO_H
