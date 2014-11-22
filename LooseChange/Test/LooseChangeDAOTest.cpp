#include <QtTest/QtTest>
//#include <QString>


#include <DataAccess/LooseChangeDAO.h>
#include <QFileDialog>
#include <Utility/TransactionType.h>
#include <QFileDialog>


class LooseChangeDAOTest
{
    LooseChangeDAO dao;
public:
    void OpenFile_ShouldReadFileAndReturnData(QWidget* parent)
    {

        QString fileLocation = QFileDialog::ShowOpenFileDialog(parent);

        if(dao.ReadFile(fileLocation).count() < 0)
            qDebug() << "FAILED - " << Q_FUNC_INFO;
        else
            qDebug() << "Passed - " << Q_FUNC_INFO;
    }

    void SaveFile_ShouldWriteFileAndReturnTrue(QWidget* parent)
    {
        QString fileLocation = QFileDialog::ShowSaveFileDialog(parent);
        QList<LooseChangeDTO> list;

        QDate d;
        list.append(LooseChangeDTO(d.currentDate(),123.12,IN, Groceries, "TESTComment"));
        list.append(LooseChangeDTO(d.currentDate(),123.12,OUT, GasTravel, "TESTComment2"));

        if(dao.WriteFile(fileLocation, list))
            qDebug() << "Passed - " << Q_FUNC_INFO;
        else
            qDebug() << "FAILED - " << Q_FUNC_INFO;
        //Check save file

    }





};

