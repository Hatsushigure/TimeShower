#pragma once

#include "settings.h"

//全局变量
extern Settings* settings;
extern QSize scrSize;
extern QIcon appIcon;
extern QFile* logFile;

//全局函数
//写日志
void write_log(const QString& text);
