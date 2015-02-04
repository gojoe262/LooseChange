#ifndef TRANSACTIONDAOTEST_H
#define TRANSACTIONDAOTEST_H

#include <QDebug>
#include <Data/DAO/TransactionDAO.h>
#include <Data/Cache/CachedData.h>

class TransactionDAOTest
{
public:
    TransactionDAOTest();
    ~TransactionDAOTest();

    void RunTests();

private:
    bool TestGetTransactionListHasTransactions();
    bool TestGetTransactionListHasNoTransactions();
    bool TestGetTransactionsByCategoryId();

};

#endif // TRANSACTIONDAOTEST_H
