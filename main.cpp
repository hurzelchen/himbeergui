#include <QApplication>
#include <QCommandLineOption>
#include <QCommandLineParser>
#include <QMainWindow>
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

    QCommandLineOption fullscreenOption(
        { "f", "fullscreen" }, QStringLiteral("Show application fullscreen"));
    commandLineParser.addOption(fullscreenOption);

    commandLineParser.process(app);

    QMainWindow mainWindow(nullptr);

    if (commandLineParser.isSet(fullscreenOption))
    {
        mainWindow.showFullScreen();
    }
    else
    {
        mainWindow.setFixedSize(HIMBEERGUI_WIDTH, HIMBEERGUI_HEIGHT);
        mainWindow.setSizePolicy(QSizePolicy::Fixed, QSizePolicy::Fixed);
        mainWindow.show();
    }

    int returnValue = QApplication::exec();

    return returnValue;
}
