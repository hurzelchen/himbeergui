#ifndef HTTPSERVER_H
#define HTTPSERVER_H

#include "AbstractHttpRoute.h"

#include <QObject>
#include <QString>

class AbstractTcpServer;

class HttpServer : public QObject, public AbstractHttpRoute
{
    Q_OBJECT

public:
    explicit HttpServer(QObject *parent = nullptr);
    explicit HttpServer(AbstractTcpServer *replacementTcpServer, QObject *parent = nullptr);

    void close();

    bool listen();

private slots:
    void newConnection();

private:
    AbstractTcpServer *m_tcpServer;
};

#endif // HTTPSERVER_H
