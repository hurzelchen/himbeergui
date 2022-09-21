#ifndef QTCPSERVERWRAPPER_H
#define QTCPSERVERWRAPPER_H

#include <QHostAddress>
#include <QObject>
#include <QString>
#include <QtGlobal>

#include "AbstractTcpServer.h"

class QTcpServer;

class QTcpServerWrapper : public AbstractTcpServer
{
    Q_OBJECT

public:
    explicit QTcpServerWrapper(QObject *parent = nullptr);
    virtual ~QTcpServerWrapper() = default;

    void close() override;

    bool listen(const QHostAddress &address = QHostAddress::Any, quint16 port = 0) override;

private:
    QTcpServer *m_implementation;
};

#endif // QTCPSERVERWRAPPER_H
