#include "mainobject.h"

MainObject::MainObject(QObject* obj, QObject *parent) : QObject(parent)
{
    m_obj = obj;
    id = 1;
}

void MainObject::insertBox(QVariant box)
{
    boxHash.insert(id, box);
    id += 1;
}

QVariant MainObject::getBox(int id)
{
    return boxHash.value(id);
}

int MainObject::hashSize()
{
    return boxHash.size();
}
