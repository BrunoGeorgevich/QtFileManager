#include "directory.h"

Directory::Directory(QString path, QString parentPath, QObject *parent) :
    Component(path, Component::DIR,parent),m_parentPath(parentPath)
{
    m_content = new QQmlObjectListModel<Component>(this);
    m_dir = new QDir(get_path());
    m_isRoot = (parentPath == "#root#") ? true : false;
}

void Directory::populateContent()
{
    QStringList fileList = m_dir->entryList(QDir::Files);
    QStringList dirList = m_dir->entryList(QDir::NoDotAndDotDot | QDir::Dirs);
    foreach (QString file, fileList)
        m_content->append(new File(m_dir->absoluteFilePath(file),this));
    foreach (QString dir, dirList)
        m_content->append(new Directory(m_dir->filePath(dir),get_path(),this));
    qDebug() << "Populate Content in" << get_name();
}

