#ifndef PRODUCER_H
#define PRODUCER_H
#include <QTimer>
#include "qtquick2applicationviewer.h"

class Producer : public QObject
{
    Q_OBJECT
public:
    explicit Producer(QObject* obj = 0, QObject* parent = 0);
    QTimer *timer;

public slots:
    void produceTimer() const;
private:
    QObject* m_obj;
};

#endif
