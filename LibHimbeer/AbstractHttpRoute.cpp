#include "AbstractHttpRoute.h"

#include "HttpRoute.h"

AbstractHttpRoute::AbstractHttpRoute(AbstractHttpRoute *parent)
    : m_parent{parent},
      m_routes{}
{
}

HttpRoute &AbstractHttpRoute::route(const QString &route)
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
        m_routes[normalizedRoute] = new HttpRoute(normalizedRoute, this);
    }

    return *(m_routes[normalizedRoute]);
}
