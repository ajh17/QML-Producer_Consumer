#include "mainobject.h"

MainObject::MainObject(QObject *parent) : QObject(parent)
{
    id = 1;
}

void MainObject::insertBox(QVariant box)
{
    mutex.lock();
    boxHash.insert(id, box);
    qDebug() << "\n+++>> INSERTED Hash(" << id <<  "," << boxHash.value(id) << "\n";
    ++id;
    mutex.unlock();
}

int MainObject::getKeyFor(QVariant box)
{
    mutex.lock();
    int key = boxHash.key(box);
    mutex.unlock();

    return key;
}

QVariant MainObject::getBox(int id)
{
    mutex.lock();
    QVariant box = QVariant::fromValue(boxHash.value(id));
    mutex.unlock();

    return box;
}

QList<int> MainObject::getKeys()
{
    mutex.lock();
    QList<int> keyList = boxHash.keys();
    mutex.unlock();

    return keyList;
}

QVariant MainObject::removeBox(int id)
{
    mutex.lock();
    QVariant removedBox = boxHash.value(id);
    qDebug() << "\n<<--- REMOVED Hash(" << id << "," << removedBox << "\n";
    boxHash.remove(id);
    --id;
    mutex.unlock();

    return removedBox;
}

int MainObject::hashSize()
{
    return boxHash.size();
}

bool MainObject::didFind(int id)
{
    mutex.lock();
    bool contains =  boxHash.contains(id);
    mutex.unlock();

    return contains;
}
