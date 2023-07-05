#include "desktopwindow.h"

#include <QApplication>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    DesktopWindow w;
    w.show();
//    QGuiApplication app(argc, argv);
//    QQmlApplicationEngine engine;
//    engine.load(QUrl("qrc:/Quick/SlideMode.qml"));
//    if (engine.rootObjects().isEmpty())
//        return -1;
    return a.exec();
}
