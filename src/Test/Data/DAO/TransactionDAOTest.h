#ifndef TRANSACTIONDAOTEST_H
#define TRANSACTIONDAOTEST_H

#include <QDebug>
#include <Data/DAO/TransactionDAO.h>
#include <Data/Cache/CachedData.h>
#include <Test/TestBase.h>

class TransactionDAOTest : TestBase
{
public:
    TransactionDAOTest();

    void RunTests();

private:
    /// Test GetTransactionList
    void TestGetTransactionList_HasTransactions();
    void TestGetTransactionList_HasNoTransactions();

    /// Test UpdateAmount
    void TestUpdateAmount_ChangeMade();
    void TestUpdateAmount_NoChangeMade();
    void TestUpdateAmount_NotFound();

    /// Test UpdateDate
    void TestUpdateDate_ChangeMade();
    void TestUpdateDate_NoChangeMade();
    void TestUpdateDate_NotFound();

    /// Test UpdateType
    void TestUpdateType_ChangeMade();
    void TestUpdateType_NoChangeMade();
    void TestUpdateType_NotFound();

    /// Test UpdateComment
    void TestUpdateComment_ChangeMade();
    void TestUpdateComment_NoChangeMade();
    void TestUpdateComment_NotFound();

    /// Test UpdateCategory
    void TestUpdateCategory_ChangeMade();
    void TestUpdateCategory_NoChangeMade();
    void TestUpdateCategory_NotFound();

    /// Test GetTransactionByCategoryId
    void TestGetTransactionsByCategoryId_Found();
    void TestGetTransactionsByCategoryId_NotFound();

    /// Test AddTransaction
    void TestAddTransaction_EmptyTransactionList();
    void TestAddTransaction_NonEmptyTransactionList();

    /// Test RemoveTransaction
    void TestRemoveTransaction_Found();
    void TestRemoveTransaction_NotFoundEmptyList();
    void TestRemoveTransaction_NotFoundNonEmptyList();
};

#endif // TRANSACTIONDAOTEST_H
