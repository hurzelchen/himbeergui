#ifndef HTTPROUTE_H
#define HTTPROUTE_H

#include "AbstractHttpRoute.h"

#include <QString>

class HttpRoute : public AbstractHttpRoute
{
public:
    HttpRoute(const QString &route, AbstractHttpRoute *parent);

private:
    QString m_route;
};

#endif // HTTPROUTE_H
