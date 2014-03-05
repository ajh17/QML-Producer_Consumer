#include "consumer.h"
#include <QThread>
#include <QMutex>

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

    // Check to make sure the random number ID is in the hash
    // Otherwise, keep trying to generate random numbers.
    // Might be slow.
    while (! m_main->didFind(randomID)) {
        randomID = qrand() % hashSize;
    }
    this->consume(randomID);
}

void Consumer::consume(int id)
{
    if (m_obj) {
        qDebug() << "Consumer Thread ID: " << thread()->currentThreadId();
        QVariant retVal;
        QMutex mutex;

        mutex.lock();
        QVariant box = m_main->removeBox(id);
        QMetaObject::invokeMethod(m_obj, "destroyBox", Qt::BlockingQueuedConnection,
                Q_RETURN_ARG(QVariant, retVal), Q_ARG(QVariant, box));
        mutex.unlock();
    }
    else {
        qDebug() << "Viewer doesn't exist";
    }
}
