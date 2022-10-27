#include "fancutoff.h"
#include <QApplication>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    fancutoff w;
    w.show();

    return a.exec();
}
