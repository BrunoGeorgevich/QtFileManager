TEMPLATE = app

QT += qml quick widgets
CONFIG += c++11

HEADERS += Controller/essencials/qqmlobjectlistmodel.h \
    Controller/filemanager.h \
    Controller/directory.h \
    Controller/file.h \
    Controller/component.h

SOURCES += Controller/main.cpp \
    Controller/essencials/qqmlobjectlistmodel.cpp \
    Controller/filemanager.cpp \
    Controller/directory.cpp \
    Controller/file.cpp \
    Controller/component.cpp

RESOURCES += View/qml.qrc \
             View/essencials/components.qrc

# Additional import path used to resolve QML modules in Qt Creator's code model
QML_IMPORT_PATH =

# Default rules for deployment.
include(deployment.pri)

