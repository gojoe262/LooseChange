#ifndef CATEGORYDTO_H
#define CATEGORYDTO_H

#include <QString>

class CategoryDTO
{
public:
    CategoryDTO();

    CategoryDTO(QString inId, QString inDescription);

    /**
     * @brief id - Unique id for a category
     */
    QString id;

    /**
     * @brief description - The category description string
     */
    QString description;

};

#endif // CATEGORYDTO_H
