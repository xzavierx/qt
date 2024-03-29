#include <QCoreApplication>
#include <QDebug>

int main(int argc, char *argv[])
{
    QCoreApplication a(argc, argv);
    QList<QString> list;
    list << "A" << "B" << "C" << "D";
#ifdef JAVA_STYLE_ITERATORS
    QListIterator<QString> i(list);
    while(i.hasNext())
        qDebug() << i.next();
#else
    QList<QString>::iterator i;
    for (i = list.begin(); i != list.end(); ++i)
        qDebug() << *i;
#endif


#ifdef JAVA_STYLE_ITERATORS
    QListIterator<QString> j(list);
    j.toBack();
    while(j.hasPrevious())
        qDebug() << j.previous();
#else
    auto it1 = list.rbegin();
    for (; it1 != list.rend(); ++it1) {
        qDebug() << *it1;
    }
#endif


    QList<int> listInt;
    listInt << 1 << 2 << 3 << 4 << 5 << 6;
#ifdef JAVA_STYLE_ITERATORS
    QMutableListIterator<int> k(listInt);
    while(k.hasNext()) {
        if (k.next() % 2 != 0)
            k.remove();
    }
#else
    auto it = listInt.begin();
    while (it != listInt.end()) {
        if (*it % 2 != 0)
            it = listInt.erase(it);
        else
            ++it;
    }
#endif
    QListIterator<int> m(listInt);
    while(m.hasNext())
        qDebug() << m.next();

    QMap<QString, QString> map;
    map.insert("Paris", "France");
    map.insert("Guatemala City", "Guatemala");
    map.insert("Mexico City", "Mexico");
    map.insert("Moscow", "Russia");
    QMutableMapIterator<QString, QString> n(map);
    while(n.hasNext()) {
        if (n.next().key().endsWith("City"))
            n.remove();
    }
    QMapIterator<QString, QString> o(map);
    while(o.hasNext()) {
        const auto& a = o.next();
        qDebug() << a.key() << ":" << a.value();
    }


    return a.exec();
}
