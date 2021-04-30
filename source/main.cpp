#include <QTextCodec>
#include <QApplication>
#include "timewidget.h"

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    TimeWidget w;
    w.show();
    return a.exec();
}
