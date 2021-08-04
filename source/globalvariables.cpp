#include "globalvariables.h"

//全局变量
Settings* settings;
QSize scrSize;
QIcon appIcon;
QFile* logFile;

//全局函数
//写日志
void write_log(const QString &text)
{
    QString tmp = "[";
    tmp.append(QTime::currentTime().toString());
    tmp.append("] ").append(text).append('\n');
    logFile->open(QFile::ReadWrite | QFile::Append);
    logFile->write(tmp.toUtf8());
    logFile->close();
}
