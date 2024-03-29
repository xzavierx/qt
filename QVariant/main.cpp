#include <QCoreApplication>
#include <QDebug>
#include <QTranslator>
#include <QVariant>
#include <QSize>
#include <QColor>

int main(int argc, char *argv[])
{
    QCoreApplication a(argc, argv);
    QVariant v(123);

    QTranslator translator;

    Q_UNUSED(translator.load("hellotr_la"));
    a.installTranslator(&translator);

    qDebug() << v.toInt() << v.toString();

    v = QVariant(QTranslator::tr("hello"));
    qDebug() << v.toInt() << v.toString();

    v = QVariant(QStringList() << "hello" << "world");
    qDebug() << v.toStringList();


    QVariant variant;
    variant.setValue(QColor(Qt::black));
    qDebug() << variant.value<QColor>();

    variant.setValue(QColor(Qt::white));
    qDebug() << variant.value<QColor>();

    variant.setValue(QColor(Qt::blue));
    qDebug() << variant.value<QColor>();

    variant.setValue(QColor(Qt::darkGray));
    qDebug() << variant.value<QColor>();

    variant.setValue(QColor(Qt::lightGray));
    qDebug() << variant.value<QColor>();
    return a.exec();
}
