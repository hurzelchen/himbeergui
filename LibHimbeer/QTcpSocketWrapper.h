#ifndef QTCPSOCKETWRAPPER_H
#define QTCPSOCKETWRAPPER_H

#include "AbstractTcpSocket.h"

#include <QObject>
#include <QString>

class QTcpSocket;

class QTcpSocketWrapper : public AbstractTcpSocket
{
    Q_OBJECT

public:
    explicit QTcpSocketWrapper(QTcpSocket *wrappedSocket, QObject *parent = nullptr);

private:
    QTcpSocket *m_wrappedSocket = nullptr;
};

#endif // QTCPSOCKETWRAPPER_H
