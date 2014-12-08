#ifndef CATEGORYDTO_H
#define CATEGORYDTO_H

#include <QString>

class CategoryDTO
{
public:
    CategoryDTO();

    CategoryDTO(QString inCategory);

    QString ToString();

    QString category;
};

#endif // CATEGORYDTO_H
