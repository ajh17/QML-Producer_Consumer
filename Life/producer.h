#ifndef PRODUCER_H
#define PRODUCER_H
#include <QTimer>
#include <QThread>
#include "mainobject.h"

class Producer : public QObject
{
    Q_OBJECT
public:
    explicit Producer(QObject *obj = 0, MainObject *main = 0, QObject *parent = 0);
    QTimer *timer;
    QTimer *timer2;
public slots:
    void produceTimer();
    void clear();
signals:
    void clearSignal();
private:
    QObject *m_obj;
    MainObject *m_main;
};
#endif
