#include "HimbeerMainWidget.h"

#include <QApplication>
#include <QCommandLineOption>
#include <QCommandLineParser>
#include <QSizePolicy>
#include <QStaticStringData>
#include <QString>
#include <QStringLiteral>

static const int HIMBEERGUI_WIDTH = 1280;
static const int HIMBEERGUI_HEIGHT = 400;

int main(int argc, char **argv)
{
    QApplication app(argc, argv);

    QCommandLineParser commandLineParser;

    QCommandLineOption fullscreenOption({"f", "fullscreen"},
                                        QStringLiteral("Show application fullscreen"));
    commandLineParser.addOption(fullscreenOption);

    commandLineParser.process(app);

    HimbeerMainWidget mainWidget(nullptr);

    if (commandLineParser.isSet(fullscreenOption))
    {
        mainWidget.showFullScreen();
    }
    else
    {
        mainWidget.setFixedSize(HIMBEERGUI_WIDTH, HIMBEERGUI_HEIGHT);
        mainWidget.setSizePolicy(QSizePolicy::Fixed, QSizePolicy::Fixed);
        mainWidget.show();
    }

    int returnValue = QApplication::exec();

    return returnValue;
}
