#include "avoider.h"

Avoider::Avoider(QObject *obj, MainObject *main, Consumer *consumer,
                 QObject *parent) : QObject(parent)
{
    timer = new QTimer(this);
    m_obj = obj;
    m_main = main;
    m_consumer = consumer;

    connect(timer, SIGNAL(timeout()), this, SLOT(checkForCollision()));
    timer->start(1000);
}

void Avoider::checkForCollision()
{
    if (!m_obj) {
        qDebug() << "Viewer was null";
        return;
    }

    qDebug() << "Avoider Thread ID: " << thread()->currentThreadId();
    QList<QObject *> boxes = m_obj->findChildren<QObject *>("box",
                             Qt::FindChildrenRecursively);
    QMap<QObject *, bool> boxesMap;

    // Iterators
    QList<QObject *>::const_iterator itr = boxes.constBegin();
    QMap<QObject *, bool>::iterator boxesItr1;
    QMap<QObject *, bool>::iterator boxesItr2;

    while (itr != boxes.constEnd()) {
        boxesMap.insert(*itr++, true);
    }
    boxesItr1 = boxesMap.begin();
    boxesItr2 = boxesMap.begin();

    while (boxesItr1.value() && boxesItr1 != boxesMap.end()) {
        QVariant temp1 = QQmlProperty::read(boxesItr1.key(), "x");
        QVariant temp2 = QQmlProperty::read(boxesItr1.key(), "y");
        double bx = temp1.toDouble();
        double by = temp2.toDouble();

        while (boxesItr2.value() && boxesItr2 != boxesMap.end()) {
            if (boxesItr2.key() != boxesItr1.key()) {
                double ix = QQmlProperty::read(boxesItr2.key(), "x").toDouble();
                double iy = QQmlProperty::read(boxesItr2.key(), "y").toDouble();

                if ((abs(ix - bx) <= 50) || (abs(iy - by) <= 50)) {
                    QVariant box2 = QVariant::fromValue(boxesItr2.key());
                    int id2 = m_main->getKeyFor(box2);

                    boxesMap.insert(boxesItr1.key(), false);
                    boxesMap.insert(boxesItr2.key(), false);

                    m_consumer->consume(id2, thread()->currentThreadId());
                }
            }
            ++boxesItr2;
        }
        ++boxesItr1;
    }
}
