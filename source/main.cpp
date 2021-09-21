#include <QApplication>
#include "mainwidget.h"
#include "timeshower.h"

int main(int argc, char* argv[])
{
	QApplication app(argc, argv);
	borderRadius = 8;
	scrSize = app.primaryScreen()->size();
	mainWid = new MainWidget;
	mainWid->show();
	return app.exec();
}
