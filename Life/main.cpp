#include <QtGui/QGuiApplication>
#include <QQmlContext>
#include <QObject>
#include <QThread>
#include "qtquick2applicationviewer.h"
#include "producer.h"
#include "consumer.h"
#include "mainobject.h"
#include "worker.h"

int main(int argc, char *argv[])
{
    QGuiApplication app(argc, argv);
    QQuickView viewer;
    QVariant returnVal;

    viewer.setSource(QUrl::fromLocalFile("../../../../Life/qml/Life/main.qml"));
    QObject *item = viewer.rootObject();
    QObject::connect((QObject*)viewer.engine(), SIGNAL(quit()), &app, SLOT(quit()));


    MainObject *mainObject = new MainObject(item);
    Worker thread;

    // Start producer's thread
    Producer *producer = new Producer(item, mainObject);
    qDebug() << "GUI thread reporting in! " << app.thread()->currentThreadId();

    Consumer consumer(item, mainObject);

    viewer.setTitle("Life");
    viewer.setHeight(500);
    viewer.setWidth(500);
    viewer.show();

    return app.exec();
}
