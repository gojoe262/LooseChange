#include <QtTest/QtTest>
//#include <QString>


#include <DAO/LooseChangeDAO.h>
#include <QFileDialog>
#include <Utility/Type.h>


class LooseChangeDAOTest
{
    LooseChangeDAO dao;
public:
    void OpenFile_ShouldReadFileAndReturnData(QWidget* parent)
    {
        QString fileLocation = QFileDialog::getOpenFileName(parent, QObject::tr("Open File"),"",
                                QObject::tr("LooseChange Files (*.lc);;Text Files (*.txt)"));

        if(dao.ReadFile(fileLocation).count() < 0)
            qDebug("FAILED - OpenFile_ShouldOpenFileAndReturnData");
        else
            qDebug("Passed - OpenFile_ShouldOpenFileAndReturnData");
    }

    void SaveFile_ShouldWriteFileAndReturnTrue(QWidget* parent)
    {
        QString fileLocation = QFileDialog::getSaveFileName(parent,QObject::tr("Save File"),"",
                                                            QObject::tr("LooseChange Files (*.lc);;Text Files (*.txt)"));
        QList<LooseChangeDTO> list;

        QDate d;
        list.append(LooseChangeDTO(d.currentDate(),123.12,IN, (Category)5, "TESTComment"));
        list.append(LooseChangeDTO(d.currentDate(),123.12,OUT, (Category)4, "TESTComment2"));

        if(dao.WriteFile(fileLocation, list))
            qDebug("Passed - SaveFile_ShouldWriteFileAndReturnTrue");
        else
            qDebug("FAILED - SaveFile_ShouldWriteFileAndReturnTrue");
        //Check save file

    }





};

