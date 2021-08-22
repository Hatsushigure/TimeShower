#pragma once
#include "settings.h"

class BackgroundWidget;
class TimeEventManager;
class SideBar;
class TimeWidget;

//全局变量
extern Settings* settings;
extern QSize scrSize;
extern QIcon appIcon;
extern QFile* logFile;
extern BackgroundWidget* bck;
extern TimeEventManager* evMgr;
extern SideBar* sideBar;
extern TimeWidget* timeWid;

//全局函数
//写日志
void write_log(const QString& text);

//画圆角
void round_corner(QWidget* wid, QColor col);

//缩放
QSize scale(const QSize origin);
int scale(const int origin);
