#ifndef ANIMATOR_H
#define ANIMATOR_H
#include "mainobject.h"

class Animator : public QObject
{
    Q_OBJECT
public:
    explicit Animator(QObject *obj = 0, MainObject *main = 0, QObject *parent = 0);
public slots:
    void moveBox();
    void storeBox(QVariant box);
private:
    QObject* m_obj;
    MainObject* m_main;
    QVariant m_currentBox;
};

#endif
