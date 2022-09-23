#include "MockTcpSocket.h"

#include <QBuffer>

#include <memory>
#include <utility>

MockTcpSocket::MockTcpSocket(QByteArray requestData, QObject *parent)
    : AbstractTcpSocket{std::make_unique<QBuffer>(), parent},
      m_requestData{std::move(requestData)}
{
    qobject_cast<QBuffer *>(ioDevice().get())->setBuffer(&m_requestData);
    ioDevice()->open(QIODevice::ReadOnly);
}
