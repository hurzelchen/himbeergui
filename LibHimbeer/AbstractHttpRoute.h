#ifndef ABSTRACTHTTPROUTE_H
#define ABSTRACTHTTPROUTE_H

#include <QMap>
#include <QString>

class HttpRoute;

class AbstractHttpRoute
{
protected:
    explicit AbstractHttpRoute(AbstractHttpRoute *parent = nullptr);

public:
    HttpRoute &route(const QString &route);

private:
    AbstractHttpRoute *m_parent;
    QMap<QString, HttpRoute *> m_routes;
};

#endif // ABSTRACTHTTPROUTE_H
