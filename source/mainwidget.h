#pragma once
#include <QWidget>
#include <QPaintEvent>
#include <QMouseEvent>
#include <QResizeEvent>
#include <QPropertyAnimation>
#include "timeshower.h"

QT_BEGIN_NAMESPACE
namespace Ui
{
	class MainWidget;
}
QT_END_NAMESPACE

class MainWidget : public QWidget
{
	Q_OBJECT
private:
	Ui::MainWidget* ui;
	const int TITLE_HEIGHT = 15;
	bool m_isMovable;
	QPoint m_originPos;
	QPropertyAnimation* m_moveAnimation;

public:
	MainWidget(QWidget* parent = nullptr);

	~MainWidget();

private:
	//绘图事件
	void paintEvent(QPaintEvent* event);

	//鼠标双击事件
	void mouseDoubleClickEvent(QMouseEvent* event);

	//鼠标按下事件
	void mousePressEvent(QMouseEvent* event);

	//鼠标移动事件
	void mouseMoveEvent(QMouseEvent* event);

	//鼠标松开事件
	void mouseReleaseEvent(QMouseEvent* event);

	//大小改变事件
	void resizeEvent(QResizeEvent* event);

	//关联信号和槽
	void initConnections();

	//初始化变量
	void initVariants();

	//初始化移动动画
	void initMoveAnimation();

signals:
	void sigMove();

private slots:
	//移动槽函数
	void slotMove();
};
