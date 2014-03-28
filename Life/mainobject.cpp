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
    mutex.lock();
    boxHash.insert(id, box);
    mutex.unlock();
}

int MainObject::getKeyFor(QVariant box)
{
    mutex.lock();
    int key = boxHash.key(box);
    mutex.unlock();

    return key;
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

QVariant MainObject::getBox(int id)
{
    mutex.lock();
    QVariant box = QVariant::fromValue(boxHash.value(id));
    mutex.unlock();

    return box;
}

int MainObject::hashSize()
{
    mutex.lock();
    size_t size = boxHash.size();
    mutex.unlock();

    return size;
}

bool MainObject::didFind(int id)
{
    mutex.lock();
    bool contains =  boxHash.contains(id);
    mutex.unlock();

    return contains;
}
