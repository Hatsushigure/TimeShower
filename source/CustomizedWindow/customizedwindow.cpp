#include "customizedwindow.h"

CustomizedWindow::CustomizedWindow(QWidget *parent) : QWidget(parent)
{
	m_title =new TitleBar(this);
	m_title->resize(width() - 20, 30);
	m_title->move(10, 20);
}
