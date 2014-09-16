#ifndef CATEGORIES_H
#define CATEGORIES_H

#include <QString>

enum Category
{
    Other = 0,
    Groceries = 1,
    Shopping = 2,
    Restaurants = 3,
    GasTravel = 4,
    Phone = 5,
    Laundry = 6
};

class CategoryHelper
{
public:
    /**
     * @brief ToQString - Converts enum Category to a string.
     * @param inCategory
     * @return
     */
    static QString ToQString(Category inCategory);
};

#endif // CATEGORIES_H
