#include "consumer.h"

Consumer::Consumer(QObject* obj, MainObject *main, QObject *parent) : QObject(parent)
{
    timer = new QTimer(this);
    m_obj = obj;
    m_main = main;

    connect(timer, SIGNAL(timeout()), this, SLOT(startConsuming()));
    timer->start(3000);
}

void Consumer::startConsuming()
{
    int hashSize = m_main->hashSize();
    int randomID = qrand() % hashSize;
    this->consume(randomID);
}

void Consumer::consume(int id)
{
    if (m_obj) {
        QVariant retVal;
        QVariant box = m_main->removeBox(id);
        QMetaObject::invokeMethod(m_obj, "destroyBox", Q_RETURN_ARG(QVariant, retVal), Q_ARG(QVariant, box));
    }
    else {
        qDebug() << "Viewer doesn't exist";
    }
}
