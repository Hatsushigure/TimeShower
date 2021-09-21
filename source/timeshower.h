#pragma once
#include <QSize>

class MainWidget;

//常量
const int STANDARD_SCREEN_WIDTH = 1366;

//全局变量
extern int borderRadius;
extern MainWidget* mainWid;
extern QSize scrSize;

//全局函数
int scale(const int value);
QSize scale(const QSize& value);
