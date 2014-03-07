#include "producer.h"

Producer::Producer(QObject *obj, MainObject *main, QObject *parent) : QObject(parent)
{
    timer = new QTimer(this);
    m_obj = obj;
    m_main = main;

    connect(timer, SIGNAL(timeout()), this, SLOT(produceTimer()));
    timer->start(1000);
}

void Producer::produceTimer()
{
    if (!m_obj) {
        qDebug() << "Viewer was null";
    }
    qDebug() << "Producer Thread ID: " << thread()->currentThreadId();
    QVariant boxObject;
    QMutexLocker locker(&mutex);

    bool success = QMetaObject::invokeMethod(m_obj, "callCreate",
                   Qt::BlockingQueuedConnection, Q_RETURN_ARG(QVariant, boxObject));
    if (!success) {
        qDebug() << "Unable to call QML function callCreate";
    }

    m_main->insertBox(boxObject);
}

