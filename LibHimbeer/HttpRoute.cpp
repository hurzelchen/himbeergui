#include "HttpRoute.h"

#include <memory>
#include <utility>

HttpRoute::HttpRoute(QString route, std::weak_ptr<AbstractHttpRoute> parent)
    : AbstractHttpRoute{std::move(parent)},
      m_route{std::move(route)}
{
}
