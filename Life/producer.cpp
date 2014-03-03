#include "producer.h"
#include <QDebug>
#include <QVariant>
#include <QMetaObject>

Producer::Producer(QObject* obj, MainObject* main, QObject *parent) : QObject(parent)
{
    id = 1;
    timer = new QTimer(this);
    m_obj = obj;
    m_main = main;

    connect(timer, SIGNAL(timeout()), this, SLOT(produceTimer()));
    timer->start(1000);
}

void Producer::produceTimer()
{
    if (!m_obj) {
        qDebug() << "Object was null";
        exit(1);
    }
    QVariant boxObject;
    bool success = QMetaObject::invokeMethod(m_obj, "callCreate",
            Q_RETURN_ARG(QVariant, boxObject));
    if (!success) {
        qDebug() << "Unable to call QML function callCreate";
        exit(2);
    }
    hash.insert(id, boxObject);
    qDebug() << "INSERTED Hash(" << id <<  "," << hash.value(id);
}

QVariant Producer::getItem(int id)
{
    return hash.value(id);
}

int Producer::hashSize()
{
    return hash.size();
}
