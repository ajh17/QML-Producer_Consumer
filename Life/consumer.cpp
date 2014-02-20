#include "consumer.h"
#include <QDebug>

Consumer::Consumer(QObject* obj, QObject *parent) : QObject(parent)
{
    m_obj = obj;
}

void Consumer::consumeBox() {
    if (!m_obj) {
        qDebug() << "Object was null";
    }
    else {
        QVariant returnVal;
        QMetaObject::invokeMethod(m_obj, "destroyBox",
                Q_RETURN_ARG(QVariant, returnVal));
    }
}


// TESTING CODE
/* if (m_obj) { */
/*     QObject* box = m_obj->findChild<QObject*>("box"); */
/*     box->setProperty("color", "red"); */
/*     qDebug() << "Destroying box"; */
/* } */
/* else { */
/*     qDebug() << "Object was null"; */
/* } */
