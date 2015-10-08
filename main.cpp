#include <QGuiApplication>
#include <QQmlApplicationEngine>
#include <QQmlContext>

#include "gamemanager.h"

#define DEBUG

int main(int argc, char *argv[])
{
    QGuiApplication app(argc, argv);
    QQmlApplicationEngine engine;

    auto root_context = engine.rootContext();

    //game objects
    ScoreSystem mScore;
    GameManager mManager(&mScore);


    root_context->setContextProperty("ccManager", &mManager);
    root_context->setContextProperty("ccScore", &mScore);


    engine.load(QUrl(QStringLiteral("qrc:/main.qml")));

    return app.exec();
}

