#ifndef PRODUCER_H
#define PRODUCER_H
#include <QTimer>
#include <QHash>
#include <QVariant>
#include <QQuickItem>
#include "qtquick2applicationviewer.h"
#include "mainobject.h"

class Producer : public QObject
{
    Q_OBJECT
public:
    explicit Producer(QObject* obj = 0, MainObject* main = 0, QObject* parent = 0);
    QTimer *timer;
    QHash<int, QVariant> hash;
public slots:
    void produceTimer();
    int hashSize();
    QVariant getItem(int id);
private:
    QObject* m_obj;
    MainObject* m_main;
    int id;
};
#endif
