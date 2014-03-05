#include <QtGui/QGuiApplication>
#include <QQmlContext>
#include <QObject>
#include <QThread>
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
    QObject::connect((QObject*)viewer.engine(), SIGNAL(quit()), &app, SLOT(quit()));

    // Start producer's thread
    qDebug() << "GUI thread reporting in! " << app.thread()->currentThreadId();
    Producer *producer = new Producer(item, mainObject);

    Consumer consumer(item, mainObject);

    viewer.setTitle("Life");
    viewer.setHeight(500);
    viewer.setWidth(500);
    viewer.show();

    return app.exec();
}
