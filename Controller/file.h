#ifndef FILE_H
#define FILE_H

#include <QObject>
#include "component.h"

class File : public Component
{
    Q_OBJECT
public:
    explicit File(QString path,QObject *parent = 0);
};

#endif // FILE_H
