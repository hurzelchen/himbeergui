#ifndef ABSTRACTTCPSOCKET_H
#define ABSTRACTTCPSOCKET_H

#include <QObject>
#include <QString>

class AbstractTcpSocket : public QObject
{
    Q_OBJECT

protected:
    explicit AbstractTcpSocket(QObject *parent = nullptr);
    virtual ~AbstractTcpSocket() = default;
};

#endif // ABSTRACTTCPSOCKET_H
