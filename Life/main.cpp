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
    MainObject *mainObject = new MainObject(item);
    Producer producer(item, mainObject);
    Consumer consumer(item, mainObject);

    viewer.setTitle("Life");
    viewer.setHeight(500);
    viewer.setWidth(500);
    viewer.show();

    return app.exec();
}
