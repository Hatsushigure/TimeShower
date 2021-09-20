#include <QApplication>
#include "mainwidget.h"

int main(int argc, char *argv[])
{
	QApplication app(argc, argv);
	MainWidget wid;
	wid.show();
	return app.exec();
}
