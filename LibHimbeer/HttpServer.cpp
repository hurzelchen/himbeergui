#include "HttpServer.h"

#include "AbstractTcpServer.h"
#include "QTcpServerWrapper.h"
#include "QTcpSocketWrapper.h"

#include <QHostAddress>
#include <QTcpServer>
#include <QtGlobal>

static const int LISTEN_PORT = 8000;

HttpServer::HttpServer(QObject *parent)
    : QObject{parent},
      AbstractHttpRoute(nullptr),
      m_tcpServer{new QTcpServerWrapper(this)}
{
    connect(m_tcpServer, &AbstractTcpServer::newConnection, this, &HttpServer::newConnection);
}

HttpServer::HttpServer(AbstractTcpServer *replacementTcpServer, QObject *parent)
    : QObject{parent},
      m_tcpServer{replacementTcpServer}
{
}

void HttpServer::close()
{
    m_tcpServer->close();
}

bool HttpServer::listen()
{
    return m_tcpServer->listen(QHostAddress::Any, LISTEN_PORT);
}

void HttpServer::newConnection()
{
    AbstractTcpSocket *socket = m_tcpServer->nextPendingConnection();

    // TODO(hurzelchen): implement
    Q_UNUSED(socket);
}
