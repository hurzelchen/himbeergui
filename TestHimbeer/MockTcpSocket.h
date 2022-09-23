#ifndef MOCKTCPSOCKET_H
#define MOCKTCPSOCKET_H

#include "AbstractTcpSocket.h"

#include <QByteArray>
#include <QObject>
#include <QString>

class MockTcpSocket : public AbstractTcpSocket
{
    // NOLINTNEXTLINE
    Q_OBJECT

public:
    explicit MockTcpSocket(QByteArray requestData, QObject *parent = nullptr);

private:
    QByteArray m_requestData;
};

#endif // MOCKTCPSOCKET_H
