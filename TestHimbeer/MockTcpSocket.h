#ifndef MOCKTCPSOCKET_H
#define MOCKTCPSOCKET_H

#include "AbstractTcpSocket.h"

#include <QByteArray>
#include <QObject>
#include <QString>

class MockTcpSocket : public AbstractTcpSocket
{
    Q_OBJECT

public:
    explicit MockTcpSocket(const QByteArray &requestData, QObject *parent = nullptr);

    const QByteArray &requestData() const;

private:
    QByteArray m_requestData;
};

#endif // MOCKTCPSOCKET_H
