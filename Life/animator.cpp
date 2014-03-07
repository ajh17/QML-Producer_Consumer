#include "animator.h"

Animator::Animator(QObject *obj, MainObject *main, QObject *parent) : QObject(parent)
{
    m_obj = obj;
    m_main = main;
    m_currentBox = 0;
}

void Animator::storeBox(QVariant box)
{
    m_currentBox = box;
}

void Animator::moveBox()
{
    QVariant box;
    QVariant movedBox;

    int key = m_main->getKeyFor(box);

    // Update the hash
    QMetaObject::invokeMethod(m_obj, "moveBox", Q_RETURN_ARG(QVariant, box),
                              Q_ARG(QVariant, movedBox));
    m_main->updateHash(key, movedBox);
}
