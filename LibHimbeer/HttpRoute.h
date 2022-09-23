#ifndef HTTPROUTE_H
#define HTTPROUTE_H

#include "AbstractHttpRoute.h"

#include <QString>

#include <memory>

class HttpRoute : public AbstractHttpRoute
{
public:
    explicit HttpRoute(QString route, std::weak_ptr<AbstractHttpRoute> parent = {});

private:
    QString m_route;
};

#endif // HTTPROUTE_H
