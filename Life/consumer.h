#ifndef CONSUMER_H
#define CONSUMER_H
#include <QTimer>
#include <QThread>
#include "mainobject.h"

class Consumer : public QObject
{
    Q_OBJECT
public:
    explicit Consumer(MainObject *main = 0, QObject *parent = 0);
    QTimer *timer;
public slots:
    void startConsuming();
    void consume(int id, Qt::HANDLE threadID, bool collision);
    Q_INVOKABLE void consumeSlot(const QVariant &obj);
signals:
    void collisionSignal(QVariant box);
    void consumedSignal(QVariant box);
private:
    Qt::HANDLE m_threadID;
    MainObject *m_main;
};
#endif
