#ifndef MOCKTCPSERVER_H
#define MOCKTCPSERVER_H

#include "AbstractTcpServer.h"

#include <QByteArray>
#include <QHostAddress>
#include <QObject>
#include <QString>
#include <QtGlobal>

class MockTcpServer : public AbstractTcpServer
{
    Q_OBJECT

public:
    explicit MockTcpServer(QObject *parent = nullptr);

    void close() override;

    bool listen(const QHostAddress &address = QHostAddress::Any, quint16 port = 0) override;

    void mockRequest(const QByteArray &requestContent);

private:
    bool m_listening = false;
};

#endif // MOCKTCPSERVER_H
