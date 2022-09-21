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
    widgets \

include(../LibHimbeer/include.pri)

equals(QT_ARCH, arm64) {
    LIBS += -L/usr/lib/aarch64-linux-gnu/
}

HEADERS += \
    HimbeerMainWidget.h

SOURCES = \
    HimbeerMainWidget.cpp \
    main.cpp
