#include "QTcpServerWrapper.h"

#include "QTcpSocketWrapper.h"

#include <QTcpServer>
#include <QTcpSocket>

#include <memory>

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

std::unique_ptr<AbstractTcpSocket> QTcpServerWrapper::nextPendingConnection()
{
    QTcpSocket *socket = m_implementation->nextPendingConnection();

    if (nullptr != socket)
    {
        return std::make_unique<QTcpSocketWrapper>(std::unique_ptr<QTcpSocket>(socket), this);
    }

    return {};
}
