#include "life.h"

Life::Life(QObject *parent) :
    QObject(parent)
{
    m_color = "white";
}

void Life::setBackgroundColor(const QColor &c)
{
    if (c != m_color) {
        m_color = c;
        emit backgroundColorChanged();
    }
}

QColor Life::backgroundColor() const
{
    return m_color;
}
