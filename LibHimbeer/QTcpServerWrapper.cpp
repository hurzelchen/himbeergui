#include "QTcpServerWrapper.h"

#include "QTcpSocketWrapper.h"

#include <QTcpServer>

class AbstractTcpSocket;
class QTcpSocket;

QTcpServerWrapper::QTcpServerWrapper(QObject *parent)
    : AbstractTcpServer(parent),
      m_implementation{new QTcpServer(parent)}
{
    connect(m_implementation, &QTcpServer::newConnection, this, &AbstractTcpServer::newConnection);
}

void QTcpServerWrapper::close()
{
    m_implementation->close();
}

bool QTcpServerWrapper::listen(const QHostAddress &address, quint16 port)
{
    return m_implementation->listen(address, port);
}

AbstractTcpSocket *QTcpServerWrapper::nextPendingConnection()
{
    QTcpSocket *socket = m_implementation->nextPendingConnection();

    if (nullptr != socket)
    {
        return new QTcpSocketWrapper(socket, this);
    }
    else
    {
        return nullptr;
    }
}
