#include "consumer.h"

Consumer::Consumer(QObject *obj, MainObject *main,
                   QObject *parent) : QObject(parent)
{
    timer = new QTimer(this);
    m_obj = obj;
    m_main = main;
    connect(timer, SIGNAL(timeout()), this, SLOT(startConsuming()));
    timer->start(3000);
}

void Consumer::startConsuming()
{
    if (!m_obj) {
        qDebug() << "Viewer was null.";
        return;
    }
    m_threadID = this->thread()->currentThreadId();
    qDebug() << "Consumer Thread ID: " << m_threadID;
    int hashSize = m_main->hashSize();
    int randomID = qrand() % hashSize;

    // Check to make sure the random number ID is in the hash
    // Otherwise, keep trying to generate random numbers.
    // Might be slow.
    while (! m_main->didFind(randomID)) {
        randomID = qrand() % hashSize;
    }
    this->consume(randomID, m_threadID);
}

void Consumer::consume(int id, Qt::HANDLE threadID)
{
    if (threadID == m_threadID) {
        qDebug() << "Called from Consumer thread: " << threadID;
    }
    else {
        qDebug() << "Called from Avoider thread: " << threadID;
    }
    QVariant retVal;

    if (!mutex.tryLock()) {
        qDebug() << "Lock failed.";
    }
    else {
        qDebug() << "Locking consumer.";
    }

    qDebug() << "ID: " << id;
    QVariant box = m_main->removeBox(id);
    QMetaObject::invokeMethod(m_obj, "destroyBox", Qt::BlockingQueuedConnection,
                              Q_RETURN_ARG(QVariant, retVal),
                              Q_ARG(QVariant, box));
    mutex.unlock();
}

void Consumer::consumeSlot(QVariant &obj)
{
    consum(m_main->getKeyFor(obj), this->thread()->currentThreadId());
}
