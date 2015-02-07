#include "TransactionDAOTest.h"

TransactionDAOTest::TransactionDAOTest()
{

}

void TransactionDAOTest::RunTests()
{
    qDebug() << "========TransactionDAOTest=====";
    /// Test GetTransactionList
    TestGetTransactionList_HasTransactions();
    TestGetTransactionList_HasNoTransactions();

    /// Test UpdateAmount
    TestUpdateAmount_ChangeMade();
    TestUpdateAmount_NoChangeMade();
    TestUpdateAmount_NotFound();

    /// Test UpdateDate
    TestUpdateDate_ChangeMade();
    TestUpdateDate_NoChangeMade();
    TestUpdateDate_NotFound();

    /// Test UpdateType
    TestUpdateType_ChangeMade();
    TestUpdateType_NoChangeMade();
    TestUpdateType_NotFound();

    /// Test UpdateComment
    TestUpdateComment_ChangeMade();
    TestUpdateComment_NoChangeMade();
    TestUpdateComment_NotFound();

    /// Test UpdateCategory
    TestUpdateCategory_ChangeMade();
    TestUpdateCategory_NoChangeMade();
    TestUpdateCategory_NotFound();

    /// Test GetTransactionByCategoryId
    TestGetTransactionsByCategoryId_Found();
    TestGetTransactionsByCategoryId_NotFound();

}

/// Test GetTransactionList
void TransactionDAOTest::TestGetTransactionList_HasTransactions()
{
    CachedData *c = new CachedData();
    c->transactionList.append(TransactionDTO("id", QDate(1999, 9, 9), 111.11, IN, "category", "comment"));
    c->transactionList.append(TransactionDTO("id2", QDate(1999, 9, 9), 111.11, IN, "category", "comment"));

    TransactionDAO *t = new TransactionDAO(c);

    Assert(t->GetTransactionList().count() == 2, "TestGetTransactionList_HasTransactions()");
}

void TransactionDAOTest::TestGetTransactionList_HasNoTransactions()
{
    CachedData *c = new CachedData();
    TransactionDAO *t = new TransactionDAO(c);

    Assert(t->GetTransactionList().count() == 0, "TestGetTransactionList_HasTransactions");
}

/// Test UpdateAmount
void TransactionDAOTest::TestUpdateAmount_ChangeMade()
{
    CachedData *c = new CachedData();
    c->transactionList.append(TransactionDTO("id", QDate(1999, 9, 9), 111.11, IN, "category", "comment"));
    c->transactionList.append(TransactionDTO("id2", QDate(1999, 9, 9), 111.11, IN, "category", "comment"));

    TransactionDAO *t = new TransactionDAO(c);

    bool changeMade = t->UpdateAmount("id", 587.34);
    Assert((changeMade && c->transactionList.at(0).amount == 587.34), "TestUpdateAmount_ChangeMade()");
}

void TransactionDAOTest::TestUpdateAmount_NoChangeMade()
{
    CachedData *c = new CachedData();
    c->transactionList.append(TransactionDTO("id", QDate(1999, 9, 9), 111.11, IN, "category", "comment"));
    c->transactionList.append(TransactionDTO("id2", QDate(1999, 9, 9), 111.11, IN, "category", "comment"));

    TransactionDAO *t = new TransactionDAO(c);

    bool changeMade = t->UpdateAmount("id2", 111.11);
    Assert((!changeMade && c->transactionList.at(0).amount == 111.11), "TestUpdateAmount_NoChangeMade()");
}

void TransactionDAOTest::TestUpdateAmount_NotFound()
{
    CachedData *c = new CachedData();
    c->transactionList.append(TransactionDTO("id", QDate(1999, 9, 9), 111.11, IN, "category", "comment"));
    c->transactionList.append(TransactionDTO("id2", QDate(1999, 9, 9), 111.11, IN, "category", "comment"));

    TransactionDAO *t = new TransactionDAO(c);

    bool changeMade = t->UpdateAmount("55", 111.11);
    Assert((!changeMade), "TestUpdateAmount_NotFound()");
}

