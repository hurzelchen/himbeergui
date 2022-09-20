#ifndef HIMBEERMAINWIDGET_H
#define HIMBEERMAINWIDGET_H

#include <QObject>
#include <QString>
#include <QWidget>

class HttpServer;
class QThread;

class HimbeerMainWidget : public QWidget
{
    Q_OBJECT

public:
    explicit HimbeerMainWidget(QWidget *parent = nullptr);
    virtual ~HimbeerMainWidget();

private:
    HttpServer *m_httpServer;
    QThread *m_networkThread;
};

#endif // HIMBEERMAINWIDGET_H
