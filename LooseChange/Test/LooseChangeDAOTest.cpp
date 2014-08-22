#include <QtTest/QtTest>
//#include <QString>


#include <DAO/LooseChangeDAO.h>
#include <QFileDialog>

class LooseChangeDAOTest
{
    LooseChangeDAO dao;
public:
    void OpenFile_ShouldOpenFileAndReturnData(QWidget* parent)
    {
        QString fileLocation = QFileDialog::getOpenFileName(parent, QObject::tr("Open File"),"",
                                QObject::tr("LooseChange Files (*.lc);;Text Files (*.txt)"));
        if(dao.OpenFile(fileLocation).count() < 0)
            qDebug("OpenFile_ShouldOpenFileAndReturnData FAILED!!");
        qDebug("OpenFile_ShouldOpenFileAndReturnData passed");
    }

    void SaveFile_ShouldWriteFileAndReturnTrue(QWidget* parent)
    {
        QString fileLocation = QFileDialog::getSaveFileName(parent,QObject::tr("Save File"),"",
                                                            QObject::tr("LooseChange Files (*.lc);;Text Files (*.txt)"));
        QList<LooseChangeDTO> list;
//        LooseChangeDTO one;
//        one.amount = 123.21;
//        one.category = Category::GasTravel;
//        one.comment = "TEST";
        QDate d;
        list.append(LooseChangeDTO(d.currentDate(),123.12,(Type)1, (Category)5, "TESTComment"));
        list.append(LooseChangeDTO(d.currentDate(),123.12,(Type)0, (Category)4, "TESTComment2"));

        dao.SaveFile(fileLocation, list);
        qDebug("Check Save File");

    }





};

