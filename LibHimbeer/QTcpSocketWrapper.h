#ifndef QTCPSOCKETWRAPPER_H
#define QTCPSOCKETWRAPPER_H

#include "AbstractTcpSocket.h"

#include <QObject>
#include <QString>

#include <memory>

class QTcpSocket;

class QTcpSocketWrapper : public AbstractTcpSocket
{
    // NOLINTNEXTLINE
    Q_OBJECT

public:
    explicit QTcpSocketWrapper(std::unique_ptr<QTcpSocket> wrappedSocket,
                               QObject *parent = nullptr);
};

#endif // QTCPSOCKETWRAPPER_H
