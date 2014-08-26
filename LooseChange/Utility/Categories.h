#ifndef CATEGORIES_H
#define CATEGORIES_H

#include <QString>

class Category
{
public:
    Category();
    Category(int inCategoryCode);

    QString Description();


private:
    int categoryCode;

};

#endif // CATEGORIES_H
