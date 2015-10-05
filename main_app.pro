#-------------------------------------------------
#
# Project created by QtCreator 2015-10-04T00:30:46
#
#-------------------------------------------------

QT       += core gui webkitwidgets multimedia

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

TARGET = main_app
TEMPLATE = app


SOURCES += main.cpp\
        mainwindow.cpp \
    widgetKeyboard2015/keyboard/QKeyPushButton.cpp \
    widgetKeyboard2015/keyboard/widgetKeyBoard.cpp

HEADERS  += mainwindow.h \
    widgetKeyboard2015/keyboard/QKeyPushButton.h \
    widgetKeyboard2015/keyboard/widgetKeyBoard.h

FORMS    +=

DISTFILES += \
    webview_stylesheets.qml

RESOURCES += \
    resources.qrc
