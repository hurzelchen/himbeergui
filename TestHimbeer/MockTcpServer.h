#ifndef MOCKTCPSERVER_H
#define MOCKTCPSERVER_H

#include "AbstractTcpServer.h"

#include <QByteArray>
#include <QHostAddress>
#include <QObject>
#include <QString>
#include <QVector>
#include <QtGlobal>

class AbstractTcpSocket;

class MockTcpServer : public AbstractTcpServer
{
    // NOLINTNEXTLINE
    Q_OBJECT

public:
    explicit MockTcpServer(QObject *parent = nullptr);

    void close() override;

    bool listen(const QHostAddress &address = QHostAddress::Any, quint16 port = 0) override;

    void mockRequest(const QByteArray &requestContent);

    AbstractTcpSocket *nextPendingConnection() override;

private:
    struct MockRequest
    {
        QByteArray requestData;
    };

    bool m_listening = false;

    QVector<MockRequest> m_mockRequests{};
};

#endif // MOCKTCPSERVER_H
