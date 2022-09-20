#include "HimbeerMainWidget.h"

#include "HttpServer.h"

#include <QStaticStringData>
#include <QStringLiteral>
#include <QThread>

HimbeerMainWidget::HimbeerMainWidget(QWidget *parent)
    : QWidget{parent},
      m_httpServer{new HttpServer(this)},
      m_networkThread{new QThread(this)}
{
    setStyleSheet(QStringLiteral("background-color: #000000;"));

    m_httpServer->moveToThread(m_networkThread);

    m_networkThread->start();
}

HimbeerMainWidget::~HimbeerMainWidget()
{
    m_httpServer->close();

    m_networkThread->quit();
    m_networkThread->wait();
}
