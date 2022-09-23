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
    std::shared_ptr<AbstractTcpSocket> socket = m_tcpServer->nextPendingConnection();

    connect(socket.get(),
            &AbstractTcpSocket::readyRead,
            this,
            static_cast<void (HttpServer::*)()>(&HttpServer::readFromSocket));

    if (socket->bytesAvailable() > 0)
    {
        readFromSocket(socket);
    }
}

void HttpServer::readFromSocket()
{
    auto *socket = qobject_cast<AbstractTcpSocket *>(QObject::sender());

    if (socket != nullptr)
    {
        readFromSocket(std::shared_ptr<AbstractTcpSocket>());
    }
}

void HttpServer::readFromSocket(std::shared_ptr<AbstractTcpSocket> socket)
{
    std::shared_ptr<AbstractTcpSocket> ownedSocket = std::move(socket);
    m_connectedSockets[ownedSocket] = 0;

    qDebug() << QString::fromUtf8(ownedSocket->readLine());
}
