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

    /// Test AddTransaction
    TestAddTransaction_EmptyTransactionList();
    TestAddTransaction_NonEmptyTransactionList();

    /// Test RemoveTransaction
    TestRemoveTransaction_Found();
    TestRemoveTransaction_NotFoundEmptyList();
    TestRemoveTransaction_NotFoundNonEmptyList();

}

/// Test GetTransactionList
void TransactionDAOTest::TestGetTransactionList_HasTransactions()
{
    CachedData *c = new CachedData();
    c->transactionList.append(TransactionDTO("id", QDate(1999, 9, 9), 111.11, IN_TRANSACTION, "category", "comment"));
    c->transactionList.append(TransactionDTO("id2", QDate(1999, 9, 9), 111.11, IN_TRANSACTION, "category", "comment"));

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
    c->transactionList.append(TransactionDTO("id", QDate(1999, 9, 9), 111.11, IN_TRANSACTION, "category", "comment"));
    c->transactionList.append(TransactionDTO("id2", QDate(1999, 9, 9), 111.11, IN_TRANSACTION, "category", "comment"));

    TransactionDAO *t = new TransactionDAO(c);

    bool changeMade = t->UpdateAmount("id", 587.34);
    Assert((changeMade && c->transactionList.at(0).amount == 587.34), "TestUpdateAmount_ChangeMade()");
}

void TransactionDAOTest::TestUpdateAmount_NoChangeMade()
{
    CachedData *c = new CachedData();
    c->transactionList.append(TransactionDTO("id", QDate(1999, 9, 9), 111.11, IN_TRANSACTION, "category", "comment"));
    c->transactionList.append(TransactionDTO("id2", QDate(1999, 9, 9), 111.11, IN_TRANSACTION, "category", "comment"));

    TransactionDAO *t = new TransactionDAO(c);

    bool changeMade = t->UpdateAmount("id2", 111.11);
    Assert((!changeMade && c->transactionList.at(0).amount == 111.11), "TestUpdateAmount_NoChangeMade()");
}

void TransactionDAOTest::TestUpdateAmount_NotFound()
{
    CachedData *c = new CachedData();
    c->transactionList.append(TransactionDTO("id", QDate(1999, 9, 9), 111.11, IN_TRANSACTION, "category", "comment"));
    c->transactionList.append(TransactionDTO("id2", QDate(1999, 9, 9), 111.11, IN_TRANSACTION, "category", "comment"));

    TransactionDAO *t = new TransactionDAO(c);

    bool changeMade = t->UpdateAmount("55", 111.11);
    Assert((!changeMade), "TestUpdateAmount_NotFound()");
}

/// Test UpdateDate
void TransactionDAOTest::TestUpdateDate_ChangeMade()
{
    CachedData *c = new CachedData();
    c->transactionList.append(TransactionDTO("id", QDate(1999, 9, 9), 111.11, IN_TRANSACTION, "category", "comment"));
    c->transactionList.append(TransactionDTO("id2", QDate(1999, 9, 9), 111.11, IN_TRANSACTION, "category", "comment"));

    TransactionDAO *t = new TransactionDAO(c);

    bool changeMade = t->UpdateDate("id2", QDate(2012, 5, 5));
    Assert((changeMade && c->transactionList.at(1).date == QDate(2012, 5, 5)), "TestUpdateDate_ChangeMade()");
}

void TransactionDAOTest::TestUpdateDate_NoChangeMade()
{
    CachedData *c = new CachedData();
    c->transactionList.append(TransactionDTO("id", QDate(1999, 9, 9), 111.11, IN_TRANSACTION, "category", "comment"));
    c->transactionList.append(TransactionDTO("id2", QDate(1999, 9, 9), 111.11, IN_TRANSACTION, "category", "comment"));

    TransactionDAO *t = new TransactionDAO(c);

    bool changeMade = t->UpdateDate("id2", QDate(1999, 9, 9));
    Assert(!changeMade && c->transactionList.at(1).date == QDate(1999, 9, 9), "TestUpdateDate_NoChangeMade()");
}

