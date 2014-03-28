#include <QtGui/QGuiApplication>
#include <QQmlContext>
#include <csignal>
#include "qtquick2applicationviewer.h"
#include "producer.h"
#include "consumer.h"

struct CleanExit {
    CleanExit()
    {
        signal(SIGINT, &CleanExit::exitQt);
        signal(SIGTERM, &CleanExit::exitQt);
        signal(SIGABRT, &CleanExit::exitQt);
    }

    static void exitQt(int sig)
    {
        qDebug() << "Recieved signal" << sig;
        QCoreApplication::exit(0);
    }
};

int main(int argc, char *argv[])
{
    CleanExit cleanExit;
    QGuiApplication app(argc, argv);
    qDebug() << "GUI Thread ID: " << app.thread()->currentThreadId();

    // Read QML File
    QQuickView viewer;
    viewer.setSource(QUrl::fromLocalFile("../../../../Life/qml/Life/main.qml"));
    QObject *item = viewer.rootObject();

    // Setup main object.
    MainObject *mainObject = new MainObject(item);

    // Start producer thread
    QThread *produceThread = new QThread();
    Producer *producer = new Producer(item, mainObject);
    producer->moveToThread(produceThread);
    produceThread->start();

    // Start consumer thread
    QThread *consumeThread = new QThread();
    Consumer *consumer = new Consumer(item, mainObject);
    consumer->moveToThread(consumeThread);
    consumeThread->start();
    viewer.rootContext()->setContextProperty("_consumer", consumer);

    // <-- Signals from QML to C++ -->
    QObject::connect((QObject *)viewer.engine(), SIGNAL(quit()), &app, SLOT(quit()));

    viewer.setTitle("Life");
    viewer.setHeight(500);
    viewer.setWidth(500);
    viewer.show();

    return app.exec();
}
