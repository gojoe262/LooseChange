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
    ~TransactionDAOTest();

    void RunTests();

private:
    /// Test GetTransactionList
    bool TestGetTransactionListHasTransactions();
    bool TestGetTransactionListHasNoTransactions();

    /// Test UpdateAmount
    bool TestUpdateAmountChangeMade();
    bool TestUpdateAmountNoChangeMade();
    bool TestUpdateAmountNotFound();

    /// Test UpdateDate
    bool TestUpdateDateChangeMade();
    bool TestUpdateDateNoChangeMade();
    bool TestUpdateDateNotFound();

    /// Test UpdateType
    bool TestUpdateTypeChangeMade();
    bool TestUpdateTypeNoChangeMade();
    bool TestUpdateTypeNotFound();

    /// Test UpdateComment
    bool TestUpdateCommentChangeMade();
    bool TestUpdateCommentNoChangeMade();
    bool TestUpdateCommentNotFound();

    /// Test UpdateCategory
    bool TestUpdateCategoryChangeMade();
    bool TestUpdateCategoryNoChangeMade();
    bool TestUpdateCategoryNotFound();

    /// Test GetTransactionByCategoryId
    bool TestGetTransactionsByCategoryId();

};

#endif // TRANSACTIONDAOTEST_H
