#pragma once
#include <QWidget>
#include "titlebar.h"

class CustomizedWindow : public QWidget
{
	Q_OBJECT
private:
	TitleBar* m_title;
public:
	explicit CustomizedWindow(QWidget *parent = nullptr);

signals:

};

