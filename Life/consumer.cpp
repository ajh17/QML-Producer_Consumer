#include "consumer.h"

Consumer::Consumer(QObject* obj, MainObject *main, QObject *parent) : QObject(parent)
{
    timer = new QTimer(this);
    m_obj = obj;
    m_main = main;

    connect(timer, SIGNAL(timeout()), this, SLOT(startConsuming()));
    timer->start(1000);
}

// TODO: Implement this
void Consumer::startConsuming()
{
}

void Consumer::consume(const QVariant &obj)
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
