#-------------------------------------------------
#
# Project created by QtCreator 2022-07-29T16:13:32
#
#-------------------------------------------------

QT       += core gui

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

TARGET = kaifa
TEMPLATE = app

# The following define makes your compiler emit warnings if you use
# any feature of Qt which as been marked as deprecated (the exact warnings
# depend on your compiler). Please consult the documentation of the
# deprecated API in order to know how to port your code away from it.
DEFINES += QT_DEPRECATED_WARNINGS

# You can also make your code fail to compile if you use deprecated APIs.
# In order to do so, uncomment the following line.
# You can also select to disable deprecated APIs only up to a certain version of Qt.
#DEFINES += QT_DISABLE_DEPRECATED_BEFORE=0x060000    # disables all the APIs deprecated before Qt 6.0.0


SOURCES += \
        main.cpp \
        mainwindow.cpp \
    manager.cpp \
    zhucejiemian.cpp \
    user.cpp \
    mycombobox.cpp \
    chengyuan.cpp \
    add.cpp \
    sub.cpp \
    shenqing.cpp \
    zhuchejiemian1.cpp \
    qingkuang.cpp

HEADERS += \
        mainwindow.h \
    manager.h \
    zhucejiemian.h \
    user.h \
    mycombobox.h \
    chengyuan.h \
    add.h \
    sub.h \
    shenqing.h \
    zhuchejiemian1.h \
    qingkuang.h

FORMS += \
        mainwindow.ui \
    manager.ui \
    zhucejiemian.ui \
    user.ui \
    chengyuan.ui \
    add.ui \
    sub.ui \
    shenqing.ui \
    zhuchejiemian1.ui \
    qingkuang.ui

RESOURCES += \
    image.qrc
