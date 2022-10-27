#include "mainwindow.h"
#include <QApplication>
#include <QSplitter>
#include <QTextEdit>
#include <QTextCodec>
int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    QFont font("ZYSong18030", 12); //指定显示字体
    a.setFont(font);

    //主分割窗口
    QSplitter *splitterMain = new QSplitter(Qt::Horizontal, 0); //新建QSplitter类对象，水平分割窗口
    QTextEdit *textLeft = new QTextEdit(QObject::tr("Left Widget"), splitterMain);  //新建一个QTxtEdit对象，插入主窗口

    textLeft -> setAlignment(Qt::AlignCenter); // 设置文字居中
    //分割右窗口
    QSplitter *splitterRight =new QSplitter(Qt::Vertical, splitterMain);
    splitterRight ->setOpaqueResize(false); //拖拽窗口时是否显示线条
    QTextEdit *textUp = new QTextEdit(QObject::tr("Top Widget"), splitterRight); //设置窗口的文字
    textUp -> setAlignment(Qt::AlignCenter);
    QTextEdit *textBottom = new QTextEdit(QObject::tr("Bottom Widget"), splitterRight);
    textBottom  -> setAlignment(Qt::AlignCenter);

    splitterMain -> setStretchFactor(1,1);
    splitterMain -> setWindowTitle(QObject::tr("Splitter"));
    splitterMain -> show();
//    MainWindow w;
//    w.show();

    return a.exec();
}