/// Test UpdateDate
void TransactionDAOTest::TestUpdateDate_ChangeMade()
{
    CachedData *c = new CachedData();
    c->transactionList.append(TransactionDTO("id", QDate(1999, 9, 9), 111.11, IN, "category", "comment"));
    c->transactionList.append(TransactionDTO("id2", QDate(1999, 9, 9), 111.11, IN, "category", "comment"));

    TransactionDAO *t = new TransactionDAO(c);

    bool changeMade = t->UpdateDate("id2", QDate(2012, 5, 5));
    Assert((changeMade && c->transactionList.at(1).date == QDate(2012, 5, 5)), "TestUpdateDate_ChangeMade()");
}

void TransactionDAOTest::TestUpdateDate_NoChangeMade()
{
    CachedData *c = new CachedData();
    c->transactionList.append(TransactionDTO("id", QDate(1999, 9, 9), 111.11, IN, "category", "comment"));
    c->transactionList.append(TransactionDTO("id2", QDate(1999, 9, 9), 111.11, IN, "category", "comment"));

    TransactionDAO *t = new TransactionDAO(c);

    bool changeMade = t->UpdateDate("id2", QDate(1999, 9, 9));
    Assert(!changeMade && c->transactionList.at(1).date == QDate(1999, 9, 9), "TestUpdateDate_NoChangeMade()");
}

void TransactionDAOTest::TestUpdateDate_NotFound()
{
    CachedData *c = new CachedData();
    c->transactionList.append(TransactionDTO("id", QDate(1999, 9, 9), 111.11, IN, "category", "comment"));
    c->transactionList.append(TransactionDTO("id2", QDate(1999, 9, 9), 111.11, IN, "category", "comment"));

    TransactionDAO *t = new TransactionDAO(c);

    bool changeMade = t->UpdateDate("12345", QDate(1999, 9, 9));
    Assert(!changeMade, "TestUpdateDate_NoChangeMade()");
}

/// Test UpdateType
void TransactionDAOTest::TestUpdateType_ChangeMade()
{
    CachedData *c = new CachedData();
    c->transactionList.append(TransactionDTO("id", QDate(1999, 9, 9), 111.11, IN, "category", "comment"));
    c->transactionList.append(TransactionDTO("id2", QDate(1999, 9, 9), 111.11, IN, "category", "comment"));

    TransactionDAO *t = new TransactionDAO(c);

    bool changeMade = t->UpdateType("id2", OUT);
    Assert(changeMade && (int)c->transactionList.at(1).transactionType == (int)OUT, "TestUpdateType_ChangeMade()");
}

void TransactionDAOTest::TestUpdateType_NoChangeMade()
{
    CachedData *c = new CachedData();
    c->transactionList.append(TransactionDTO("id", QDate(1999, 9, 9), 111.11, IN, "category", "comment"));
    c->transactionList.append(TransactionDTO("id2", QDate(1999, 9, 9), 111.11, IN, "category", "comment"));

    TransactionDAO *t = new TransactionDAO(c);

    bool changeMade = t->UpdateType("id2", IN);
    Assert(!changeMade && (int)c->transactionList.at(1).transactionType == (int)IN, "TestUpdateType_NoChangeMade()");
}

void TransactionDAOTest::TestUpdateType_NotFound()
{
    CachedData *c = new CachedData();
    c->transactionList.append(TransactionDTO("id", QDate(1999, 9, 9), 111.11, IN, "category", "comment"));
    c->transactionList.append(TransactionDTO("id2", QDate(1999, 9, 9), 111.11, IN, "category", "comment"));

    TransactionDAO *t = new TransactionDAO(c);

    bool changeMade = t->UpdateType("555", IN);
    Assert(!changeMade, "TestUpdateType_NotFound()");
}

/// Test UpdateComment
void TransactionDAOTest::TestUpdateComment_ChangeMade()
{
    CachedData *c = new CachedData();
    c->transactionList.append(TransactionDTO("id", QDate(1999, 9, 9), 111.11, IN, "category", "comment"));
    c->transactionList.append(TransactionDTO("id2", QDate(1999, 9, 9), 111.11, IN, "category", "comment"));

    TransactionDAO *t = new TransactionDAO(c);

    bool changeMade = t->UpdateComment("id", "NEW COMMENT");
    Assert(changeMade && c->transactionList.at(0).comment == "NEW COMMENT", "TestUpdateComment_ChangeMade()");
}

