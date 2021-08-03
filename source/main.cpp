#include "timewidget.h"

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    scrSize = a.primaryScreen()->size();
    settings = new Settings;
    APP_ICON.addFile(":/resources/appIcon.svg");
    TimeWidget w;
    return a.exec();
}
