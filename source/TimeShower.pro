QT       += core gui

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

CONFIG += c++11

# You can make your code fail to compile if it uses deprecated APIs.
# In order to do so, uncomment the following line.
#DEFINES += QT_DISABLE_DEPRECATED_BEFORE=0x060000    # disables all the APIs deprecated before Qt 6.0.0

RC_ICONS = ./resources/appIcon.ico

SOURCES += \
    backgroundwidget.cpp \
    dialog.cpp \
    main.cpp \
    messagebox.cpp \
    settings.cpp \
    sidebar.cpp \
    timewidget.cpp

HEADERS += \
    backgroundwidget.h \
    dialog.h \
    messagebox.h \
    settings.h \
    sidebar.h \
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
