#ifndef LIFE_H
#define LIFE_H

#include <QQuickItem>
#include <QObject>
#include <QDebug>

class Life : public QObject
{
    Q_OBJECT
    Q_PROPERTY(QColor backgroundColor
               READ backgroundColor
               WRITE setBackgroundColor
               NOTIFY backgroundColorChanged)
public:
    explicit Life(QObject *parent = 0);
    void setBackgroundColor(const QColor &c);
    QColor backgroundColor() const;
    void changeState();

signals:
    void backgroundColorChanged();

private:
    QColor m_color;
};

#endif
