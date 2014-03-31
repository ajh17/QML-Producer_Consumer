#include "producer.h"

Producer::Producer(QObject *obj, MainObject *main,
                   QObject *parent) : QObject(parent)
{
    timer = new QTimer(this);
    timer2 = new QTimer(this);
    m_obj = obj;
    m_main = main;

    connect(timer, SIGNAL(timeout()), this, SLOT(produceTimer()));
    connect(timer2, SIGNAL(timeout()), this, SLOT(startFlash()));
    timer->start(1000);
    timer2->start(300);
}

void Producer::produceTimer()
{
    if (!m_obj) {
        qDebug() << "Viewer was null";
        return;
    }
    qDebug() << "Producer Thread ID: " << thread()->currentThreadId();
    QVariant boxObject;

    bool success = QMetaObject::invokeMethod(m_obj, "callCreate",
                   Qt::BlockingQueuedConnection,
                   Q_RETURN_ARG(QVariant, boxObject));

    if (!success) {
        qDebug() << "Unable to call QML function callCreate";
        return;
    }
    m_main->insertBox(boxObject);
}

void Producer::startFlash()
{
    flash("white");
}

void Producer::flash(QVariant color)
{
    QObject *collisionText = m_obj->findChild<QObject *>("collisionTextBox");
    QObject *consumerText = m_obj->findChild<QObject *>("consumerTextBox");

    collisionText->setProperty("color", color);
    consumerText->setProperty("color", color);
}
