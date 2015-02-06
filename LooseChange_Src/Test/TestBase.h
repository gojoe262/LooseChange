#ifndef TESTBASE_H
#define TESTBASE_H

#include <QString>
#include <QDebug>

class TestBase
{
public:
    TestBase();
    ~TestBase();

    void RunTests();

    void PrintFailedMessage(QString methodName);
    void PrintPassedMessage(QString methodName);
};

#endif // TESTBASE_H
