#include "TestBase.h"

TestBase::TestBase()
{

}

TestBase::~TestBase()
{

}

void TestBase::RunTests()
{

}

void TestBase::PrintFailedMessage(QString message)
{
    QString failed = "** FAILED ** - ";
    qDebug() << failed.append(message);
}

void TestBase::PrintPassedMessage(QString message)
{
    QString passed = "Passed - ";
    qDebug() << passed.append(message);
}

