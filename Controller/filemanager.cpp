#include "filemanager.h"

FileManager::FileManager(QString path, QObject *parent) : QObject(parent)
{
    m_root = new Directory(path,"#root#",this);
    m_current = m_root;
    m_current->populateContent();
}

void FileManager::cd(QString name)
{
    QString currentPath = m_current->get_path();
    if(name!="/")
        m_current = new Directory(m_current->get_dir()->absoluteFilePath(name),currentPath,this);
    else
        m_current = new Directory(m_current->get_dir()->absoluteFilePath(name),"#root#",this);
    m_current->populateContent();
    emit refreshList();
    emit updateStatusBar("Changing directory to " + m_current->get_path());
}

void FileManager::cdUp()
{
    cd(m_current->get_parentPath());
}

void FileManager::openFile(QString name)
{
    qDebug() << "Opening the file:" << name;
    QDesktopServices::openUrl(QUrl("file://" + m_current->get_dir()->absoluteFilePath(name)));
    emit updateStatusBar("Open file " + name);
}

