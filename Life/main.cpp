#include <QtGui/QGuiApplication>
#include <QQmlContext>
#include "qtquick2applicationviewer.h"
#include "life.h"

int main(int argc, char *argv[])
{
    QGuiApplication app(argc, argv);
    QQuickView viewer;
    Life life;
    QVariant returnVal;
    QVariant message = "Hello from C++";

    viewer.rootContext()->setContextProperty("_life", &life);
    viewer.setSource(QUrl::fromLocalFile("../../../../Life/qml/Life/main.qml"));
    viewer.setTitle("Life");
    viewer.setHeight(120);
    viewer.setWidth(120);

    QObject *object = viewer.rootObject()->findChild<QObject*>("box1");
    QObject *root = viewer.rootObject();
    QMetaObject::invokeMethod(root, "test", Q_RETURN_ARG(QVariant, returnVal),
                                            Q_ARG(QVariant, message));
    if (object) {
        object->setProperty("color", "red");
    }
    else {
        qDebug() << "Object not found";
    }

    viewer.show();
    return app.exec();
}
