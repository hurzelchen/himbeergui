#ifndef QTCPSERVERWRAPPER_H
#define QTCPSERVERWRAPPER_H

#include "AbstractTcpServer.h"

#include <QHostAddress>
#include <QObject>
#include <QString>
#include <QtGlobal>

#include <memory>

class AbstractTcpSocket;
class QTcpServer;

class QTcpServerWrapper : public AbstractTcpServer
{
    // NOLINTNEXTLINE
    Q_OBJECT

public:
    explicit QTcpServerWrapper(QObject *parent = nullptr);

    void close() override;

    bool listen(const QHostAddress &address = QHostAddress::Any, quint16 port = 0) override;

    std::unique_ptr<AbstractTcpSocket> nextPendingConnection() override;

private:
    QTcpServer *m_implementation;
};

#endif // QTCPSERVERWRAPPER_H
