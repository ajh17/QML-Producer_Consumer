#include "mainobject.h"

MainObject::MainObject(QObject *obj, QObject *parent) : QObject(parent)
{
    m_obj = obj;
    id = 1;
}

void MainObject::insertBox(QVariant box)
{
    boxHash.insert(id, box);
    qDebug() << "\n+++>> INSERTED Hash(" << id <<  "," << this->getBox(id) << "\n";
    ++id;
}

void MainObject::updateHash(int id, QVariant box)
{
    boxHash.insert(id, box);
}

int MainObject::getKeyFor(QVariant box)
{
    return boxHash.key(box);
}

QList<int> MainObject::getKeys()
{
    return boxHash.keys();
}

QVariant MainObject::removeBox(int id)
{
    QVariant removedBox = boxHash.value(id);
    qDebug() << "\n<<--- REMOVED Hash(" << id << "," << removedBox << "\n";
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

