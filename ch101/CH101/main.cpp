#include "dialog.h" //包含了程序中要完成功能的Dialog类的定义，在Dialog类中封装完成所需要的功能
#include <QApplication> //每个使用Qt图形化应用程序中必须使用一个QApplication对象

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    Dialog w; //创建一个对话框对象
    w.show();

    return a.exec();
}
