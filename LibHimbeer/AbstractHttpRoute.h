#ifndef ABSTRACTHTTPROUTE_H
#define ABSTRACTHTTPROUTE_H

#include <QMap>
#include <QString>

#include <functional>
#include <memory>

class QByteArray;
class HttpRoute;

class AbstractHttpRoute : public std::enable_shared_from_this<AbstractHttpRoute>
{
protected:
    explicit AbstractHttpRoute(std::weak_ptr<AbstractHttpRoute> parent = {});

public:
    void get(const QString &get, const std::function<void(const QByteArray &)> &function);
    std::shared_ptr<HttpRoute> route(const QString &route);

private:
    std::weak_ptr<AbstractHttpRoute> m_parent;
    QMap<QString, std::shared_ptr<HttpRoute> > m_routes;
    QMap<QString, std::function<void(const QByteArray &)> > m_gets;
};

#endif // ABSTRACTHTTPROUTE_H
