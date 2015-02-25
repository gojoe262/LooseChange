#include "CategoryDAOTest.h"

CategoryDAOTest::CategoryDAOTest()
{

}

void CategoryDAOTest::RunTests()
{
    qDebug() << "========CategoryDAOTest========";
    /// Test GetCategories
    TestGetCategories_NonEmptyList();
    TestGetCategories_EmptyList();

    /// Test GetCategoryById
    TestGetCategoryById_HasMatch();
    TestGetCategoryById_NoMatch();
    TestGetCategoryById_EmptyList();

    /// Test UpdateDescription
    TestUpdateDescription_ChangeMade();
    TestUpdateDescription_NoChangeMade();

    /// Test AddCategory
    TestAddCategory();

    /// Test RemoveCategory
    TestRemoveCategory_ChangeMade();
    TestRemoveCategory_NoChangeMadeNotFound();
    TestRemoveCategory_EmptyList();
}


void CategoryDAOTest::TestGetCategories_NonEmptyList()
{
    CachedData *c = new CachedData();
    c->categoryList.append(CategoryDTO("id", "Description"));
    c->categoryList.append(CategoryDTO("id2", "Description"));
    c->categoryList.append(CategoryDTO("id3", "Description"));

    CategoryDAO *dao = new CategoryDAO(c);

    Assert(dao->GetCategories().count() == 3, "TestGetCategories_NonEmptyList()");
}

void CategoryDAOTest::TestGetCategories_EmptyList()
{
    CachedData *c = new CachedData();
    CategoryDAO *dao = new CategoryDAO(c);

    Assert(dao->GetCategories().count() == 0, "TestGetCategories_EmptyList()");
}

void CategoryDAOTest::TestGetCategoryById_HasMatch()
{
    CachedData *c = new CachedData();
    c->categoryList.append(CategoryDTO("id", "Description"));
    c->categoryList.append(CategoryDTO("id2", "TEST Description"));
    c->categoryList.append(CategoryDTO("id3", "Description"));

    CategoryDAO *dao = new CategoryDAO(c);

    Assert(dao->GetCategoryById("id2").description == "TEST Description", "TestGetCategoryById_HasMatch()");
}

void CategoryDAOTest::TestGetCategoryById_NoMatch()
{
    CachedData *c = new CachedData();
    c->categoryList.append(CategoryDTO("id", "Description"));
    c->categoryList.append(CategoryDTO("id2", "TEST Description"));
    c->categoryList.append(CategoryDTO("id3", "Description"));

    CategoryDAO *dao = new CategoryDAO(c);

    CategoryDTO dto = dao->GetCategoryById("id4");

    Assert((dto.description == "" && dto.id == ""), "TestGetCategoryById_NoMatch()");
}

void CategoryDAOTest::TestGetCategoryById_EmptyList()
{
    CachedData *c = new CachedData();
    CategoryDAO *dao = new CategoryDAO(c);

    CategoryDTO dto = dao->GetCategoryById("id4");

    Assert((dto.description == "" && dto.id == ""), "TestGetCategoryById_EmptyList()");
}

void CategoryDAOTest::TestUpdateDescription_ChangeMade()
{
    CachedData *c = new CachedData();
    c->categoryList.append(CategoryDTO("id", "Description"));
    c->categoryList.append(CategoryDTO("id2", "TEST Description"));
    c->categoryList.append(CategoryDTO("id3", "Description"));

    CategoryDAO *dao = new CategoryDAO(c);

    bool changeMade = dao->UpdateDescription("id", "New Decription 007");
    Assert(changeMade && c->categoryList.at(0).description == "New Decription 007", "TestUpdateDescription_ChangeMade()");
}

void CategoryDAOTest::TestUpdateDescription_NoChangeMade()
{
    CachedData *c = new CachedData();
    c->categoryList.append(CategoryDTO("id", "Description"));
    c->categoryList.append(CategoryDTO("id2", "TEST Description"));
    c->categoryList.append(CategoryDTO("id3", "Description"));

    CategoryDAO *dao = new CategoryDAO(c);

    bool changeMade = dao->UpdateDescription("id", "Description");
    Assert(!changeMade, "TestUpdateDescription_NoChangeMade()");
}

void CategoryDAOTest::TestAddCategory()
{
    CachedData *c = new CachedData();
    c->categoryList.append(CategoryDTO("id", "Description"));
    c->categoryList.append(CategoryDTO("id2", "TEST Description"));

    CategoryDAO *dao = new CategoryDAO(c);

    dao->AddCategory();
    Assert(c->categoryList.count() == 3, "TestAddCategory()");
}

void CategoryDAOTest::TestRemoveCategory_ChangeMade()
{
    CachedData *c = new CachedData();
    c->categoryList.append(CategoryDTO("id", "Description"));
    c->categoryList.append(CategoryDTO("id2", "TEST Description"));
    c->categoryList.append(CategoryDTO("id3", "Description"));

    CategoryDAO *dao = new CategoryDAO(c);

    bool changeMade = dao->RemoveCategory("id");
    Assert(changeMade && c->categoryList.count() == 2, "TestRemoveCategory_ChangeMade()");
}

void CategoryDAOTest::TestRemoveCategory_NoChangeMadeNotFound()
{
    CachedData *c = new CachedData();
    c->categoryList.append(CategoryDTO("id", "Description"));
    c->categoryList.append(CategoryDTO("id2", "TEST Description"));
    c->categoryList.append(CategoryDTO("id3", "Description"));

    CategoryDAO *dao = new CategoryDAO(c);

    bool changeMade = dao->RemoveCategory("id4");
    Assert(!changeMade && c->categoryList.count() == 3, "TestRemoveCategory_NoChangeMadeNotFound()");
}

void CategoryDAOTest::TestRemoveCategory_EmptyList()
{
    CachedData *c = new CachedData();

    CategoryDAO *dao = new CategoryDAO(c);

    bool changeMade = dao->RemoveCategory("id");
    Assert(!changeMade, "TestRemoveCategory_EmptyList()");
}