void TransactionDAOTest::TestUpdateDate_NotFound()
{
    CachedData *c = new CachedData();
    c->transactionList.append(TransactionDTO("id", QDate(1999, 9, 9), 111.11, IN_TRANSACTION, "category", "comment"));
    c->transactionList.append(TransactionDTO("id2", QDate(1999, 9, 9), 111.11, IN_TRANSACTION, "category", "comment"));

    TransactionDAO *t = new TransactionDAO(c);

    bool changeMade = t->UpdateDate("12345", QDate(1999, 9, 9));
    Assert(!changeMade, "TestUpdateDate_NoChangeMade()");
}

/// Test UpdateType
void TransactionDAOTest::TestUpdateType_ChangeMade()
{
    CachedData *c = new CachedData();
    c->transactionList.append(TransactionDTO("id", QDate(1999, 9, 9), 111.11, IN_TRANSACTION, "category", "comment"));
    c->transactionList.append(TransactionDTO("id2", QDate(1999, 9, 9), 111.11, IN_TRANSACTION, "category", "comment"));

    TransactionDAO *t = new TransactionDAO(c);

    bool changeMade = t->UpdateType("id2", OUT_TRANSACTION);
    Assert(changeMade && (int)c->transactionList.at(1).transactionType == (int)OUT_TRANSACTION, "TestUpdateType_ChangeMade()");
}

void TransactionDAOTest::TestUpdateType_NoChangeMade()
{
    CachedData *c = new CachedData();
    c->transactionList.append(TransactionDTO("id", QDate(1999, 9, 9), 111.11, IN_TRANSACTION, "category", "comment"));
    c->transactionList.append(TransactionDTO("id2", QDate(1999, 9, 9), 111.11, IN_TRANSACTION, "category", "comment"));

    TransactionDAO *t = new TransactionDAO(c);

    bool changeMade = t->UpdateType("id2", IN_TRANSACTION);
    Assert(!changeMade && (int)c->transactionList.at(1).transactionType == (int)IN_TRANSACTION, "TestUpdateType_NoChangeMade()");
}

void TransactionDAOTest::TestUpdateType_NotFound()
{
    CachedData *c = new CachedData();
    c->transactionList.append(TransactionDTO("id", QDate(1999, 9, 9), 111.11, IN_TRANSACTION, "category", "comment"));
    c->transactionList.append(TransactionDTO("id2", QDate(1999, 9, 9), 111.11, IN_TRANSACTION, "category", "comment"));

    TransactionDAO *t = new TransactionDAO(c);

    bool changeMade = t->UpdateType("555", IN_TRANSACTION);
    Assert(!changeMade, "TestUpdateType_NotFound()");
}

/// Test UpdateComment
void TransactionDAOTest::TestUpdateComment_ChangeMade()
{
    CachedData *c = new CachedData();
    c->transactionList.append(TransactionDTO("id", QDate(1999, 9, 9), 111.11, IN_TRANSACTION, "category", "comment"));
    c->transactionList.append(TransactionDTO("id2", QDate(1999, 9, 9), 111.11, IN_TRANSACTION, "category", "comment"));

    TransactionDAO *t = new TransactionDAO(c);

    bool changeMade = t->UpdateComment("id", "NEW COMMENT");
    Assert(changeMade && c->transactionList.at(0).comment == "NEW COMMENT", "TestUpdateComment_ChangeMade()");
}

void TransactionDAOTest::TestUpdateComment_NoChangeMade()
{
    CachedData *c = new CachedData();
    c->transactionList.append(TransactionDTO("id", QDate(1999, 9, 9), 111.11, IN_TRANSACTION, "category", "comment"));
    c->transactionList.append(TransactionDTO("id2", QDate(1999, 9, 9), 111.11, IN_TRANSACTION, "category", "comment"));

    TransactionDAO *t = new TransactionDAO(c);

    bool changeMade = t->UpdateComment("id", "comment");
    Assert(!changeMade && c->transactionList.at(0).comment == "comment", "TestUpdateComment_NoChangeMade()");
}

