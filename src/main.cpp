#include <QGuiApplication>
#include <QQmlApplicationEngine>
#include <QQmlContext>
#include <QQuickStyle>
#include "BankingController.h"

int main(int argc, char *argv[])
{
    QGuiApplication app(argc, argv);
    QGuiApplication::setApplicationName("BankingAppSmall");
    QQuickStyle::setStyle("Basic");

    BankingController controller;
    QQmlApplicationEngine engine;
    engine.rootContext()->setContextProperty("banking", &controller);
    engine.loadFromModule("BankingApp", "Main");
    if (engine.rootObjects().isEmpty())
        return -1;
    return app.exec();
}
