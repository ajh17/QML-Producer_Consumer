#ifndef CONSUMER_H
#define CONSUMER_H
#include <QObject>
#include <QVariant>
#include <QDebug>

class Consumer : public QObject
{
    Q_OBJECT
public:
    explicit Consumer(QObject* obj = 0, QObject *parent = 0);

signals:

public slots:
    void consumeBox(const QVariant &obj);
private:
    QObject* m_obj;
};

#endif
