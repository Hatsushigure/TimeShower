QT += core gui

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets
greaterThan(QT_MAJOR_VERSION, 5): QT += core5compat

CONFIG += c++11

# You can make your code fail to compile if it uses deprecated APIs.
# In order to do so, uncomment the following line.
DEFINES += QT_DISABLE_DEPRECATED_BEFORE=0x060000    # disables all the APIs deprecated before Qt 6.0.0

RC_ICONS = ./resources/appIcon.ico
VERSION = 1.2.4
QMAKE_TARGET_PRODUCT = TimeShower
QMAKE_TARGET_COMPANY = czj_____
QMAKE_TARGET_DESCRIPTION = TimeShower
QMAKE_TARGET_COPYRIGHT = czj_____

SOURCES += \
    backgroundwidget.cpp \
    dialog.cpp \
    globals.cpp \
    main.cpp \
    messagebox.cpp \
    settings.cpp \
    sidebar.cpp \
    timeevent.cpp \
    timeeventmanager.cpp \
    timewidget.cpp

HEADERS += \
    backgroundwidget.h \
    dialog.h \
    globals.h \
    messagebox.h \
    settings.h \
    sidebar.h \
    timeevent.h \
    timeeventmanager.h \
    timeshower.h \
    timewidget.h

FORMS += \
    backgroundwidget.ui \
    dialog.ui \
    sidebar.ui \
    timewidget.ui

# Default rules for deployment.
qnx: target.path = /tmp/$${TARGET}/bin
else: unix:!android: target.path = /opt/$${TARGET}/bin
!isEmpty(target.path): INSTALLS += target

RESOURCES += \
    resources.qrc

DISTFILES +=
