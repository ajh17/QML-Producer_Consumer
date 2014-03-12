#ifndef MAINOBJECT_H
#define MAINOBJECT_H
#include <QObject>
#include <QDebug>
#include <QVariant>

class MainObject : public QObject
{
    Q_OBJECT
public:
    explicit MainObject(QObject *obj = 0, QObject *parent = 0);
    QHash<int, QVariant> boxHash;
public slots:
    void insertBox(QVariant box);
    void updateHash(int id, QVariant box);
    int getKeyFor(QVariant box);
    QList<int> getKeys();
    QVariant removeBox(int id);
    int hashSize();
    QVariant getBox(int id);
    bool didFind(int id);
private:
    QObject *m_obj;
    int id;
};
#endif

