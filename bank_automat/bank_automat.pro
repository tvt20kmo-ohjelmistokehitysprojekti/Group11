QT       += core gui

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

CONFIG += c++11

# You can make your code fail to compile if it uses deprecated APIs.
# In order to do so, uncomment the following line.
#DEFINES += QT_DISABLE_DEPRECATED_BEFORE=0x060000    # disables all the APIs deprecated before Qt 6.0.0

SOURCES += \
    action.cpp \
    balance.cpp \
    main.cpp \
    mainwindow.cpp \
    menu.cpp \
    withdraw.cpp

HEADERS += \
    action.h \
    balance.h \
    mainwindow.h \
    menu.h \
    withdraw.h

FORMS += \
    action.ui \
    balance.ui \
    mainwindow.ui \
    menu.ui \
    withdraw.ui

# Default rules for deployment.
qnx: target.path = /tmp/$${TARGET}/bin
else: unix:!android: target.path = /opt/$${TARGET}/bin
!isEmpty(target.path): INSTALLS += target

QT += network
