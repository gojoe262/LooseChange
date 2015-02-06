#include "CategoryDAOTest.h"

CategoryDAOTest::CategoryDAOTest()
{

}

CategoryDAOTest::~CategoryDAOTest()
{

}

void CategoryDAOTest::RunTests()
{
    bool testsPassed = true;

    /// Test GetCategories
    if(!TestGetCategoriesNonEmptyList())
    {
        PrintFailedMessage("CategoryDAOTest::TestGetCategoriesNonEmptyList()");
        testsPassed = false;
    }
    if(!TestGetCategoriesEmptyList())
    {
        PrintFailedMessage("CategoryDAOTest::TestGetCategoriesEmptyList()");
        testsPassed = false;
    }

    /// Test GetCategoryById
    if(!TestGetCategoryByIdHasMatch())
    {
        PrintFailedMessage("CategoryDAOTest::TestGetCategoryByIdHasMatch()");
        testsPassed = false;
    }
    if(!TestGetCategoryByIdNoMatch())
    {
        PrintFailedMessage("CategoryDAOTest::TestGetCategoryByIdNoMatch()");
        testsPassed = false;
    }
    if(!TestGetCategoryByIdEmptyList())
    {
        PrintFailedMessage("CategoryDAOTest::TestGetCategoryByIdEmptyList()");
        testsPassed = false;
    }

    /// Test UpdateDescription
    if(!TestUpdateDescriptionChangeMade())
    {
        PrintFailedMessage("CategoryDAOTest::TestUpdateDescriptionChangeMade()");
        testsPassed = false;
    }
    if(!TestUpdateDescriptionNoChangeMade())
    {
        PrintFailedMessage("CategoryDAOTest::TestUpdateDescriptionNoChangeMade()");
        testsPassed = false;
    }

    /// Test AddCategory
    if(!TestAddCategory())
    {
        PrintFailedMessage("CategoryDAOTest::TestAddCategory()");
        testsPassed = false;
    }

    /// Test RemoveCategory
    if (!TestRemoveCategoryChangeMade())
    {
        PrintFailedMessage("CategoryDAOTest::TestRemoveCategoryChangeMade()");
        testsPassed = false;
    }
    if (!TestRemoveCategoryNoChangeMadeNotFound())
    {
        PrintFailedMessage("CategoryDAOTest::TestRemoveCategoryNoChangeMadeNotFound()");
        testsPassed = false;
    }
    if (!TestRemoveCategoryEmptyList())
    {
        PrintFailedMessage("CategoryDAOTest::TestRemoveCategoryEmptyList()");
        testsPassed = false;
    }


    /// If all passed, display that they all passed.
    if(testsPassed)
    {
        PrintPassedMessage("CategoryDAOTest");
    }
}


bool CategoryDAOTest::TestGetCategoriesNonEmptyList()
{
    CachedData *c = new CachedData();
    c->categoryList.append(CategoryDTO("id", "Description"));
    c->categoryList.append(CategoryDTO("id2", "Description"));
    c->categoryList.append(CategoryDTO("id3", "Description"));

    CategoryDAO *dao = new CategoryDAO(c);

    return (dao->GetCategories().count() == 3);
}

bool CategoryDAOTest::TestGetCategoriesEmptyList()
{
    CachedData *c = new CachedData();
    CategoryDAO *dao = new CategoryDAO(c);

    return (dao->GetCategories().count() == 0);
}

bool CategoryDAOTest::TestGetCategoryByIdHasMatch()
{
    CachedData *c = new CachedData();
    c->categoryList.append(CategoryDTO("id", "Description"));
    c->categoryList.append(CategoryDTO("id2", "TEST Description"));
    c->categoryList.append(CategoryDTO("id3", "Description"));

    CategoryDAO *dao = new CategoryDAO(c);

    return (dao->GetCategoryById("id2").description == "TEST Description");
}

bool CategoryDAOTest::TestGetCategoryByIdNoMatch()
{
    CachedData *c = new CachedData();
    c->categoryList.append(CategoryDTO("id", "Description"));
    c->categoryList.append(CategoryDTO("id2", "TEST Description"));
    c->categoryList.append(CategoryDTO("id3", "Description"));

    CategoryDAO *dao = new CategoryDAO(c);

    try
    {
        dao->GetCategoryById("id4");
    }
    catch (CategoryNotFoundException e)
    {
        /// Should be expecting the exception
        return true;
    }
    return false;
}

bool CategoryDAOTest::TestGetCategoryByIdEmptyList()
{
    CachedData *c = new CachedData();
    CategoryDAO *dao = new CategoryDAO(c);

    try
    {
        dao->GetCategoryById("id4");
    }
    catch (CategoryNotFoundException e)
    {
        /// Should be expecting the exception
        return true;
    }
    return false;
}

bool CategoryDAOTest::TestUpdateDescriptionChangeMade()
{
    CachedData *c = new CachedData();
    c->categoryList.append(CategoryDTO("id", "Description"));
    c->categoryList.append(CategoryDTO("id2", "TEST Description"));
    c->categoryList.append(CategoryDTO("id3", "Description"));

    CategoryDAO *dao = new CategoryDAO(c);

    bool changeMade = dao->UpdateDescription("id", "New Decription 007");
    if(changeMade && c->categoryList.at(0).description == "New Decription 007")
    {
        return true;
    }
    return false;
}

bool CategoryDAOTest::TestUpdateDescriptionNoChangeMade()
{
    CachedData *c = new CachedData();
    c->categoryList.append(CategoryDTO("id", "Description"));
    c->categoryList.append(CategoryDTO("id2", "TEST Description"));
    c->categoryList.append(CategoryDTO("id3", "Description"));

    CategoryDAO *dao = new CategoryDAO(c);

    bool changeMade = dao->UpdateDescription("id", "Description");
    if(!changeMade)
    {
        return true;
    }
    return false;
}

bool CategoryDAOTest::TestAddCategory()
{
    CachedData *c = new CachedData();
    c->categoryList.append(CategoryDTO("id", "Description"));
    c->categoryList.append(CategoryDTO("id2", "TEST Description"));

    CategoryDAO *dao = new CategoryDAO(c);

    dao->AddCategory();
    if(c->categoryList.count() == 3)
    {
        return true;
    }
    return false;

}

bool CategoryDAOTest::TestRemoveCategoryChangeMade()
{
    CachedData *c = new CachedData();
    c->categoryList.append(CategoryDTO("id", "Description"));
    c->categoryList.append(CategoryDTO("id2", "TEST Description"));
    c->categoryList.append(CategoryDTO("id3", "Description"));

    CategoryDAO *dao = new CategoryDAO(c);

    bool changeMade = dao->RemoveCategory("id");
    if(changeMade && c->categoryList.count() == 2)
    {
        return true;
    }
    return false;
}

bool CategoryDAOTest::TestRemoveCategoryNoChangeMadeNotFound()
{
    CachedData *c = new CachedData();
    c->categoryList.append(CategoryDTO("id", "Description"));
    c->categoryList.append(CategoryDTO("id2", "TEST Description"));
    c->categoryList.append(CategoryDTO("id3", "Description"));

    CategoryDAO *dao = new CategoryDAO(c);

    bool changeMade = dao->RemoveCategory("id4");
    if(!changeMade && c->categoryList.count() == 3)
    {
        return true;
    }
    return false;
}

bool CategoryDAOTest::TestRemoveCategoryEmptyList()
{
    CachedData *c = new CachedData();

    CategoryDAO *dao = new CategoryDAO(c);

    bool changeMade = dao->RemoveCategory("id");
    if(!changeMade)
    {
        return true;
    }
    return false;
}



