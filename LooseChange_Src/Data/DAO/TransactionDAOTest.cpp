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

    if(!TestGetTransactionListHasTransactions())
    {
        testsPassed = false;
        qDebug() << "FAILED TEST - TransactionDAOTest::TestGetTransactionListHasTransactions()";
    }

    if(!TestGetTransactionListHasNoTransactions())
    {
        testsPassed = false;
        qDebug() << "FAILED TEST - TransactionDAOTest::TestGetTransactionListHasNoTransactions()";
    }

    /// If all passed, display that they all passed.
    if(testsPassed)
    {
        qDebug() << "TransactionDAOTest Passed.";
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
