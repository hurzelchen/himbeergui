#include "AbstractTcpSocket.h"

#include <QIODevice>

#include <memory>
#include <utility>

AbstractTcpSocket::AbstractTcpSocket(std::unique_ptr<QIODevice> ioDevice, QObject *parent)
    : QObject{parent},
      m_ioDevice{std::move(ioDevice)}
{
    connect(m_ioDevice.get(), &QIODevice::readyRead, this, &AbstractTcpSocket::readyRead);
}

qint64 AbstractTcpSocket::bytesAvailable() const
{
    return m_ioDevice->bytesAvailable();
}

bool AbstractTcpSocket::canReadLine() const
{
    return m_ioDevice->canReadLine();
}

QByteArray AbstractTcpSocket::readLine(qint64 maxlen)
{
    return m_ioDevice->readLine(maxlen);
}

const std::unique_ptr<QIODevice> &AbstractTcpSocket::ioDevice() const
{
    return m_ioDevice;
}
