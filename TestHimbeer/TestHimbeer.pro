TARGET = testhimbeer

QT = \
    core \
    gui \
    network \
    widgets \

SOURCES += \
    MockTcpServer.cpp \
    MockTcpSocket.cpp \
    main.cpp

HEADERS += \
    MockTcpServer.h \
    MockTcpSocket.h

include(../LibHimbeer/LibHimbeer.pri)
include(../Global.pri)
