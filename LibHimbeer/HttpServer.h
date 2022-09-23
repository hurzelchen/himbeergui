#ifndef HTTPSERVER_H
#define HTTPSERVER_H

#include "AbstractHttpRoute.h"
#include <unordered_map>

#include <QObject>
#include <QString>

#include <memory>

class AbstractTcpServer;
class AbstractTcpSocket;

class HttpServer : public QObject, public AbstractHttpRoute
{
    // NOLINTNEXTLINE
    Q_OBJECT

public:
    explicit HttpServer(QObject *parent = nullptr);
    explicit HttpServer(std::shared_ptr<AbstractTcpServer> replacementTcpServer,
                        QObject *parent = nullptr);

    void close();

    bool listen();

private slots:
    void newConnection();
    void readFromSocket();

private: // NOLINT(readability-redundant-access-specifiers)
    void readFromSocket(std::shared_ptr<AbstractTcpSocket> socket);

    std::shared_ptr<AbstractTcpServer> m_tcpServer;

    std::unordered_map<std::shared_ptr<AbstractTcpSocket>, int> m_connectedSockets;
};

#endif // HTTPSERVER_H
