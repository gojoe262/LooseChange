#include "TransactionDAO.h"


#include <QTextStream>
#include <QStringList>
#include <QFileDialog>
#include <QObject>
#include <QFile>
#include <Utility/TransactionType.h>
#include <Utility/Categories.h>
#include <DataAccess/FileAccess/FileReader.h>
#include <DataAccess/FileAccess/FileWriter.h>
#include <QMessageBox>


TransactionDAO::TransactionDAO(QWidget *parent) : QObject(parent)
{
}

TransactionDAO::~TransactionDAO()
{
}


//SEE Examples: http://qt-project.org/doc/qt-5/QFile.html
//              http://qt-project.org/doc/qt-5/qstring.html (Split)
void TransactionDAO::ReadFile(QString fileLocation)
{    
    FileReader reader;
    cachedList.ClearList();
    cachedList.SetList(reader.ReadFile(fileLocation));
    MarkClean();
}

void TransactionDAO::WriteFile(QString fileLocation)
{
    QList<TransactionDTO> dtoList = cachedList.GetList();
    FileWriter writer;

    if(writer.WriteFile(dtoList, fileLocation))
    {
        MarkClean();
    }
    else
    {
        MarkDirty();
    }
}

QList<TransactionDTO> TransactionDAO::GetTransactionList()
{
    return cachedList.GetList();
}

bool TransactionDAO::Add(TransactionDTO inDto)
{
    cachedList.Add(inDto);
    MarkDirty();
}

bool TransactionDAO::Update(TransactionDTO inDto)
{
    cachedList.Update(inDto);
    MarkDirty();
}

void TransactionDAO::UpdateAmount(int id, double amount)
{
    if(cachedList.UpdateAmount(id, amount))
    {
        MarkDirty();
    }
}

void TransactionDAO::UpdateDate(int id, QDate date)
{
    if(cachedList.UpdateDate(id, date))
    {
        MarkDirty();
    }
}

void TransactionDAO::UpdateTransactionType(int id, TransactionType type)
{
    if(cachedList.UpdateTransactionType(id, type))
    {
        MarkDirty();
    }
}

void TransactionDAO::UpdateCategory(int id, CategoryDTO category)
{
    if(cachedList.UpdateCategory(id, category))
    {
        MarkDirty();
    }
}

void TransactionDAO::UpdateComment(int id, QString comment)
{
    if(cachedList.UpdateComment(id, comment))
    {
        MarkDirty();
    }
}

bool TransactionDAO::Delete(TransactionDTO inDto)
{
    cachedList.Delete(inDto);
    isDirty = true;
}

bool TransactionDAO::IsDirty()
{
    return isDirty;
}

void TransactionDAO::MarkDirty()
{
    isDirty = true;
    emit this->DataChanged(true);
}

void TransactionDAO::MarkClean()
{
    isDirty = false;
    emit this->DataChanged(false);
}




