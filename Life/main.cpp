#include <QtGui/QGuiApplication>
#include <QQmlContext>
#include "qtquick2applicationviewer.h"
#include "producer.h"
#include "consumer.h"
#include "animator.h"

int main(int argc, char *argv[])
{
    QGuiApplication app(argc, argv);
    qDebug() << "GUI thread reporting in! " << app.thread()->currentThreadId();

    // Construct two threads for producer and consumer.
    QThread *produceThread = new QThread();
    QThread *consumeThread = new QThread();

    // Read QML File
    QQuickView viewer;
    viewer.setSource(QUrl::fromLocalFile("../../../../Life/qml/Life/main.qml"));

    QObject *item = viewer.rootObject();
    QObject::connect((QObject *)viewer.engine(), SIGNAL(quit()), &app, SLOT(quit()));

    // Setup main object.
    MainObject *mainObject = new MainObject(item);

    // Start producer thread
    Producer *producer = new Producer(item, mainObject);
    producer->moveToThread(produceThread);
    produceThread->start();

    // Start consumer thread
    Consumer *consumer = new Consumer(item, mainObject);
    consumer->moveToThread(consumeThread);
    consumeThread->start();

    // Start Animator
    Animator *animator = new Animator(item, consumer, mainObject);
    animator->checkForCollision();

    viewer.setTitle("Life");
    viewer.setHeight(500);
    viewer.setWidth(500);
    viewer.show();

    return app.exec();
}
