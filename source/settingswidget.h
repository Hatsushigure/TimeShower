#pragma once
#include "timeshower.h"

namespace Ui {
class SettingsWidget;
}

class SettingsWidget : public QWidget
{
	Q_OBJECT
private:
	Ui::SettingsWidget *ui;
	QPoint originPos;
public:
	explicit SettingsWidget(QWidget *parent = nullptr);

	~SettingsWidget();

	//事件过滤器
	bool eventFilter(QObject* watch, QEvent* e);
};

