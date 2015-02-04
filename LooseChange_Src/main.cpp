#include "UI/Presenter/LooseChangePresenter.h"
#include <QApplication>

#define TESTING //Toggle to switch between testing and running program


#ifndef TESTING
//Run Application
int main(int argc, char *argv[])
{
    QApplication a(argc, argv);

    LooseChangePresenter w;
    w.show();

    return a.exec();
}


#endif



#ifdef TESTING
 //Run Unit Tests
#include <Utility/UniqueKeyGenerator.h>
#include <Data/DAO/TransactionDAOTest.h>
#include <QDebug>
int main(int argc, char *argv[])
{
    TransactionDAOTest t;
    t.RunTests();


    /*
    UniqueKeyGenerator g;
    for(int i = 0; i < 20; i++)
    {
        QList<QString> list;
        qDebug() << g.GenerateUniqueKey(list);
    }
    return 0;
    */
}

#endif
