#include <QtGui/QGuiApplication>
#include <QQmlContext>
#include <csignal>
#include "qtquick2applicationviewer.h"
#include "producer.h"
#include "consumer.h"
#include "avoider.h"

struct CleanExit {
    CleanExit() {
        signal(SIGINT, &CleanExit::exitQt);
        signal(SIGTERM, &CleanExit::exitQt);
        signal(SIGABRT, &CleanExit::exitQt);
    }

    static void exitQt(int sig) {
        qDebug() << "Recieved signal " << sig;
        QCoreApplication::exit(0);
    }
};

int main(int argc, char *argv[])
{
    CleanExit cleanExit;
    QGuiApplication app(argc, argv);
    qDebug() << "GUI Thread ID: " << app.thread()->currentThreadId();

    // Construct two threads for producer and consumer.
    QThread *produceThread = new QThread();
    QThread *consumeThread = new QThread();
    //QThread *avoiderThread = new QThread();

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

    // NOTE: Uncomment the following to run collision detection in C++
    // Start Avoider
    // Avoider *avoider = new Avoider(item, mainObject, consumer);
    // avoider->moveToThread(avoiderThread);
    // avoiderThread->start();

    viewer.setTitle("Life");
    viewer.setHeight(500);
    viewer.setWidth(500);
    viewer.show();

    return app.exec();
}
