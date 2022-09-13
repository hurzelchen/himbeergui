#include <QApplication>
#include <QMainWindow>

int main(int argc, char** argv)
{
    QApplication app(argc, argv);

    QMainWindow mainWindow(nullptr);
    mainWindow.show();

    int returnValue = app.exec();

    return returnValue;
}
