#include "HimbeerMainWidget.h"

#include <QStringLiteral>

HimbeerMainWidget::HimbeerMainWidget(QWidget *parent)
    : QWidget{parent}
{
    setStyleSheet(QStringLiteral("background-color: #000000;"));
}
