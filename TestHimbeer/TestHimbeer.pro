TARGET = testhimbeer

QT = \
    core \
    gui \
    network \
    widgets \

include(../LibHimbeer/include.pri)

SOURCES += \
    MockTcpServer.cpp \
    MockTcpSocket.cpp \
    main.cpp

HEADERS += \
    MockTcpServer.h \
    MockTcpSocket.h
