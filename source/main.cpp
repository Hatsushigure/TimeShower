#include "timewidget.h"

int main(int argc, char *argv[])
{
    logFile = new QFile(QDate::currentDate().toString("yyyy-MM-dd")
                        .append('-')
                        .append(QTime::currentTime().toString("HH-mm-ss"))
                        .append(".log"));
    write_log("成功创建日志文件");
    QApplication a(argc, argv);
    scrSize = a.primaryScreen()->size();
    settings = new Settings;
    appIcon.addFile(":/resources/appIcon.svg");
    TimeWidget w;
    return a.exec();
}
