#include "HttpServer.h"

#include "AbstractTcpServer.h"
#include "QTcpServerWrapper.h"
#include "QTcpSocketWrapper.h"

#include <QHostAddress>
#include <QTcpServer>
#include <QtGlobal>

#include <utility>

static const int LISTEN_PORT = 8000;

HttpServer::HttpServer(QObject *parent)
    : QObject{parent},
      m_tcpServer{std::make_shared<QTcpServerWrapper>(this)}
{
    connect(m_tcpServer.get(), &AbstractTcpServer::newConnection, this, &HttpServer::newConnection);
}

HttpServer::HttpServer(std::shared_ptr<AbstractTcpServer> replacementTcpServer, QObject *parent)
    : QObject{parent},
      m_tcpServer{std::move(replacementTcpServer)}
{
    connect(m_tcpServer.get(), &AbstractTcpServer::newConnection, this, &HttpServer::newConnection);
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
