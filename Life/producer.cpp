#include "producer.h"
#include <QDebug>
#include <QVariant>
#include <QMetaObject>

Producer::Producer(QObject* obj, QObject *parent) : QObject(parent)
{
    id = 0;
    timer = new QTimer(this);
    m_obj = obj;

    connect(timer, SIGNAL(timeout()), this, SLOT(produceTimer()));
    timer->start(1000);
}

void Producer::produceTimer()
{
    if (!m_obj) {
        qDebug() << "Object was null";
        exit(1);
    }
    bool success = QMetaObject::invokeMethod(m_obj, "callCreate");
    if (!success) {
        qDebug() << "Unable to call QML function";
        exit(2);
    }
    ++id;
}

QVariant* Producer::getHash(int id) const
{
    return hash.value(id);
}
