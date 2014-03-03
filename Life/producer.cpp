#include "producer.h"
#include <QDebug>
#include <QVariant>
#include <QMetaObject>

Producer::Producer(QObject* obj, MainObject* main, QObject *parent) : QObject(parent)
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
        exit(1);
    }
    QVariant boxObject;
    bool success = QMetaObject::invokeMethod(m_obj, "callCreate",
            Q_RETURN_ARG(QVariant, boxObject));
    if (!success) {
        qDebug() << "Unable to call QML function callCreate";
        exit(2);
    }
    m_main->insertBox(boxObject);
}
