#include <QCoreApplication>
#include <QDebug>

int main(int argc, char *argv[])
{
    QCoreApplication a(argc, argv);
    QMap<QString, QString> map; //创建一个QMap栈对象
    //向栈对象中插入<城市，区号>对
    map.insert("beijing", "111");
    map.insert("shanghai", "021");
    map.insert("nanjing", "025");
    QMapIterator<QString, QString> i(map); //创建一个只读存储器，共用一个存储空间
    for (;i.hasNext();) {
        i.next();
        qDebug() << " " << i.key() << i.value();
    }

    QMutableMapIterator<QString, QString> mi(map);
    if(mi.findNext("111"))
        mi.setValue("010");
    QMutableMapIterator<QString, QString> modi(map);
    qDebug() << " ";
    for (;modi.hasNext();) {
        modi.next();
        qDebug()<<" "<<modi.key()<<" "<<modi.value();
    }

    return a.exec();
}
