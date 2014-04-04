#ifndef TRANSLATIONOBJECT_H
#define TRANSLATIONOBJECT_H
#include <QtGui>
#include <QObject>
#include <QTranslator>

class TranslationObject : public QObject
{
    Q_OBJECT
    Q_PROPERTY(QString emptyString READ getEmptyString NOTIFY languageChanged)
public:
    TranslationObject();
public slots:
    QString getEmptyString();
    Q_INVOKABLE void selectLanguage(QString lang);
signals:
    void languageChanged();
private:
    QTranslator *m_translator;
};
#endif
