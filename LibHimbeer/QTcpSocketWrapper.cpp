#include "QTcpSocketWrapper.h"

QTcpSocketWrapper::QTcpSocketWrapper(QTcpSocket *wrappedSocket, QObject *parent)
    : AbstractTcpSocket{parent},
      m_wrappedSocket{wrappedSocket}
{
}
