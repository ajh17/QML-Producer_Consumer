#include "avoider.h"

Avoider::Avoider(QObject *obj, MainObject *main, Consumer *consumer,
                 QObject *parent) : QObject(parent)
{
    timer = new QTimer(this);
    m_obj = obj;
    m_main = main;
    m_consumer = consumer;

    connect(timer, SIGNAL(timeout()), this, SLOT(checkForCollision()));
    timer->start(2000);
}

void Avoider::checkForCollision()
{
    QList<QObject *> boxes = m_obj->findChildren<QObject *>("box");
    QList<QObject *>::iterator itr;

    // Algorithm is currently O(n^2)
    // TODO: Make this better.
    foreach(QObject *b, boxes) {
        QVariant temp1 = QQmlProperty::read(b, "x");
        QVariant temp2 = QQmlProperty::read(b, "y");
        double bx = temp1.toDouble();
        double by = temp2.toDouble();

        for (itr = boxes.begin(); itr != boxes.end(); ++itr) {
            if (*itr != b) {
                QVariant temp3 = QQmlProperty::read(*itr, "x");
                QVariant temp4 = QQmlProperty::read(*itr, "y");
                double ix = temp3.toDouble();
                double iy = temp4.toDouble();

                if ((abs(ix - bx) <= 50) || (abs(iy - by) <= 50)) {
                    QVariant returnVal;
                    QVariant box = QVariant::fromValue(b);
                    QVariant box2 = QVariant::fromValue(*itr);
                    int id = m_main->getKeyFor(box);
                    int id2 = m_main->getKeyFor(box2);

                    boxes.removeOne(b);
                    boxes.removeOne(*itr);

                    qDebug() << "Deleting " << box << "ID: " << id;
                    m_consumer->consume(id);
                    qDebug() << "Deleting " << box2 << "ID: " << id2;
                    m_consumer->consume(id2);
                }
            }
        }
    }
}

