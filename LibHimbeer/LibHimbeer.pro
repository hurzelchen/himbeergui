TEMPLATE = lib

TARGET = himbeer

QT = \
    core \
    gui \
    network \
    widgets \

HEADERS += \
    AbstractHttpRoute.h \
    AbstractTcpServer.h \
    AbstractTcpSocket.h \
    HttpGet.h \
    HttpPost.h \
    HttpRoute.h \
    HttpServer.h \
    QTcpServerWrapper.h \
    QTcpSocketWrapper.h

SOURCES += \
    AbstractHttpRoute.cpp \
    AbstractTcpServer.cpp \
    AbstractTcpSocket.cpp \
    HttpGet.cpp \
    HttpPost.cpp \
    HttpRoute.cpp \
    HttpServer.cpp \
    QTcpServerWrapper.cpp \
    QTcpSocketWrapper.cpp

OTHER_FILES += \
    include.pri

include(../Global.pri)

DISTFILES += \
    LibHimbeer.pri
