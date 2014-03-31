#ifndef CONSUMER_H
#define CONSUMER_H
#include <QTimer>
#include <QThread>
#include "mainobject.h"

class Consumer : public QObject
{
    Q_OBJECT
public:
    explicit Consumer(QObject *obj = 0, MainObject *main = 0, QObject *parent = 0);
    QTimer *timer;
public slots:
    void startConsuming();
    void consume(int id, Qt::HANDLE threadID, bool collision);
    Q_INVOKABLE void consumeSlot(const QVariant &obj);
private:
    QObject *m_obj;
    Qt::HANDLE m_threadID;
    MainObject *m_main;
};
#endif
