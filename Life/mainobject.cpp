#include "mainobject.h"
#include <QDebug>

MainObject::MainObject(QObject* obj, QObject *parent) : QObject(parent)
{
    m_obj = obj;
    id = 1;
}

void MainObject::insertBox(QVariant box)
{
    boxHash.insert(id, box);
    qDebug() << "INSERTED Hash(" << id <<  "," << this->getBox(id);
    ++id;
}

QVariant MainObject::removeBox(int id)
{
    QVariant removedBox = boxHash.value(id);
    qDebug() << "REMOVED Hash( " << id << "," << removedBox << ")";
    boxHash.remove(id);
    --id;

    return removedBox;
}

QVariant MainObject::getBox(int id)
{
    return boxHash.value(id);
}

int MainObject::hashSize()
{
    return boxHash.size();
}

bool MainObject::didFind(int id)
{
    return boxHash.contains(id);
}
