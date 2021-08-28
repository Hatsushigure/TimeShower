#include "titlebar.h"

TitleBar::TitleBar(QWidget *parent, int rndCornerRadius) : QWidget(parent)
{
	m_color = DEFAULT_COLOR;
	m_rndCornerRadius = rndCornerRadius;

	//窗体特效
	setAttribute(Qt::WA_TranslucentBackground);
}

//绘图事件
void TitleBar::paintEvent(QPaintEvent* event)
{
	QPainter painter(this);
	QPen pen(FRAME_COLOR);
	QBrush brush(m_color);
	painter.setPen(pen);
	painter.setBrush(brush);
	painter.setRenderHint(QPainter::Antialiasing);
	painter.drawRoundedRect(rect(), m_rndCornerRadius, m_rndCornerRadius);
	painter.drawRect(QRect(rect().x(),
						   rect().y() + m_rndCornerRadius,
						   rect().width(),
						   rect().height() - m_rndCornerRadius));
	pen.setColor(m_color);
	painter.setPen(pen);
	painter.drawRect(QRect(rect().x() + 2 * pen.width(),
						   rect().y() + m_rndCornerRadius - pen.width(),
						   rect().width() - 4 * pen.width(),
						   rect().height() - m_rndCornerRadius - pen.width()));
}
