INCLUDEPATH += \
    $${PWD}/../LibHimbeer/

message($$QMAKE_LIBDIR)

LIBS += \
    -L$${OUT_PWD}/../LibHimbeer/ -lhimbeer
