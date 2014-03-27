#ifndef CONSUMER_H
#define CONSUMER_H
#include <QTimer>
#include <QThread>
#include <QMutex>
#include <QVariant>
#include "mainobject.h"

class Consumer : public QObject
{
    Q_OBJECT
public:
    explicit Consumer(QObject *obj = 0, MainObject *main = 0, QObject *parent = 0);
    QTimer *timer;
    Q_INVOKABLE void consumeSlot(QVariant &obj);
public slots:
    void startConsuming();
    void consume(int id, Qt::HANDLE threadID);
    void testSlot()
    {
        qDebug() << "It works!";
    }
private:
    QObject *m_obj;
    MainObject *m_main;
    Qt::HANDLE m_threadID;
    QMutex mutex;
};

#endif
