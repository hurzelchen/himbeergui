#include "AbstractHttpRoute.h"

#include "HttpRoute.h"

#include <utility>

class QByteArray;

AbstractHttpRoute::AbstractHttpRoute(std::weak_ptr<AbstractHttpRoute> parent)
    : m_parent{std::move(parent)}
{
}

void AbstractHttpRoute::get(const QString &get,
                            const std::function<void(const QByteArray &)> &function)
{
    QString normalizedGet = get;
    if (!normalizedGet.startsWith('/'))
    {
        normalizedGet.prepend('/');
    }

    if (!m_gets.contains(normalizedGet))
    {
        m_gets[normalizedGet] = function;
    }
}

std::shared_ptr<HttpRoute> AbstractHttpRoute::route(const QString &route)
{
    QString normalizedRoute = route;
    if (!normalizedRoute.startsWith('/'))
    {
        normalizedRoute.prepend('/');
    }

    if (normalizedRoute.endsWith('/'))
    {
        normalizedRoute.remove(normalizedRoute.length(), 1);
    }

    if (!m_routes.contains(normalizedRoute))
    {
        m_routes[normalizedRoute]
            = std::make_shared<HttpRoute>(normalizedRoute, shared_from_this());
    }

    return m_routes[normalizedRoute];
}
