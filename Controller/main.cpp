#include <QQmlContext>
#include <QApplication>
#include <QQmlApplicationEngine>

#include "filemanager.h"

int main(int argc, char *argv[])
{
    QApplication app(argc, argv);

    QQmlApplicationEngine engine;
    QQmlContext *ctx = engine.rootContext();
    FileManager *fm = new FileManager("/");
    ctx->setContextProperty("_fileManager",fm);
    engine.load(QUrl(QStringLiteral("qrc:/main.qml")));

    return app.exec();
}

