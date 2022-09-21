#ifndef ABSTRACTTCPSERVER_H
#define ABSTRACTTCPSERVER_H

#include <QHostAddress>
#include <QObject>
#include <QString>
#include <QtGlobal>

class AbstractTcpSocket;

class AbstractTcpServer : public QObject
{
    Q_OBJECT

protected:
    explicit AbstractTcpServer(QObject *parent = nullptr);
    virtual ~AbstractTcpServer() = default;

public:
    virtual void close() = 0;

    virtual bool listen(const QHostAddress &address = QHostAddress::Any, quint16 port = 0) = 0;

    virtual AbstractTcpSocket *nextPendingConnection() = 0;

signals:
    void newConnection();
};

#endif // ABSTRACTTCPSERVER_H
