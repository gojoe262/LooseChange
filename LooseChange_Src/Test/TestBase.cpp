#include "TestBase.h"

TestBase::TestBase()
{

}


void TestBase::Assert(bool b, QString methodName)
{
    if(!b)
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

