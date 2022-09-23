#ifndef HTTPSERVER_H
#define HTTPSERVER_H

#include "AbstractHttpRoute.h"

#include <QObject>
#include <QString>

#include <memory>

class AbstractTcpServer;

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

private: // NOLINT(readability-redundant-access-specifiers)
    std::shared_ptr<AbstractTcpServer> m_tcpServer;
};

#endif // HTTPSERVER_H
