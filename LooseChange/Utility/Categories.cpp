#include <Utility/Categories.h>


QString CategoryHelper::ToString(Category inCategory)
{
    switch (inCategory)
    {
        case Other:
            return "Other";
        case Groceries:
            return "Groceries";
        case Shopping:
            return "Shopping";
        case Restaurants:
            return "Restaurants";
        case GasTravel:
            return "Gas/Travel";
        case Phone:
            return "Phone";
        case Laundry:
            return "Laundry";
        default:
            return "";
    }
}

Category CategoryHelper::FromString(QString inCategoryStr)
{
    if(inCategoryStr == ToString(Other))
        return Other;
    else if(inCategoryStr == ToString(Groceries))
        return Groceries;
    else if(inCategoryStr == ToString(Shopping))
        return Shopping;
    else if(inCategoryStr == ToString(Restaurants))
        return Restaurants;
    else if(inCategoryStr == ToString(GasTravel))
        return GasTravel;
    else if(inCategoryStr == ToString(Phone))
        return Phone;
    else if(inCategoryStr == ToString(Laundry))
        return Laundry;
    else
        return Other;
}
