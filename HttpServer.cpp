#include "HttpServer.h"

#include <QHostAddress>
#include <QTcpServer>

static const int LISTEN_PORT = 8000;

HttpServer::HttpServer(QObject *parent)
    : QObject{parent},
      m_tcpServer{new QTcpServer(this)}
{
    connect(m_tcpServer, &QTcpServer::newConnection, this, &HttpServer::newConnection);
}

void HttpServer::close()
{
    m_tcpServer->close();
}

bool HttpServer::listen()
{
    return m_tcpServer->listen(QHostAddress::Any, LISTEN_PORT);
}
