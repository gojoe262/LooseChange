#include "Presenter/LooseChangePresenter.h"
#include <QApplication>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    LooseChangePresenter w;
    w.show();

    return a.exec();
}
