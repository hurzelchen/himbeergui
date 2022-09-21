#include "QTcpServerWrapper.h"

#include <QTcpServer>

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
