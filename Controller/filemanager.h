#ifndef FILEMANAGER_H
#define FILEMANAGER_H

#include <QDesktopServices>
#include <QObject>
#include <QUrl>

#include "directory.h"

class FileManager : public QObject
{
    Q_OBJECT
    QML_READONLY_PROPERTY(Directory*,root)
    QML_READONLY_PROPERTY(Directory*,current)
public:
    explicit FileManager(QString path, QObject *parent = 0);
    Q_INVOKABLE void cd(QString name);
    Q_INVOKABLE void cdUp();
    Q_INVOKABLE void openFile(QString name);
signals:
    void refreshList();
    void updateStatusBar(QString message);
};

#endif // FILEMANAGER_H
