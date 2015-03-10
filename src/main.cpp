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


/// Run Unit Tests
#ifdef TESTING

#include <Test/Data/DAO/TransactionDAOTest.h>
#include <Test/Data/DAO/CategoryDAOTest.h>

int main(int argc, char *argv[])
{
    TransactionDAOTest t;
    t.RunTests();

    CategoryDAOTest c;
    c.RunTests();

}

#endif
