#include <QtGui/QGuiApplication>
#include <QQmlContext>
#include "qtquick2applicationviewer.h"
#include "life.h"
#include "producer.h"
#include "consumer.h"

int main(int argc, char *argv[])
{
    QGuiApplication app(argc, argv);
    QQuickView viewer;
    Life life;
    QVariant returnVal;

    viewer.setSource(QUrl::fromLocalFile("../../../../Life/qml/Life/main.qml"));
    Producer producer(viewer.rootObject());
    viewer.rootContext()->setContextProperty("consumer", new Consumer(viewer.rootObject()));
    viewer.setTitle("Life");
    viewer.setHeight(500);
    viewer.setWidth(500);

    viewer.show();

    return app.exec();
}
