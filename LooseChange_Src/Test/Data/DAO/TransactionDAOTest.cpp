#include "TransactionDAOTest.h"

TransactionDAOTest::TransactionDAOTest()
{

}

TransactionDAOTest::~TransactionDAOTest()
{

}

void TransactionDAOTest::RunTests()
{
    bool testsPassed = true;

    /// Test GetTransactionList
    if(!TestGetTransactionListHasTransactions())
    {
        PrintFailedMessage("TransactionDAOTest::TestGetTransactionListHasTransactions()");
        testsPassed = false;
    }
    if(!TestGetTransactionListHasNoTransactions())
    {
        PrintFailedMessage("TransactionDAOTest::TestGetTransactionListHasNoTransactions()");
        testsPassed = false;
    }

    /// Test UpdateAmount
    if(!TestUpdateAmountChangeMade())
    {
        PrintFailedMessage("TransactionDAOTest::TestUpdateAmountChangeMade()");
        testsPassed = false;
    }
    if(!TestUpdateAmountNoChangeMade())
    {
        PrintFailedMessage("TransactionDAOTest::TestUpdateAmountNoChangeMade()");
        testsPassed = false;
    }
    if(!TestUpdateAmountNotFound())
    {
        PrintFailedMessage("TransactionDAOTest::TestUpdateAmountNotFound()");
        testsPassed = false;
    }

//    /// Test UpdateDate
//    bool TestUpdateDateChangeMade();
//    bool TestUpdateDateNoChangeMade();
//    bool TestUpdateDateNotFound();

//    /// Test UpdateType
//    bool TestUpdateTypeChangeMade();
//    bool TestUpdateTypeNoChangeMade();
//    bool TestUpdateTypeNotFound();

//    /// Test UpdateComment
//    bool TestUpdateCommentChangeMade();
//    bool TestUpdateCommentNoChangeMade();
//    bool TestUpdateCommentNotFound();

//    /// Test UpdateCategory
//    bool TestUpdateCategoryChangeMade();
//    bool TestUpdateCategoryNoChangeMade();
//    bool TestUpdateCategoryNotFound();

//    /// Test GetTransactionByCategoryId
//    bool TestGetTransactionsByCategoryId();





    /// If all passed, display that they all passed.
    if(testsPassed)
    {
        PrintPassedMessage("TransactionDAOTest");
    }
}

bool TransactionDAOTest::TestGetTransactionListHasTransactions()
{
    CachedData *c = new CachedData();
    c->transactionList.append(TransactionDTO("id", QDate(1999, 9, 9), 111.11, IN, "category", "comment"));
    c->transactionList.append(TransactionDTO("id2", QDate(1999, 9, 9), 111.11, IN, "category", "comment"));

    TransactionDAO *t = new TransactionDAO(c);

    return (t->GetTransactionList().count() == 2);
}

bool TransactionDAOTest::TestGetTransactionListHasNoTransactions()
{
    CachedData *c = new CachedData();
    TransactionDAO *t = new TransactionDAO(c);

    return (t->GetTransactionList().count() == 0);
}

bool TransactionDAOTest::TestUpdateAmountChangeMade()
{
    CachedData *c = new CachedData();
    c->transactionList.append(TransactionDTO("id", QDate(1999, 9, 9), 111.11, IN, "category", "comment"));
    c->transactionList.append(TransactionDTO("id2", QDate(1999, 9, 9), 111.11, IN, "category", "comment"));

    TransactionDAO *t = new TransactionDAO(c);

    bool changeMade = t->UpdateAmount("id", 587.34);
    if(changeMade && c->transactionList.at(0).amount == 587.34)
    {
        return true;
    }
    return false;
}

