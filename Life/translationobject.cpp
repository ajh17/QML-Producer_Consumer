#include "translationobject.h"

TranslationObject::TranslationObject(QObject *parent) :
    QObject(parent)
{
    m_translator = new QTranslator(this);
}

QString TranslationObject::getEmptyString()
{
    return "";
}

void TranslationObject::selectLanguage(QString lang)
{
    if (lang == QString("fr")) {
        if (m_translator->load("languages/lang_fr_FR",
                               "/Users/ajh/Developer/Cpp/QML/Life/Life/")) {
            qApp->installTranslator(m_translator);
            qDebug() << "Loaded french translation";
        }
        else {
            qDebug() << "Error loading french translation";
        }
    }
    else {
        qApp->removeTranslator(m_translator);
        qDebug() << "Switched to English translation";
    }
    emit languageChanged();
}

