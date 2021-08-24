#include "timewidget.h"
#include "sidebar.h"
#include "settingswidget.h"
#include "timeeventmanager.h"

int main(int argc, char *argv[])
{
    logFile = new QFile(QDate::currentDate().toString("yyyy-MM-dd")
                        .append('-')
                        .append(QTime::currentTime().toString("HH-mm-ss"))
                        .append(".log"));
    write_log("成功创建日志文件");
    QApplication a(argc, argv);
    if (QT_VERSION >= QT_VERSION_CHECK(6,0,0))
    {
        QGuiApplication::setHighDpiScaleFactorRoundingPolicy(Qt::HighDpiScaleFactorRoundingPolicy::Floor);
    }
    scrSize = a.primaryScreen()->size();
    settings = new Settings;
    appIcon.addFile(":/resources/appIcon.svg");
	timeWid = new TimeWidget;
	evMgr = new TimeEventManager;
	sideBar = new SideBar;
	QObject::connect(sideBar, &SideBar::signalHide, timeWid, &TimeWidget::slotHide);
	settingsWid = new SettingsWidget;
    return a.exec();
}
