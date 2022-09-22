#include "HttpRoute.h"

HttpRoute::HttpRoute(const QString &route, AbstractHttpRoute *parent)
    : AbstractHttpRoute{parent},
      m_route{route}
{
}
