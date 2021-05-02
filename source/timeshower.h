//此文件包含应用所有的常量、include、枚举
#ifndef TIMESHOWER_H
#define TIMESHOWER_H
//包含
#include <QFile>
#include <QMessageBox>
#include <QDebug>
#include <QFileDialog>
#include <QDateTime>
#include <QPalette>
#include <QMouseEvent>
#include <QPaintEvent>
#include <QMoveEvent>
#include <QPainter>
#include <QDesktopWidget>
#include <QApplication>
#include <QMessageBox>
#include <QIcon>
#include <QTimer>
#include "dialog.h"

//常量
const QString SETTINGS_FILE_NAME = "settings.txt";
const short SIZE_RATE = 8;   //尺寸比例
const short APP_VERSION = 2;
namespace DefaultSettings {
const short DEF_SIZE = 1;
const bool DEF_DO_AUTO_ALIGN = true;
const short TIMER_INTERVAL = 10;    //计时器更新频率（很长一段时间内将为常量）
}

//枚举
enum class LogType {info, warning, error};
enum class SideBarType {left, right};

#endif // TIMESHOWER_H
