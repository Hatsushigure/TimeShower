#include "settingswidget.h"
#include "ui_settingswidget.h"

SettingsWidget::SettingsWidget(QWidget *parent) : QWidget(parent), ui(new Ui::SettingsWidget)
{
	ui->setupUi(this);

	//设置属性
	setAttribute(Qt::WA_QuitOnClose, false);
	setWindowFlag(Qt::FramelessWindowHint);

	//安装事件过滤器
	ui->titleBar->installEventFilter(this);
}

SettingsWidget::~SettingsWidget()
{
	delete ui;
}
//事件过滤器
bool SettingsWidget::eventFilter(QObject* watch, QEvent* e)
{
	if (watch == ui->titleBar) {
		if (e->type() == QEvent::MouseButtonPress) {
			QMouseEvent* event = static_cast<QMouseEvent*>(e);
			originPos = event->globalPosition().toPoint();
		}
		else if (e->type() == QEvent::MouseMove) {
			QMouseEvent* event = static_cast<QMouseEvent*>(e);
			QPoint dPos = event->globalPosition().toPoint() - originPos;
			move(pos() + dPos);
			originPos = event->globalPosition().toPoint();
		}
	}
	return false;
}
