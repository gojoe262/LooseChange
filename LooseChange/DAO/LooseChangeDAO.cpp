#include "LooseChangeDAO.h"


#include <QTextStream>
#include <QStringList>
#include <QFileDialog>
#include <QObject>
#include <QFile>
#include <Utility/TransactionType.h>
#include <Utility/Categories.h>
#include <QMessageBox>


LooseChangeDAO::LooseChangeDAO()
{
}


//SEE Examples: http://qt-project.org/doc/qt-5/QFile.html
//              http://qt-project.org/doc/qt-5/qstring.html (Split)
QList<LooseChangeDTO> LooseChangeDAO::ReadFile(QString fileLocation)
{    
    cachedList.ClearList();
    QFile file(fileLocation);
    if (file.open(QIODevice::ReadOnly | QIODevice::Text))
    {
        QTextStream inStream(&file);
        while (!inStream.atEnd())
        {
            QString line = inStream.readLine();
            QStringList lineData = line.split("|---|", QString::KeepEmptyParts);

            int id = lineData[0].toInt();
            QDate date = QDate::fromString(lineData[1], "yyyyMMdd");
            double amount = lineData[2].toDouble();
            TransactionType type = (TransactionType)lineData[3].toInt();
            Category category = (Category)lineData[4].toInt();
            QString comment = lineData[5];

            cachedList.Add(LooseChangeDTO(id,date, amount, type, category, comment));
        }
    }
    isDirty = false;
    return cachedList.GetList();
}

bool LooseChangeDAO::WriteFile(QString fileLocation)
{
    QList<LooseChangeDTO> dtoList = cachedList.GetList();

    QFile file(fileLocation);
    if (file.open(QIODevice::WriteOnly | QIODevice::Text))
    {
        QTextStream outStream(&file);
        foreach (LooseChangeDTO dto, dtoList)
        {
            outStream << dto.id << "|---|"
                      << dto.date.toString("yyyyMMdd") << "|---|"
                      << dto.amount << "|---|"
                      << (int)dto.transactionType << "|---|"
                      << (int)dto.category<< "|---|"
                      << dto.comment << "\n";
        }
        isDirty = false;
        return true;
    }
    else
    {
        QMessageBox::information(0, "Error", "Error writing to file " + file.fileName());
        isDirty = true;
        return false;
    }
}

QList<LooseChangeDTO> LooseChangeDAO::GetList()
{
    return cachedList.GetList();
}

bool LooseChangeDAO::Add(LooseChangeDTO inDto)
{
    cachedList.Add(inDto);
    isDirty = true;
}

bool LooseChangeDAO::Update(LooseChangeDTO inDto)
{
    cachedList.Update(inDto);
    isDirty = true;
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
}





