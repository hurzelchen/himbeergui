#ifndef ABSTRACTTCPSOCKET_H
#define ABSTRACTTCPSOCKET_H

#include <QObject>
#include <QString>

class AbstractTcpSocket : public QObject
{
    // NOLINTNEXTLINE
    Q_OBJECT

protected:
    explicit AbstractTcpSocket(QObject *parent = nullptr);
};

#endif // ABSTRACTTCPSOCKET_H
