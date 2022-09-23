#ifndef ABSTRACTTCPSOCKET_H
#define ABSTRACTTCPSOCKET_H

#include <QByteArray>
#include <QIODevice>
#include <QObject>
#include <QString>
#include <QtGlobal>

#include <memory>

class AbstractTcpSocket : public QObject
{
    // NOLINTNEXTLINE
    Q_OBJECT

protected:
    explicit AbstractTcpSocket(std::unique_ptr<QIODevice> ioDevice, QObject *parent = nullptr);

public:
    qint64 bytesAvailable() const;
    bool canReadLine() const;
    QByteArray readLine(qint64 maxlen = 0);

signals:
    void readyRead();

protected:
    const std::unique_ptr<QIODevice> &ioDevice() const;

private:
    std::unique_ptr<QIODevice> m_ioDevice;
};

#endif // ABSTRACTTCPSOCKET_H
