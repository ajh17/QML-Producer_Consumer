#include "animator.h"

Animator::Animator(QObject *obj, Consumer *consumer, MainObject *main,
                   QObject *parent) : QObject(parent)
{
    m_obj = obj;
    m_main = main;
    m_consumer = consumer;
}

void Animator::checkForCollision()
{
    QList<QVariant*> boxes = m_obj->findChildren<QVariant*>("box");

    foreach (QVariant* b, boxes) {
        qDebug() << b;
    }
}
