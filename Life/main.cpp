#include <QtGui/QGuiApplication>
#include <QQmlContext>
#include "qtquick2applicationviewer.h"
#include "life.h"
#include "producer.h"

int main(int argc, char *argv[])
{
    QGuiApplication app(argc, argv);
    QQuickView viewer;
    Life life;
    Producer producer;
    QVariant returnVal;
    QVariant message = "Hello from C++";

    viewer.rootContext()->setContextProperty("_life", &life);
    viewer.setSource(QUrl::fromLocalFile("../../../../Life/qml/Life/main.qml"));
    viewer.setTitle("Life");
    viewer.setHeight(500);
    viewer.setWidth(500);

    QObject *root = viewer.rootObject();
    QMetaObject::invokeMethod(root, "callCreate", Q_RETURN_ARG(QVariant, returnVal));
    viewer.show();
    return app.exec();
}
