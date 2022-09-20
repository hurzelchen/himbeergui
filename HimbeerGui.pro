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

SOURCES = main.cpp

DISTFILES += \
    .clang-format \
    .gitignore \
    .pre-commit-config.yaml
