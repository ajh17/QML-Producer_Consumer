#ifndef PRODUCER_H
#define PRODUCER_H
#include <QTimer>

class Producer : public QObject
{
    Q_OBJECT
public:
    explicit Producer(QObject *parent = 0);
    QTimer *timer;

public slots:
    void produce();

};

#endif
