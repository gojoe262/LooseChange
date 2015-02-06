#ifndef CATEGORYDAOTEST_H
#define CATEGORYDAOTEST_H

#include <Test/TestBase.h>
#include <Data/DAO/CategoryDAO.h>

class CategoryDAOTest : TestBase
{
public:
    CategoryDAOTest();
    ~CategoryDAOTest();

    void RunTests();
private:
    /// Test GetCategories
    bool TestGetCategoriesNonEmptyList();
    bool TestGetCategoriesEmptyList();

    /// Test GetCategoryById
    bool TestGetCategoryByIdHasMatch();
    bool TestGetCategoryByIdNoMatch();
    bool TestGetCategoryByIdEmptyList();

    /// Test UpdateDescription
    bool TestUpdateDescriptionChangeMade();
    bool TestUpdateDescriptionNoChangeMade();

    /// Test AddCategory
    bool TestAddCategory();

    /// Test RemoveCategory
    bool TestRemoveCategoryChangeMade();
    bool TestRemoveCategoryNoChangeMadeNotFound();
    bool TestRemoveCategoryEmptyList();


};

#endif // CATEGORYDAOTEST_H
