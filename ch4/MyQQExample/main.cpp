#include "dialog.h"
#include <QApplication>
#include "drawe.h"

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    Drawe drawer;
    drawer.show();
//    Dialog w;
//    w.show();

    return a.exec();
}
