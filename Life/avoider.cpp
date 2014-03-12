#include "animator.h"

Animator::Animator(QObject *obj, Consumer *consumer, MainObject *main,
                   QObject *parent) : QObject(parent)
{
    timer = new QTimer(this);
    m_obj = obj;
    m_main = main;
    m_consumer = consumer;

    connect(timer, SIGNAL(timeout()), this, SLOT(checkForCollision()));
    timer->start(2000);
}

void Animator::checkForCollision()
{
    QList<QObject *> boxes = m_obj->findChildren<QObject *>("box");
    QList<QObject *> boxesCopy = m_obj->findChildren<QObject *>("box");
    QList<QObject *>::iterator itr;

    // Algorithm is currently O(n^2)
    // TODO: Make this better.
    foreach(QObject * b, boxesCopy) {
        for (itr = boxes.begin(); itr != boxes.end(); ++itr) {
            if (*itr != b) {
                // Check bounds of the box comparing it to every other box.

            }
        }
    }
}
