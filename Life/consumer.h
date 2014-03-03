#ifndef CONSUMER_H
#define CONSUMER_H
#include <QObject>
#include <QVariant>
#include <QDebug>
#include <QTimer>
#include <QtGlobal>
#include "producer.h"
#include "mainobject.h"

class Consumer : public QObject
{
    Q_OBJECT
public:
    explicit Consumer(QObject* obj = 0, MainObject *main = 0, QObject *parent = 0);
    QTimer *timer;
public slots:
    void startConsuming();
    void consume(int id);
private:
    QObject* m_obj;
    MainObject* m_main;
};

#endif
