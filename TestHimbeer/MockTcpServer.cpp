#include "MockTcpServer.h"

#include "MockTcpSocket.h"

class AbstractTcpSocket;

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
    MockRequest mockRequest;
    mockRequest.requestData = requestContent;

    m_mockRequests.append(mockRequest);

    emit newConnection();
}

AbstractTcpSocket *MockTcpServer::nextPendingConnection()
{
    if (m_mockRequests.count() > 0)
    {
        MockRequest mockRequest = m_mockRequests.takeFirst();

        return new MockTcpSocket(mockRequest.requestData, this);
    }
    else
    {
        return nullptr;
    }
}
