#include "settingswidget.h"
#include "ui_settingswidget.h"

SettingsWidget::SettingsWidget(QWidget *parent) : QWidget(parent), ui(new Ui::SettingsWidget)
{
	ui->setupUi(this);

	//设置属性
	setWindowFlag(Qt::FramelessWindowHint);
	setAttribute(Qt::WA_QuitOnClose, false);
	setAttribute(Qt::WA_TranslucentBackground);

	//安装事件过滤器
	ui->titleBar->installEventFilter(this);

	//添加按钮
	QPushButton* btn1 = new QPushButton(QIcon(":/resources/fluentStyle/buttons/close.svg"), "");
	btn1->setFlat(true);
	ui->buttonBox->addButton(btn1, QDialogButtonBox::NoRole);
	btn1->setIconSize(QSize(30, 30));
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
