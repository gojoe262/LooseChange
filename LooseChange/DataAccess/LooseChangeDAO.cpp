#include "LooseChangeDAO.h"


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


LooseChangeDAO::LooseChangeDAO(QWidget *parent) : QObject(parent)
{
}

LooseChangeDAO::~LooseChangeDAO()
{
}


//SEE Examples: http://qt-project.org/doc/qt-5/QFile.html
//              http://qt-project.org/doc/qt-5/qstring.html (Split)
QList<LooseChangeDTO> LooseChangeDAO::ReadFile(QString fileLocation)
{    
    FileReader reader;
    cachedList.ClearList();
    cachedList.SetList(reader.ReadFile(fileLocation));
    MarkClean();
    return cachedList.GetList();
}

void LooseChangeDAO::WriteFile(QString fileLocation)
{
    QList<LooseChangeDTO> dtoList = cachedList.GetList();
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

QList<LooseChangeDTO> LooseChangeDAO::GetList()
{
    return cachedList.GetList();
}

bool LooseChangeDAO::Add(LooseChangeDTO inDto)
{
    cachedList.Add(inDto);
    MarkDirty();
}

bool LooseChangeDAO::Update(LooseChangeDTO inDto)
{
    cachedList.Update(inDto);
    MarkDirty();
}

void LooseChangeDAO::UpdateAmount(int id, double amount)
{
    if(cachedList.UpdateAmount(id, amount))
    {
        MarkDirty();
    }
}

void LooseChangeDAO::UpdateDate(int id, QDate date)
{
    if(cachedList.UpdateDate(id, date))
    {
        MarkDirty();
    }
}

void LooseChangeDAO::UpdateTransactionType(int id, TransactionType type)
{
    if(cachedList.UpdateTransactionType(id, type))
    {
        MarkDirty();
    }
}

void LooseChangeDAO::UpdateCategory(int id, Category category)
{
    if(cachedList.UpdateCategory(id, category))
    {
        MarkDirty();
    }
}

void LooseChangeDAO::UpdateComment(int id, QString comment)
{
    if(cachedList.UpdateComment(id, comment))
    {
        MarkDirty();
    }
}

bool LooseChangeDAO::Delete(LooseChangeDTO inDto)
{
    cachedList.Delete(inDto);
    isDirty = true;
}

bool LooseChangeDAO::IsDirty()
{
    return isDirty;
}

void LooseChangeDAO::MarkDirty()
{
    isDirty = true;
    emit this->DataChanged(true);
}

void LooseChangeDAO::MarkClean()
{
    isDirty = false;
    emit this->DataChanged(false);
}




