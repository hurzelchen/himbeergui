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
    Global.pri