void TransactionDAOTest::TestUpdateComment_NoChangeMade()
{
    CachedData *c = new CachedData();
    c->transactionList.append(TransactionDTO("id", QDate(1999, 9, 9), 111.11, IN, "category", "comment"));
    c->transactionList.append(TransactionDTO("id2", QDate(1999, 9, 9), 111.11, IN, "category", "comment"));

    TransactionDAO *t = new TransactionDAO(c);

    bool changeMade = t->UpdateComment("id", "comment");
    Assert(!changeMade && c->transactionList.at(0).comment == "comment", "TestUpdateComment_NoChangeMade()");
}

void TransactionDAOTest::TestUpdateComment_NotFound()
{
    CachedData *c = new CachedData();
    c->transactionList.append(TransactionDTO("id", QDate(1999, 9, 9), 111.11, IN, "category", "comment"));
    c->transactionList.append(TransactionDTO("id2", QDate(1999, 9, 9), 111.11, IN, "category", "comment"));

    TransactionDAO *t = new TransactionDAO(c);

    bool changeMade = t->UpdateComment("12345", "comment");
    Assert(!changeMade, "TestUpdateComment_NotFound()");
}

/// Test UpdateCategory
void TransactionDAOTest::TestUpdateCategory_ChangeMade()
{
    CachedData *c = new CachedData();
    c->transactionList.append(TransactionDTO("id", QDate(1999, 9, 9), 111.11, IN, "category", "comment"));
    c->transactionList.append(TransactionDTO("id2", QDate(1999, 9, 9), 111.11, IN, "category", "comment"));

    TransactionDAO *t = new TransactionDAO(c);

    bool changeMade = t->UpdateCategory("id2", "category22");
    Assert(changeMade && c->transactionList.at(1).categoryId == "category22", "TestUpdateCategory_ChangeMade()");
}

void TransactionDAOTest::TestUpdateCategory_NoChangeMade()
{
    CachedData *c = new CachedData();
    c->transactionList.append(TransactionDTO("id", QDate(1999, 9, 9), 111.11, IN, "category", "comment"));
    c->transactionList.append(TransactionDTO("id2", QDate(1999, 9, 9), 111.11, IN, "category", "comment"));

    TransactionDAO *t = new TransactionDAO(c);

    bool changeMade = t->UpdateCategory("id2", "category");
    Assert(!changeMade, "TestUpdateCategory_NoChangeMade()");
}

void TransactionDAOTest::TestUpdateCategory_NotFound()
{
    CachedData *c = new CachedData();
    c->transactionList.append(TransactionDTO("id", QDate(1999, 9, 9), 111.11, IN, "category", "comment"));
    c->transactionList.append(TransactionDTO("id2", QDate(1999, 9, 9), 111.11, IN, "category", "comment"));

    TransactionDAO *t = new TransactionDAO(c);

    bool changeMade = t->UpdateCategory("12345", "category");
    Assert(!changeMade, "TestUpdateCategory_NotFound()");
}

/// Test GetTransactionByCategoryId
void TransactionDAOTest::TestGetTransactionsByCategoryId_Found()
{
    CachedData *c = new CachedData();
    c->transactionList.append(TransactionDTO("id", QDate(1999, 9, 9), 111.11, IN, "category1", "comment"));
    c->transactionList.append(TransactionDTO("id2", QDate(1999, 9, 9), 111.11, IN, "category2", "comment"));
    c->transactionList.append(TransactionDTO("id3", QDate(1999, 9, 9), 111.11, IN, "category2", "comment"));
    c->transactionList.append(TransactionDTO("id4", QDate(1999, 9, 9), 111.11, IN, "category3", "comment"));

    TransactionDAO *t = new TransactionDAO(c);

    QList<TransactionDTO> list = t->GetTransactionsByCategoryId("category2");
    Assert(list.count() == 2, "TestGetTransactionsByCategoryId_Found()");
}

void TransactionDAOTest::TestGetTransactionsByCategoryId_NotFound()
{
    CachedData *c = new CachedData();
    c->transactionList.append(TransactionDTO("id", QDate(1999, 9, 9), 111.11, IN, "category1", "comment"));
    c->transactionList.append(TransactionDTO("id2", QDate(1999, 9, 9), 111.11, IN, "category2", "comment"));
    c->transactionList.append(TransactionDTO("id3", QDate(1999, 9, 9), 111.11, IN, "category3", "comment"));

    TransactionDAO *t = new TransactionDAO(c);

    QList<TransactionDTO> list = t->GetTransactionsByCategoryId("nonCategory");
    Assert(list.count() == 0, "TestGetTransactionsByCategoryId_NotFound()");
}


