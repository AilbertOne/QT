#include "widget.h"
#include <QtDebug>
#include <QVariant>
#include <QColor>

Widget::Widget(QWidget *parent)
    : QWidget(parent)
{
    QVariant v{709};
    qDebug()<<v.toInt(); // 709

    QVariant w{"Hello World"};
    qDebug()<<w; // QVariant(QString, "Hello World")
    qDebug()<<w.toString(); // "Hello World"

    QMap<QString,QVariant>map{{"int",709},{"double",3.14}};
    map["string"] = "Hello World";
    map.insert("color",QColor(255,0,0));
    // 调用相应的转换函数
    qDebug()<<map["int"]<<map["int"].toInt(); // QVariant(int, 709) 709
    qDebug()<<map["double"]<<map["double"].toDouble(); // QVariant(double, 3.14) 3.14
    qDebug()<<map["string"]<<map["string"].toString(); // QVariant(QString, "Hello World") "Hello World"
    qDebug()<<map["color"]<<map["color"].value<QColor>(); // QVariant(QColor, QColor(ARGB 1, 1, 0, 0)) QColor(ARGB 1, 1, 0, 0)
    QStringList s1; //创建一个字符串列表
    s1 << "A" << "B" << "C" << "D";
    QVariant slv(s1); //将该列表保存在一个QVariant变量中
    if(slv.type() == QVariant::StringList)
    {
        QStringList list = slv.toStringList();
        for (int i = 0; i < list.size(); ++i) {
            qDebug() << list.at(i); //输出列表内容
        }
    }

}

Widget::~Widget()
{

}
