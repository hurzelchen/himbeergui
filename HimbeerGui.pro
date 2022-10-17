TEMPLATE = subdirs
CONFIG += ordered

SUBDIRS = \
    LibHimbeer \
    HimbeerGui \
    TestHimbeer

OTHER_FILES += \
    .clang-format \
    .clang-tidy \
    .gitignore \
    .iwyu-mapping.imp \
    .pre-commit-config.yaml \
    mkspecs/linux-xcompile-aarch64-gnu-g++/qmake.conf \
    mkspecs/linux-xcompile-aarch64-gnu-g++/qplatformdefs.h \
    mkspecs/linux-xcompile-aarch64-gnu-g++/qt_config.prf \
    Global.pri
