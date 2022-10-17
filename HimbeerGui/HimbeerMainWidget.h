#ifndef HIMBEERMAINWIDGET_H
#define HIMBEERMAINWIDGET_H

#include <QObject>
#include <QString>
#include <QWidget>

class HttpServer;
class QThread;

class HimbeerMainWidget : public QWidget
{
    // NOLINTNEXTLINE
    Q_OBJECT

public:
    explicit HimbeerMainWidget(QWidget *parent = nullptr);

    HimbeerMainWidget(const HimbeerMainWidget &) = delete;
    HimbeerMainWidget(HimbeerMainWidget &&) = delete;

    ~HimbeerMainWidget() override;

    HimbeerMainWidget &operator=(const HimbeerMainWidget &) = delete;
    HimbeerMainWidget &operator=(HimbeerMainWidget &&) = delete;

private:
    HttpServer *m_httpServer;
    QThread *m_networkThread;
};

#endif // HIMBEERMAINWIDGET_H
