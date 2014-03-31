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
    qDebug() << "Consumer Thread ID: " << thread()->currentThreadId();
    int hashSize = m_main->hashSize();
    if (hashSize != 0) {
        int randomID = qrand() % hashSize;
        this->consume(randomID, false);
    }
}

void Consumer::consume(int id, bool collision)
{
    // Invalid ID.
    if (id == 0 || m_main->getBox(id).isNull()) {
        return;
    }
    qDebug() << "ID: " << id;

    QObject *collisionTextBox, *consumerTextBox;
    if (collision) {
        collisionTextBox = m_obj->findChild<QObject *>("collisionTextBox");
        QVariant color = QQmlProperty::read(collisionTextBox, "color");
        if (collisionTextBox) {
            if (color == "white")
                collisionTextBox->setProperty("color", "red");
            else {
                collisionTextBox->setProperty("color", "white");
            }
        }
    }
    else {
        consumerTextBox = m_obj->findChild<QObject *>("consumerTextBox");
        QVariant color = QQmlProperty::read(consumerTextBox, "color");
        if (consumerTextBox) {
            if (color == "white")
                consumerTextBox->setProperty("color", "red");
            else {
                consumerTextBox->setProperty("color", "white");
            }
        }
    }

    QVariant box = m_main->removeBox(id);
    QMetaObject::invokeMethod(m_obj, "destroyBox", Qt::QueuedConnection,
                              Q_ARG(QVariant, box));
}

void Consumer::consumeSlot(const QVariant &obj)
{
    if (m_main->getKeyFor(obj) != 0) {
        consume(m_main->getKeyFor(obj), true);
    }
    else {
        qDebug() << "Box " << obj << "already removed.";
    }
}
