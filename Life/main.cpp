#include <QtGui/QGuiApplication>
#include <QQmlContext>
#include <QObject>
#include "qtquick2applicationviewer.h"
#include "producer.h"
#include "consumer.h"
#include "mainobject.h"

int main(int argc, char *argv[])
{
    QGuiApplication app(argc, argv);
    QQuickView viewer;
    QVariant returnVal;

    viewer.setSource(QUrl::fromLocalFile("../../../../Life/qml/Life/main.qml"));
    QObject *item = viewer.rootObject();
    //QObject *object = new Object(item);
    Producer producer(item);
    Consumer consumer(item);

    viewer.setTitle("Life");
    viewer.setHeight(500);
    viewer.setWidth(500);
    viewer.show();

    return app.exec();
}
