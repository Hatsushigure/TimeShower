#pragma once
#include <QWidget>
#include <QMouseEvent>
#include <QPoint>
#include <QTime>
#include <QTimer>
#include <QApplication>
#include <QDesktopWidget>
#include <QMoveEvent>
#include <QPaintEvent>
#include <QPainter>
#include <QPalette>
#include "backgroundwidget.h"
#include "sidebar.h"
#include "settings.h"

//常量
const short SIZE_RATE = 8;   //尺寸比例
const short TIMER_INTERVAL = 10;    //计时器更新频率（很长一段时间内将为常量）

QT_BEGIN_NAMESPACE
namespace Ui { class TimeWidget; }
QT_END_NAMESPACE

class TimeWidget : public QWidget
{
    Q_OBJECT

public:
    TimeWidget(QWidget *parent = nullptr);

    void mousePressEvent(QMouseEvent* e);

    void mouseMoveEvent(QMouseEvent* e);

    void mouseDoubleClickEvent(QMouseEvent* e);

    void mouseReleaseEvent(QMouseEvent* e);

    void moveEvent(QMoveEvent* e);

    void paintEvent(QPaintEvent* e);

    void on_mainTimer_timeOut();

    void on_bck_stpMoving();

    //自动对齐
    void auto_align(int aX, int aY);

    ~TimeWidget();

private:
    Ui::TimeWidget *ui;

   bool movable;
   QPoint fstPos;
   QTime curTime;
   QTimer* mainTimer;
   int scrWid;
   int scrHei;
   BackgroundWidget* bck;
   SideBar* sideBar;
   Settings* settings;


};
