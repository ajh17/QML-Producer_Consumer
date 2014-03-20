#ifndef AVOIDER_H
#define AVOIDER_H
#include <QTimer>
#include <QQmlProperty>
#include "consumer.h"

/* For now, really basic */
class Avoider : public QObject
{
    Q_OBJECT
public:
    explicit Avoider(QObject *obj = 0, MainObject *main = 0,
                     Consumer *consumer = 0, QObject *parent = 0);
    QTimer *timer;
public slots:
    void checkForCollision();
private:
    QObject *m_obj;
    MainObject *m_main;
    Consumer *m_consumer;
};

#endif

