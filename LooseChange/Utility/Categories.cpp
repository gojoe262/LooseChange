#include <Utility/Categories.h>

Category::Category()
{
}

Category::Category(int inCategoryCode)
{
    categoryCode = inCategoryCode;
}


QString Category::Description()
{
    if(categoryCode != null)
    {
        switch (categoryCode)
        {
            case 0:
                return "Other";
            case 1:
                return "Groceries";
            case 2:
                return "Shopping";
            case 3:
                return "Restaurants";
            case 4:
                return "Gas/Travel";
            case 5:
                return "Phone";
            case 6:
                return "Laundry";
            default:
                return "";
        }
    }
    return "";
}
