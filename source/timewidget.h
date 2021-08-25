#pragma once
#include "timeshower.h"
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
   QSystemTrayIcon* trayIcon;
   QAction* actionExit;
   QAction* actionShow;
   QAction* actionHide;
   QMenu* trayMenu;
   QSize originSize;
public:
    TimeWidget(QWidget *parent = nullptr);

    //创建系统托盘图标
	void addTrayIcon();

	void mousePressEvent(QMouseEvent* e);

	void mouseMoveEvent(QMouseEvent* e);

    void mouseDoubleClickEvent(QMouseEvent* e);

    void mouseReleaseEvent(QMouseEvent* e);

    void moveEvent(QMoveEvent* e);

    void paintEvent(QPaintEvent* e);

	//拖拽进入事件
	void dragEnterEvent(QDragEnterEvent* e);

	//拖拽释放事件
	void dropEvent(QDropEvent* e);

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
	void autoAlign(QPoint pos);

	//真·关机前摇
	void shutdownPrerock();

	//自动resize
	void autoResize();

	//更新设置
	void updateSettings();

	//更新事件
	void updateTimeEvents();

    ~TimeWidget();
};
