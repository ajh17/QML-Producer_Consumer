#include <QtGui/QGuiApplication>
#include <QQmlContext>
#include <QQuickItem>
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
        qDebug() << "Received signal" << sig;
        QCoreApplication::exit(0);
    }
};

int main(int argc, char *argv[])
{
    CleanExit cleanExit;
    QGuiApplication app(argc, argv);
    qDebug() << "GUI Thread ID: " << app.thread()->currentThreadId();

    // Setup main object.
    MainObject *mainObject = new MainObject();

    // Start consumer thread
    QThread *consumeThread = new QThread();
    Consumer *consumer = new Consumer(mainObject);

    // Read QML File
    QQuickView viewer;
    viewer.rootContext()->setContextProperty("Consumer", consumer);
    viewer.setSource(QUrl::fromLocalFile("../../../../Life/qml/Life/main.qml"));
    QObject *item = viewer.rootObject();

    // Start producer thread
    QThread *produceThread = new QThread();
    Producer *producer = new Producer(item, mainObject);
    producer->moveToThread(produceThread);
    produceThread->start();

    viewer.rootContext()->setContextProperty("consumer", consumer);
    consumer->moveToThread(consumeThread);
    consumeThread->start();

    // <-- Signals from QML to C++ -->
    QObject::connect((QObject *)viewer.engine(), SIGNAL(quit()), &app,
                     SLOT(quit()));

    QObject::connect(consumer, SIGNAL(consumedSignal(QVariant)), item,
                     SLOT(consumedSlot(QVariant)));

    QObject::connect(consumer, SIGNAL(collisionSignal(QVariant)), item,
                    SLOT(collisionSlot(QVariant)));

    QObject::connect(producer, SIGNAL(clearSignal()), item, SLOT(clearSlot()));

    viewer.setTitle("Life");
    viewer.setHeight(500);
    viewer.setWidth(500);
    viewer.show();

    return app.exec();
}
