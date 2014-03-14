#include "consumer.h"

Consumer::Consumer(QObject *obj, MainObject *main,
                   QObject *parent) : QObject(parent)
{
    timer = new QTimer(this);
    m_obj = obj;
    m_main = main;

    connect(timer, SIGNAL(timeout()), this, SLOT(startConsuming()));
    //timer->start(3000);
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
    this->consume(randomID, thread()->currentThreadId());
}

void Consumer::consume(int id, Qt::HANDLE threadID)
{
    if (m_obj) {
        if (threadID == thread()->currentThreadId()) {
            qDebug() << "Called from Consumer thread: " << threadID;
        }
        else {
            qDebug() << "Called from Avoider thread: " << threadID;
        }
        QVariant retVal;
        QMutexLocker locker(&mutex);

        if (m_main->getBox(id).isNull()) {
            qDebug() << "Already deleted";
            qDebug() << "ID: " << id;
            return;
        }

        qDebug() << "ID: " << id;
        QVariant box = m_main->removeBox(id);
        QMetaObject::invokeMethod(m_obj, "destroyBox", Qt::BlockingQueuedConnection,
                                  Q_RETURN_ARG(QVariant, retVal),
                                  Q_ARG(QVariant, box));
    }
    else {
        qDebug() << "Viewer doesn't exist";
    }
}
