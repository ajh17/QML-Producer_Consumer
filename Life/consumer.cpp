#include "consumer.h"

Consumer::Consumer(QObject* obj, QObject *parent) : QObject(parent)
{
    m_obj = obj;
}

void Consumer::consumeBox(const QVariant &obj)
{
    if (m_obj) {
        QVariant retVal;
        qDebug() << "Called consume box on" << obj;
        QMetaObject::invokeMethod(m_obj, "destroyBox", Q_RETURN_ARG(QVariant, retVal), Q_ARG(QVariant, obj));
    }
    else {
        qDebug() << "Viewer doesn't exist";
    }
}

