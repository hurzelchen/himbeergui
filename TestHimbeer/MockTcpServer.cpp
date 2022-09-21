#include "MockTcpServer.h"

MockTcpServer::MockTcpServer(QObject *parent)
    : AbstractTcpServer{parent},
      m_listening{false}
{
}

void MockTcpServer::close()
{
    m_listening = false;
}

bool MockTcpServer::listen(const QHostAddress & /*address*/, quint16 port)
{
    if (port >= 0)
    {
        m_listening = true;
    }

    return m_listening;
}

void MockTcpServer::mockRequest(const QByteArray &requestContent)
{
    // TODO(hurzelchen): implement
    Q_UNUSED(requestContent)
}
