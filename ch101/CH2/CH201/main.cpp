

#include <QCoreApplication>
#include <QDebug>

/*CH201*/
//int main(int argc, char *argv[])
//{
//    QCoreApplication a(argc, argv);
//    QList<int> list;
//    list << 1 << 2 << 3 << 4 << 5;
//    QListIterator<int> i(list);
//    for (;i.hasNext();) {
//        qDebug() << i.next();
//    }
//    return a.exec();
//}

/*CH202*/
int main(int argc, char *argv[])
{
    QCoreApplication a(argc, argv);
    QList<int> list; //创建一个空的列表list
    QMutableListIterator<int> i(list); //创建列表的读写迭代器
    for (int j = 0; j < 10; ++j) {
        i.insert(j);
    }
    for (i.toFront(); i.next();) {
        qDebug() << i.next();
    }
    for (i.toBack(); i.hasPrevious();) {
        if(i.previous() % 2 == 0)
            i.remove();
        else {
            i.setValue(i.peekNext() * 10);
        }
    }

    for (i.toFront(); i.hasNext();) {
        qDebug() << i.next();
    }
    return a.exec();
}
