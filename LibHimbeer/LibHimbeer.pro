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
    HttpGet.h \
    HttpPost.h \
    HttpRoute.h \
    HttpServer.h \
    QTcpServerWrapper.h

SOURCES += \
    AbstractHttpRoute.cpp \
    AbstractTcpServer.cpp \
    HttpGet.cpp \
    HttpPost.cpp \
    HttpRoute.cpp \
    HttpServer.cpp \
    QTcpServerWrapper.cpp
