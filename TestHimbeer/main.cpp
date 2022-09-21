#include "HttpServer.h"
#include "MockTcpServer.h"

#include <QStaticStringData>
#include <QString>
#include <QStringLiteral>

#include <iostream>

int main(int /*argc*/, char ** /*argv*/)
{
    std::cout << "Hello Test!" << std::endl;

    MockTcpServer *mockTcpServer = new MockTcpServer();

    HttpServer *httpServer = new HttpServer(mockTcpServer, nullptr);
    httpServer->listen();

    mockTcpServer->mockRequest(QStringLiteral("GET / HTTP1.1").toUtf8());

    httpServer->close();
    delete httpServer;

    delete mockTcpServer;

    return 0;
}
