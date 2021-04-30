#include <QTextCodec>
#include <QApplication>
#include "timewidget.h"
//#pragma execution_character_set("utf-8")

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    TimeWidget w;
    w.show();
    return a.exec();
}
