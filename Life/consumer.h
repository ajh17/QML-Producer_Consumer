#ifndef CONSUMER_H
#define CONSUMER_H
#include <QObject>

class Consumer : public QObject
{
    Q_OBJECT
public:
    explicit Consumer(QObject* obj = 0, QObject *parent = 0);
    Q_INVOKABLE void consumeBox();

signals:

public slots:

private:
    QObject* m_obj;
};

#endif
