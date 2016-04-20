#ifndef DIRECTORY_H
#define DIRECTORY_H

#include <QStringList>
#include <QObject>
#include <QDir>

#include "essencials/qqmlobjectlistmodel.h"
#include "component.h"
#include "file.h"

class Directory : public Component
{
    Q_OBJECT
    QML_OBJMODEL_PROPERTY(Component,content)
    QML_READONLY_PROPERTY(QDir*,dir)
    QML_READONLY_PROPERTY(QString,parentPath)
    QML_READONLY_PROPERTY(bool, isRoot)
public:
    explicit Directory(QString path, QString parentPath, QObject *parent = 0);
    void populateContent();
};

#endif // DIRECTORY_H
