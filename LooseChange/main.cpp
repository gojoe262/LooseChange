#include "Presenter/LooseChangePresenter.h"
#include <QApplication>

//Run Application
int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    LooseChangePresenter w;
    w.show();

    return a.exec();
}


/* //Run Unit Tests
#include <Test/LooseChangeDAOTest.cpp>
int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    QWidget * parent = new QWidget();
    qDebug("Starting Tests...");

    // LooseChangeDAOTests
    LooseChangeDAOTest testDao;
    testDao.OpenFile_ShouldOpenFileAndReturnData(parent);
    testDao.SaveFile_ShouldWriteFileAndReturnTrue(parent);



    delete parent;
    return 0;
}
/*
