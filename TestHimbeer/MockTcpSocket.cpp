#include "MockTcpSocket.h"

MockTcpSocket::MockTcpSocket(const QByteArray &requestData, QObject *parent)
    : AbstractTcpSocket{parent},
      m_requestData{requestData}
{
}

const QByteArray &MockTcpSocket::requestData() const
{
    return m_requestData;
}
