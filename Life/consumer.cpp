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

    QList<int> keyList = m_main->getKeys();
    int key_size = keyList.size();
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

    QObject *collisionTextBox, *consumerTextBox;
    if (collision) {
        collisionTextBox = m_obj->findChild<QObject *>("collisionTextBox");
        if (collisionTextBox) {
            collisionTextBox->setProperty("color", "red");
        }
    }
    else {
        consumerTextBox = m_obj->findChild<QObject *>("consumerTextBox");
        if (consumerTextBox) {
            consumerTextBox->setProperty("color", "red");
        }
    }

    QVariant box = m_main->removeBox(id);
    QMetaObject::invokeMethod(m_obj, "destroyBox", Qt::QueuedConnection,
                              Q_ARG(QVariant, box));
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
