#include "HttpRoute.h"
#include "HttpServer.h"
#include "MockTcpServer.h"

#include <QByteArray>
#include <QDebug>
#include <QStaticStringData>
#include <QString>
#include <QStringLiteral>

#include <iostream>
#include <memory>

int main(int /*argc*/, char ** /*argv*/)
{
    std::cout << "Hello Test!" << std::endl;

    std::shared_ptr<MockTcpServer> mockTcpServer = std::make_shared<MockTcpServer>();

    std::shared_ptr<HttpServer> httpServer = std::make_shared<HttpServer>(mockTcpServer, nullptr);

    httpServer->route(QStringLiteral("/test"))
        ->get(QStringLiteral("/test"),
              [](const QByteArray &data) { qDebug() << QString::fromUtf8(data); });

    httpServer->listen();

    mockTcpServer->mockRequest(QStringLiteral("GET / HTTP1.1\n\n").toUtf8());

    httpServer->close();

    return 0;
}
