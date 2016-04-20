#include "component.h"

Component::Component(QString path, Component::Type type, QObject *parent) : QObject(parent),
    m_path(path), m_type(type)
{
    if(m_type == Component::FILE)
        initFile();
    else if(m_type == Component::DIR)
        initDir();
    else
        qFatal(qPrintable("TYPE INVALID!" + type));
}

void Component::initDir()
{
    QDir d(m_path);
    if(!d.exists()) qFatal(qPrintable("PATH DOESNT EXISTS!" + m_path));
    m_name = d.dirName();
    m_isDir = true;
}

void Component::initFile()
{
    QFileInfo f(m_path);
    if(!f.exists()) qFatal(qPrintable("PATH DOESNT EXISTS!" + m_path));
    m_name = f.fileName();
    m_isDir = false;
}