void TransactionDAOTest::TestUpdateComment_NotFound()
{
    CachedData *c = new CachedData();
    c->transactionList.append(TransactionDTO("id", QDate(1999, 9, 9), 111.11, IN_TRANSACTION, "category", "comment"));
    c->transactionList.append(TransactionDTO("id2", QDate(1999, 9, 9), 111.11, IN_TRANSACTION, "category", "comment"));

    TransactionDAO *t = new TransactionDAO(c);

    bool changeMade = t->UpdateComment("12345", "comment");
    Assert(!changeMade, "TestUpdateComment_NotFound()");
}

/// Test UpdateCategory
void TransactionDAOTest::TestUpdateCategory_ChangeMade()
{
    CachedData *c = new CachedData();
    c->transactionList.append(TransactionDTO("id", QDate(1999, 9, 9), 111.11, IN_TRANSACTION, "category", "comment"));
    c->transactionList.append(TransactionDTO("id2", QDate(1999, 9, 9), 111.11, IN_TRANSACTION, "category", "comment"));

    TransactionDAO *t = new TransactionDAO(c);

    bool changeMade = t->UpdateCategory("id2", "category22");
    Assert(changeMade && c->transactionList.at(1).categoryId == "category22", "TestUpdateCategory_ChangeMade()");
}

void TransactionDAOTest::TestUpdateCategory_NoChangeMade()
{
    CachedData *c = new CachedData();
    c->transactionList.append(TransactionDTO("id", QDate(1999, 9, 9), 111.11, IN_TRANSACTION, "category", "comment"));
    c->transactionList.append(TransactionDTO("id2", QDate(1999, 9, 9), 111.11, IN_TRANSACTION, "category", "comment"));

    TransactionDAO *t = new TransactionDAO(c);

    bool changeMade = t->UpdateCategory("id2", "category");
    Assert(!changeMade, "TestUpdateCategory_NoChangeMade()");
}

void TransactionDAOTest::TestUpdateCategory_NotFound()
{
    CachedData *c = new CachedData();
    c->transactionList.append(TransactionDTO("id", QDate(1999, 9, 9), 111.11, IN_TRANSACTION, "category", "comment"));
    c->transactionList.append(TransactionDTO("id2", QDate(1999, 9, 9), 111.11, IN_TRANSACTION, "category", "comment"));

    TransactionDAO *t = new TransactionDAO(c);

    bool changeMade = t->UpdateCategory("12345", "category");
    Assert(!changeMade, "TestUpdateCategory_NotFound()");
}

/// Test GetTransactionByCategoryId
void TransactionDAOTest::TestGetTransactionsByCategoryId_Found()
{
    CachedData *c = new CachedData();
    c->transactionList.append(TransactionDTO("id", QDate(1999, 9, 9), 111.11, IN_TRANSACTION, "category1", "comment"));
    c->transactionList.append(TransactionDTO("id2", QDate(1999, 9, 9), 111.11, IN_TRANSACTION, "category2", "comment"));
    c->transactionList.append(TransactionDTO("id3", QDate(1999, 9, 9), 111.11, IN_TRANSACTION, "category2", "comment"));
    c->transactionList.append(TransactionDTO("id4", QDate(1999, 9, 9), 111.11, IN_TRANSACTION, "category3", "comment"));

    TransactionDAO *t = new TransactionDAO(c);

    QList<TransactionDTO> list = t->GetTransactionsByCategoryId("category2");
    Assert(list.count() == 2, "TestGetTransactionsByCategoryId_Found()");
}

void TransactionDAOTest::TestGetTransactionsByCategoryId_NotFound()
{
    CachedData *c = new CachedData();
    c->transactionList.append(TransactionDTO("id", QDate(1999, 9, 9), 111.11, IN_TRANSACTION, "category1", "comment"));
    c->transactionList.append(TransactionDTO("id2", QDate(1999, 9, 9), 111.11, IN_TRANSACTION, "category2", "comment"));
    c->transactionList.append(TransactionDTO("id3", QDate(1999, 9, 9), 111.11, IN_TRANSACTION, "category3", "comment"));

    TransactionDAO *t = new TransactionDAO(c);

    QList<TransactionDTO> list = t->GetTransactionsByCategoryId("nonCategory");
    Assert(list.count() == 0, "TestGetTransactionsByCategoryId_NotFound()");
}

