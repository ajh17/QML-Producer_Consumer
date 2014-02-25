#include <QtGui/QGuiApplication>
#include <QQmlContext>
#include <QObject>
#include "qtquick2applicationviewer.h"
#include "life.h"
#include "producer.h"
#include "consumer.h"

int main(int argc, char *argv[])
{
    QGuiApplication app(argc, argv);
    QQuickView viewer;
    Life life;
    QVariant returnVal;

    viewer.setSource(QUrl::fromLocalFile("../../../../Life/qml/Life/main.qml"));
    QObject *item = viewer.rootObject();
    Producer producer(item);
    Consumer* consumer = new Consumer(item);
    QObject::connect(item, SIGNAL(qmlSignal(QVariant)), consumer, SLOT(consumeBox(QVariant)));
    viewer.setTitle("Life");
    viewer.setHeight(500);
    viewer.setWidth(500);

    viewer.show();

    return app.exec();
}
