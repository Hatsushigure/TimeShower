#include "mainwidget.h"
#include "ui_mainwidget.h"
#include <QPainter>

MainWidget::MainWidget(QWidget* parent)
	: QWidget(parent), ui(new Ui::MainWidget)
{
	ui->setupUi(this);
	//设置显示效果
	setAttribute(Qt::WA_TranslucentBackground);
	setWindowFlag(Qt::FramelessWindowHint);

	ui->titleBar->setSizePolicy(QSizePolicy::Preferred, QSizePolicy::Fixed);
	ui->titleBar->setFixedHeight(scale(TITLE_HEIGHT));
	ui->eventLabel->setSizePolicy(QSizePolicy::Preferred, QSizePolicy::Fixed);
	ui->eventLabel->setFixedHeight(scale(TITLE_HEIGHT));
	QFont tmp = ui->titleText->font();
	tmp.setPixelSize(scrSize.width() /160);
	ui->titleText->setFont(tmp);
	ui->redDot->setFont(tmp);
	qDebug() <<ui->titleText->height();

	initVariants();
	initConnections();

	//测试代码
	initMoveAnimation();
}

MainWidget::~MainWidget()
{
	delete ui;
	delete m_moveAnimation;
}

//绘图事件
void MainWidget::paintEvent(QPaintEvent* event)
{
	Q_UNUSED(event);
	QPainter painter(this);
	QBrush brush(QColor(0, 0, 0, 20));
	painter.setBrush(brush);
	painter.setRenderHint(QPainter::Antialiasing);
	painter.drawRoundedRect(0, 0, width(), height(), borderRadius, borderRadius);
}

//鼠标双击事件
void MainWidget::mouseDoubleClickEvent(QMouseEvent* event)
{
	Q_UNUSED(event);
	emit sigMove();
}

//鼠标按下事件
void MainWidget::mousePressEvent(QMouseEvent* event)
{
	if (m_isMovable)
	{
		m_originPos = event->globalPosition().toPoint();
		m_moveAnimation->setDirection(QPropertyAnimation::Forward);
		m_moveAnimation->start();
	}
}

//鼠标移动事件
void MainWidget::mouseMoveEvent(QMouseEvent* event)
{
	if (m_isMovable)
	{
		QPoint tmp = event->globalPosition().toPoint();
		QPoint dPos = tmp - m_originPos;
		move(pos() + dPos);
		m_originPos = tmp;
	}
}

//鼠标松开事件
void MainWidget::mouseReleaseEvent(QMouseEvent* event)
{
	Q_UNUSED(event);
	if (m_isMovable)
	{
		m_moveAnimation->setDirection(QPropertyAnimation::Backward);
		m_moveAnimation->start();
	}
}

//大小改变事件
void MainWidget::resizeEvent(QResizeEvent* event)
{
	QFont fnt =ui->timeLabel->font();
	fnt.setBold(true);
	fnt.setPixelSize(event->size().width() / 6);
	ui->timeLabel->setFont(fnt);
}

//关联信号和槽
void MainWidget::initConnections()
{
	connect(this, &MainWidget::sigMove, this, &MainWidget::slotMove);
}

//初始化变量
void MainWidget::initVariants()
{
	m_isMovable = false;
	m_originPos = QPoint();
	m_moveAnimation = new QPropertyAnimation(this, "size");
}

//初始化动画
void MainWidget::initMoveAnimation()
{
	m_moveAnimation->setStartValue(size());
	m_moveAnimation->setEndValue(QSize(size().width() * 0.85, size().height() * 0.85));
	m_moveAnimation->setEasingCurve(QEasingCurve::OutCirc);
	m_moveAnimation->setDuration(200);
}

//移动槽函数
void MainWidget::slotMove()
{
	m_isMovable = true;
}