/// Test AddTransaction
void TransactionDAOTest::TestAddTransaction_EmptyTransactionList()
{
    CachedData *c = new CachedData();

    TransactionDAO *t = new TransactionDAO(c);

    t->AddTransaction(QDate(2004, 4, 4), 10, IN_TRANSACTION, "CAT2", "COMMENT");

    Assert(c->transactionList.at(0).amount == 10 &&
           c->transactionList.at(0).date ==  QDate(2004, 4, 4) &&
           c->transactionList.at(0).transactionType == IN_TRANSACTION &&
           c->transactionList.at(0).categoryId == "CAT2" &&
           c->transactionList.at(0).comment == "COMMENT" &&
           c->transactionList.count() == 1,
           "TestAddTransaction_EmptyTransactionList()");
}

void TransactionDAOTest::TestAddTransaction_NonEmptyTransactionList()
{
    CachedData *c = new CachedData();
    c->transactionList.append(TransactionDTO("id", QDate(1999, 9, 9), 111.11, IN_TRANSACTION, "category1", "comment"));
    c->transactionList.append(TransactionDTO("id2", QDate(1999, 9, 9), 111.11, IN_TRANSACTION, "category2", "comment"));
    c->transactionList.append(TransactionDTO("id3", QDate(1999, 9, 9), 111.11, IN_TRANSACTION, "category3", "comment"));

    TransactionDAO *t = new TransactionDAO(c);

    t->AddTransaction(QDate(2004, 4, 4), 10, IN_TRANSACTION, "CAT2", "COMMENT");

    Assert(c->transactionList.at(0).amount == 10 &&
           c->transactionList.at(0).date ==  QDate(2004, 4, 4) &&
           c->transactionList.at(0).transactionType == IN_TRANSACTION &&
           c->transactionList.at(0).categoryId == "CAT2" &&
           c->transactionList.at(0).comment == "COMMENT" &&
           c->transactionList.count() == 4,
           "TestAddTransaction_NonEmptyTransactionList()");
}

/// Test RemoveTransaction
void TransactionDAOTest::TestRemoveTransaction_Found()
{
    CachedData *c = new CachedData();
    c->transactionList.append(TransactionDTO("id", QDate(1999, 9, 9), 111.11, IN_TRANSACTION, "category1", "comment"));
    c->transactionList.append(TransactionDTO("id2", QDate(1999, 9, 9), 111.11, IN_TRANSACTION, "category2", "comment"));
    c->transactionList.append(TransactionDTO("id3", QDate(1999, 9, 9), 111.11, IN_TRANSACTION, "category3", "comment"));

    TransactionDAO *t = new TransactionDAO(c);
    bool result = t->RemoveTransaction("id2");

    Assert(c->transactionList.count() == 2 && result,
           "TestRemoveTransaction_Found()");
}

void TransactionDAOTest::TestRemoveTransaction_NotFoundEmptyList()
{
    CachedData *c = new CachedData();

    TransactionDAO *t = new TransactionDAO(c);
    bool result = t->RemoveTransaction("GARBAGE_ID");

    Assert(c->transactionList.count() == 0 && !result,
           "TestRemoveTransaction_NotFoundEmptyList()");
}

void TransactionDAOTest::TestRemoveTransaction_NotFoundNonEmptyList()
{
    CachedData *c = new CachedData();
    c->transactionList.append(TransactionDTO("id", QDate(1999, 9, 9), 111.11, IN_TRANSACTION, "category1", "comment"));
    c->transactionList.append(TransactionDTO("id2", QDate(1999, 9, 9), 111.11, IN_TRANSACTION, "category2", "comment"));
    c->transactionList.append(TransactionDTO("id3", QDate(1999, 9, 9), 111.11, IN_TRANSACTION, "category3", "comment"));

    TransactionDAO *t = new TransactionDAO(c);
    bool result = t->RemoveTransaction("GARBAGE_ID");

    Assert(c->transactionList.count() == 3 && !result,
           "TestRemoveTransaction_NotFoundNonEmptyList()");
}


