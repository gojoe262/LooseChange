#ifndef CATEGORYDAOTEST_H
#define CATEGORYDAOTEST_H

#include <Test/TestBase.h>
#include <Data/DAO/CategoryDAO.h>

class CategoryDAOTest : TestBase
{
public:
    CategoryDAOTest();

    void RunTests();
private:
    /// Test GetCategories
    void TestGetCategories_NonEmptyList();
    void TestGetCategories_EmptyList();

    /// Test GetCategoryById
    void TestGetCategoryById_HasMatch();
    void TestGetCategoryById_NoMatch();
    void TestGetCategoryById_EmptyList();

    /// Test UpdateDescription
    void TestUpdateDescription_ChangeMade();
    void TestUpdateDescription_NoChangeMade();

    /// Test AddCategory
    void TestAddCategory();

    /// Test RemoveCategory
    void TestRemoveCategory_ChangeMade();
    void TestRemoveCategory_NoChangeMadeNotFound();
    void TestRemoveCategory_EmptyList();


};

#endif // CATEGORYDAOTEST_H
