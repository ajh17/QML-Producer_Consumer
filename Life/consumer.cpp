#include "consumer.h"

Consumer::Consumer(MainObject *main, QObject *parent) : QObject(parent)
{
    timer = new QTimer(this);
    m_main = main;
    connect(timer, SIGNAL(timeout()), this, SLOT(startConsuming()));
    timer->start(3000);
}

void Consumer::startConsuming()
{
    QList<int> keyList = m_main->getKeys();
    int key_size = keyList.size();

    qDebug() << "Consumer Thread ID: " << m_threadID;
    m_threadID = this->thread()->currentThreadId();

    if (key_size != 0) {
        qDebug() << key_size;
        int randomID = qrand() % key_size;
        this->consume(keyList[randomID], m_threadID , false);
    }
}

void Consumer::consume(int id, Qt::HANDLE threadID, bool collision)
{
    if (m_threadID == threadID) {
        qDebug() << "Called from Consumer thread: " << threadID;
    }
    else {
        qDebug() << "Called from the GUI thread: " << threadID;
    }
    if (id == 0 || m_main->getBox(id).isNull()) {
        return;
    }

    qDebug() << "ID: " << id;
    QVariant box = m_main->removeBox(id);
    if (collision) {
        emit collisionSignal(box);
    }
    else {
        emit consumedSignal(box);
    }
}

void Consumer::consumeSlot(const QVariant &obj)
{
    if (m_main->getKeyFor(obj) != 0) {
        consume(m_main->getKeyFor(obj), this->thread()->currentThreadId(), true);
    }
    else {
        qDebug() << "Box " << obj << "already removed.";
    }
}
