#pragma once
#include <QWidget>
#include <QIcon>
#include <QPushButton>
#include <QLabel>
#include <QPaintEvent>
#include <QColor>
#include <QPainter>

class TitleBar : public QWidget
{
	Q_OBJECT
private:
	//按钮图标
	QIcon* m_closeIcon;
	QIcon* m_maximizeIcon;
	QIcon* m_restoreIcon;
	QIcon* m_minimizeIcon;
	QIcon* m_backIcon;
	//按钮
	QPushButton* m_closeBtn;
	QPushButton* m_maximizeBtn;
	QPushButton* m_restoreBtn;
	QPushButton* m_minimizeBtn;
	QPushButton* m_backBtn;
	//其他控件
	QLabel* m_windowIcon;
	QLabel* m_textLabel;
	//其他
	int m_rndCornerRadius;	//圆角半径
	QColor m_color;	//标题栏颜色
	const QColor FRAME_COLOR = QColor(181, 181, 181);
	const QColor DEFAULT_COLOR = QColor(255, 255, 255);

public:
	explicit TitleBar(QWidget *parent = nullptr, int rndCornerRadius = 8);
private:
	//绘图事件
	void paintEvent(QPaintEvent* event);

signals:

};

