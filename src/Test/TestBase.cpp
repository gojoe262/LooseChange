#include "TestBase.h"

TestBase::TestBase()
{

}


void TestBase::Assert(bool predicate, QString methodName)
{
    if(!predicate)
    {
        PrintFailedMessage(methodName);
    }
}

void TestBase::PrintFailedMessage(QString methodName)
{
    QString failed = "** FAILED ** - ";
    qDebug() << failed.append(methodName);
}

void TestBase::PrintPassedMessage(QString methodName)
{
    QString passed = "Passed - ";
    qDebug() << passed.append(methodName);
}

