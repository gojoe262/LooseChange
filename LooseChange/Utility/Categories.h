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

class CategoryLookup
{
public:
    CategoryLookup(){}

//    QString Description(Category inCategory)
//    {
//        switch(inCategory)
//        {
//            case Category::Other:
//                return "Other";
//            case Category::Groceries:
//                return "Groceries";
//            case Category::Shopping:
//                return "Shopping";
//            default:
//                return "Other";
//            // todo implement rest
//        }
//    }

};


#endif // CATEGORIES_H
