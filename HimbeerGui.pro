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

equals(QT_ARCH, arm64) {
    LIBS += -L/usr/lib/aarch64-linux-gnu/
}

HEADERS += \
    HimbeerMainWidget.h \
    HttpServer.h

SOURCES = main.cpp \
    HimbeerMainWidget.cpp \
    HttpServer.cpp

OTHER_FILES += \
    .clang-format \
    .clang-tidy \
    .gitignore \
    .iwyu-mapping.imp \
    .pre-commit-config.yaml \
    .uncrustify.cfg
