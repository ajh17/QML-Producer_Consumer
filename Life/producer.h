#ifndef PRODUCER_H
#define PRODUCER_H

#include <QObject>

class Producer : public QObject
{
    Q_OBJECT
public:
    explicit Producer(QObject *parent = 0);

signals:

public slots:

};

#endif // PRODUCER_H
