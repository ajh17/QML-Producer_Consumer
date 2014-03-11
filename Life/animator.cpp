#include "animator.h"

Animator::Animator(QObject *obj, MainObject *main, QObject *parent) : QObject(parent)
{
    m_obj = obj;
    m_main = main;
}

void Animator::checkForCollision(const QVariant &obj)
{
    qDebug() << "recieved";
}

