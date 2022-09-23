#include "QTcpSocketWrapper.h"

#include <QIODevice>
#include <QTcpSocket>

#include <memory>
#include <utility>

QTcpSocketWrapper::QTcpSocketWrapper(std::unique_ptr<QTcpSocket> wrappedSocket, QObject *parent)
    : AbstractTcpSocket{std::move(wrappedSocket), parent}
{
}
