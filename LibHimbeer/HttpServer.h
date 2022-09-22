#ifndef HTTPSERVER_H
#define HTTPSERVER_H

#include "AbstractHttpRoute.h"

#include <QObject>
#include <QString>

class AbstractTcpServer;

class HttpServer : public QObject, public AbstractHttpRoute
{
    // NOLINTNEXTLINE
    Q_OBJECT

public:
    explicit HttpServer(QObject *parent = nullptr);
    explicit HttpServer(AbstractTcpServer *replacementTcpServer, QObject *parent = nullptr);

    void close();

    auto listen() -> bool;

private slots:
    void newConnection();

private: // NOLINT(readability-redundant-access-specifiers)
    AbstractTcpServer *m_tcpServer;
};

#endif // HTTPSERVER_H
