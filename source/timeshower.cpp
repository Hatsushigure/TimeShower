#include "timeshower.h"

//全局变量
int borderRadius;
MainWidget* mainWid;
QSize scrSize;

//全局函数
int scale(const int value)
{
	return value * (double(scrSize.width()) / STANDARD_SCREEN_WIDTH);
}
QSize scale(const QSize& value)
{
	return value * (double(scrSize.width()) / STANDARD_SCREEN_WIDTH);
}
