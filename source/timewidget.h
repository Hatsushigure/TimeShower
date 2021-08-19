#pragma once
#include "timeshower.h"
#include "backgroundwidget.h"
#include "sidebar.h"
#include "timeeventmanager.h"
#include "globals.h"

QT_BEGIN_NAMESPACE
namespace Ui { class TimeWidget; }
QT_END_NAMESPACE

class TimeWidget : public QWidget
{
    Q_OBJECT
private:
    Ui::TimeWidget *ui;

   bool movable;
   QPoint fstPos;
   QTime curTime;
   QTimer* mainTimer;
   QTimer* shutDownTimer;
   int scrWid;
   int scrHei;
   BackgroundWidget* bck;
   SideBar* sideBar;
   QSystemTrayIcon* trayIcon;
   QAction* actionExit;
   QAction* actionShow;
   QAction* actionHide;
   QMenu* trayMenu;
   TimeEventManager* evMgr;
public:
    TimeWidget(QWidget *parent = nullptr);

    //创建系统托盘图标
    void add_tray_icon();

    void mousePressEvent(QMouseEvent* e);

    void mouseMoveEvent(QMouseEvent* e);

    void mouseDoubleClickEvent(QMouseEvent* e);

    void mouseReleaseEvent(QMouseEvent* e);

    void moveEvent(QMoveEvent* e);

    void paintEvent(QPaintEvent* e);

    void on_bck_stpMoving();

    void on_mainTimer_timeOut();

    //从托盘中唤起槽函数
    void slotShow();

    //最小化槽函数
    void slotHide();

    //关机槽函数
    void slotShutDown();

    //重启槽函数
    void slotRestart();

    //显示消息槽函数
    void slotShowMessage(QString msg);

    //退出槽函数
    void slotExit();

	//事件变更槽函数
	void slotEventChanged(QString name);

    //自动对齐
    void auto_align(QPoint pos);

	//真·关机前摇
	void shutdown_prerock();

    ~TimeWidget();
};
