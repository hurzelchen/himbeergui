TEMPLATE = app

CONFIG(debug, debug|release) {
    TARGET = himbeerguidbg
} else {
    TARGET = himbeergui
}

QT = \
    core \
    gui \
    network \
    webenginewidgets \
    widgets \

HEADERS += \
    AbstractHimbeerWidget.h \
    HimbeerMainWidget.h \
    JsClockWidget.h

SOURCES = \
    AbstractHimbeerWidget.cpp \
    HimbeerMainWidget.cpp \
    JsClockWidget.cpp \
    main.cpp

RESOURCES += \
    HimbeerGui.qrc

include(../LibHimbeer/LibHimbeer.pri)
include(../Global.pri)
