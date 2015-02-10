#ifndef TESTBASE_H
#define TESTBASE_H

#include <QString>
#include <QDebug>

class TestBase
{
public:
    TestBase();

    virtual void RunTests() = 0;

    void Assert(bool b, QString methodName);

private:
    void PrintFailedMessage(QString methodName);
    void PrintPassedMessage(QString methodName);
};

#endif // TESTBASE_H
