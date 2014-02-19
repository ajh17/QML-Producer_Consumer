#include "producer.h"
#include <QDebug>

Producer::Producer(QObject *parent) : QObject(parent)
{
    timer = new QTimer(this);

    connect(timer, SIGNAL(timeout()), this, SLOT(produce()));
    timer->start(1000);
}

void Producer::produce()
{
    qDebug() << "Timer tick";
}
