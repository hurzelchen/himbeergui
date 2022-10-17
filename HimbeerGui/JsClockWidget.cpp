#include "JsClockWidget.h"

#include <QByteArray>
#include <QFile>
#include <QIODevice>
#include <QStaticStringData>
#include <QStringLiteral>
#include <QUrl>

class QWidget;

JsClockWidget::JsClockWidget(QWidget *parent)
    : QWebEngineView(parent)
{
    QFile htmlFile(QStringLiteral(":/JsClockWidget/jsclock.html"));

    if (htmlFile.open(QIODevice::ReadOnly))
    {
        setHtml(QString::fromUtf8(htmlFile.readAll()), QUrl(QStringLiteral("qrc:/JsClockWidget/")));
    }
}
