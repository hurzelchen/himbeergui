#ifndef HTTPSERVER_H
#define HTTPSERVER_H

#include <QObject>
#include <QString>

class QTcpServer;

class HttpServer : public QObject
{
    Q_OBJECT

public:
    explicit HttpServer(QObject *parent = nullptr);

    void close();

    bool listen();

private slots:
    void newConnection();

private:
    QTcpServer *m_tcpServer;
};

#endif // HTTPSERVER_H
