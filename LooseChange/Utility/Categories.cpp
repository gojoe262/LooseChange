#include <Utility/Categories.h>


QString CategoryHelper::ToQString(Category inCategory)
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

//Category CategoryHelper::FromString(QString inCategoryStr)
//{
//    switch (inCategoryStr)
//    {
//        case "Other":
//            return Other;
//        case "Groceries":
//            return Groceries;
//        case "Shopping":
//            return Shopping;
//        case "Restaurants":
//            return Restaurants;
//        case "Gas/Travel":
//            return GasTravel;
//        case "Phone":
//            return Phone;
//        case "Laundry":
//            return Laundry;
//        default:
//            return Other;
//    }
//}
