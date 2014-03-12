#ifndef ANIMATOR_H
#define ANIMATOR_H
#include <QTimer>
#include <QThread>
#include <QMutex>
#include "consumer.h"

/* For now, really basic */
class Animator : public QObject
{
    Q_OBJECT
public:
    explicit Animator(QObject *obj = 0, Consumer *consumer = 0, MainObject *main = 0,
                      QObject *parent = 0);
    QTimer *timer;
public slots:
    /**
     * Checks for collisions and destroys two objects if they collide.
     */
    void checkForCollision();
private:
    QObject *m_obj;
    MainObject *m_main;
    Consumer* m_consumer;
    QMutex mutex;
};

#endif
