#ifndef COMPONENT_H
#define COMPONENT_H

#include <QFileInfo>
#include <QObject>
#include <QDebug>
#include <QFile>
#include <QDir>

#include "essencials/qqmlhelpers.h"

class Component : public QObject
{
    Q_OBJECT
public:
    enum Type { FILE, DIR };
private:
    Q_ENUM(Type)
    QML_READONLY_PROPERTY(QString,path)
    QML_READONLY_PROPERTY(QString,name)
    QML_READONLY_PROPERTY(Type,type)
    QML_READONLY_PROPERTY(bool, isDir)
public:
    explicit Component(QString path, Type type, QObject *parent = 0);
private:
    void initDir();
    void initFile();
};

#endif // COMPONENT_H
