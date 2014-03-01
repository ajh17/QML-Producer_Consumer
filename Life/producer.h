#ifndef PRODUCER_H
#define PRODUCER_H
#include <QTimer>
#include <QHash>
#include <QVariant>
#include <QQuickItem>
#include "qtquick2applicationviewer.h"

class Producer : public QObject
{
    Q_OBJECT
public:
    explicit Producer(QObject* obj = 0, QObject* parent = 0);
    QTimer *timer;
    QHash<int, QVariant> hash;
public slots:
    void produceTimer();
public:
    int hashSize();
private:
    QObject* m_obj;
    int id;
};
#endif
