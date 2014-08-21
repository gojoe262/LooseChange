#include "LooseChangeDAO.h"


#include <QTextStream>
#include <QStringList>
#include <QFileDialog>
#include <QObject>
#include <QFile>
#include <Type.h>

LooseChangeDAO::LooseChangeDAO()
{
}

//SEE Examples: http://qt-project.org/doc/qt-5/QFile.html
//              http://qt-project.org/doc/qt-5/qstring.html (Split)
QList<LooseChangeDTO> LooseChangeDAO::ReadFile(QString inFileName)
{
    QList<LooseChangeDTO> list = QList<LooseChangeDTO>();
    QFile file(inFileName);
    if (file.open(QIODevice::ReadOnly | QIODevice::Text))
    {
        QTextStream inStream(&file);
        while (!inStream.atEnd())
        {
            QString line = inStream.readLine();
            QStringList lineData = line.split("|||", QString::KeepEmptyParts);

            QDate date = QDate::fromString(lineData[0], "yyyyMMdd");
            float amount = lineData[1].toFloat();
            Type type = (Type)lineData[2].toInt();
            QString comment = lineData[3];

            list.append(LooseChangeDTO(date, amount, type, comment));
        }
    }
    return list;
}

//http://qt-project.org/forums/viewthread/935
QString LooseChangeDAO::FetchFileLocation(QWidget *parent)
{
    QString fileName = QFileDialog::getOpenFileName(parent, QObject::tr("Open File"),"", QObject::tr("LooseChange Files (*.lc);;Text Files (*.txt)"));
    return fileName;
}
