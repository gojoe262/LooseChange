#ifndef CATEGORIES_H
#define CATEGORIES_H

#include <QString>


//Maybe iterate through the list of categories by number. Would need refactoring in
//usages. By doing this, categories can be read in, edited and saved to the file.
//Maybe it would be best to create a category list Class. This will suffice for now though.
//See Trello - "Create CategoryList Class"

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
    static QString ToString(Category inCategory);

    static Category FromString(QString inCategoryStr);
};

#endif // CATEGORIES_H
