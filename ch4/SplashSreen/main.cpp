#include "mainwindow.h"
#include <QApplication>
#include <QPixmap>
#include <QSplashScreen>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    QPixmap pixmap("Qt.png"); //创建QPixmap对象，设置启动图片
    QSplashScreen splash(pixmap); //利用QPixmap对象创建一个QSplashScreen对象
    splash.show(); //显示此启动图片
    a.processEvents(); //使程序在显示启动画面的同时仍能响应鼠标等其它事件。

    MainWindow w;
    w.show();
    splash.finish(&w); //等主窗体对象初始化完成后，结束启动画面

    return a.exec();
}
