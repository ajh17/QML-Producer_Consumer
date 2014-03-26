#ifndef CONSUMER_H
#define CONSUMER_H
#include <QTimer>
#include <QThread>
#include <QMutex>
#include "mainobject.h"

class Consumer : public QObject
{
    Q_OBJECT
public:
    explicit Consumer(QObject *obj = 0, MainObject *main = 0, QObject *parent = 0);
    QTimer *timer;
public slots:
    void consumeSlot(const QVariant &obj)
    {
        qDebug() << "Called consumeSlot!";
        consume(m_main->getKeyFor(obj), this->thread()->currentThreadId());
    }
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
