#include "LooseChangeDAO.h"


#include <QTextStream>
#include <QStringList>
#include <QFileDialog>
#include <QObject>
#include <QFile>
#include <Utility/Type.h>
#include <Utility/Categories.h>


LooseChangeDAO::LooseChangeDAO()
{
}


//SEE Examples: http://qt-project.org/doc/qt-5/QFile.html
//              http://qt-project.org/doc/qt-5/qstring.html (Split)
QList<LooseChangeDTO> LooseChangeDAO::ReadFile(QString fileLocation)
{
    QList<LooseChangeDTO> list = QList<LooseChangeDTO>();
    QFile file(fileLocation);
    if (file.open(QIODevice::ReadOnly | QIODevice::Text))
    {
        QTextStream inStream(&file);
        while (!inStream.atEnd())
        {
            QString line = inStream.readLine();
            QStringList lineData = line.split("|---|", QString::KeepEmptyParts);

            QDate date = QDate::fromString(lineData[0], "yyyyMMdd");
            float amount = lineData[1].toFloat();
            Type type = (Type)lineData[2].toInt();
            Category category = Category(lineData[3].toInt());
            QString comment = lineData[4];

            list.append(LooseChangeDTO(date, amount, type, category, comment));
        }
    }
    return list;
}

bool LooseChangeDAO::WriteFile(QString fileLocation, QList<LooseChangeDTO> dtoList)
{
    QFile file(fileLocation);
    if (file.open(QIODevice::WriteOnly | QIODevice::Text))
    {
        QTextStream outStream(&file);
        foreach (LooseChangeDTO dto, dtoList)
        {
            outStream << dto.date.toString("yyyyMMdd") << "|---|"
                      << dto.amount << "|---|"
                      << (int)dto.type << "|---|"
                      << (int)dto.category<< "|---|"
                      << dto.comment << "\n";
        }
        return true;
    }
    return false;
}
