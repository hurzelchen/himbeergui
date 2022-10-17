#ifndef JSCLOCKWIDGET_H
#define JSCLOCKWIDGET_H

#include "AbstractHimbeerWidget.h"

#include <QObject>
#include <QString>
#include <QWebEngineView>

class QWidget;

class JsClockWidget : public QWebEngineView, AbstractHimbeerWidget
{
    // NOLINTNEXTLINE
    Q_OBJECT

public:
    explicit JsClockWidget(QWidget *parent = nullptr);
};

#endif // JSCLOCKWIDGET_H
