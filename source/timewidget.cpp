#include "backgroundwidget.h"
#include "timeeventmanager.h"
#include "timewidget.h"
#include "ui_timewidget.h"
#include "sidebar.h"

TimeWidget::TimeWidget(QWidget *parent) : QWidget(parent), ui(new Ui::TimeWidget)
{
    ui->setupUi(this);

    //初始化变量
    write_log("正在初始化时间表");

	originSize = scale(size());

    evMgr = new TimeEventManager;
	evMgr->connect_events();

    //以下3行将会修改
    scrWid = scrSize.width();
    scrHei = scrSize.height();
    write_log(QString("成功获取屏幕宽高:")+ QString::number(scrWid) + ", " + QString::number(scrHei));

    movable = false;
    write_log("设置为不可移动");

    fstPos = QPoint();
    curTime = QTime();

    mainTimer = new QTimer(this);
    write_log("计时器已创建");

	bck = new BackgroundWidget();

    sideBar = nullptr;

    trayIcon = nullptr;
    actionExit = new QAction("退出");
    actionShow = new QAction("显示主界面");
    actionHide = new QAction("隐藏");
    trayMenu = new QMenu(this);
    write_log("系统托盘相关变量初始化完成");

    //窗口效果
    setWindowFlags(Qt::WindowStaysOnTopHint | Qt::FramelessWindowHint | Qt::Tool);
    setAttribute(Qt::WA_TranslucentBackground);
    write_log("主窗口特效设置完毕");

    //设置界面元素显示效果
    ui->timeLabel->setStyleSheet("color:#E0E0E0");
    ui->currentLabel->setStyleSheet("color:#F7F7F7");
    ui->eventLabel->setStyleSheet("color:yellow");
    write_log("字体颜色设置完毕");

    //移动及改变大小
	move(0, 0);	//改
	resize(scrSize * settings->size());
    write_log("主窗口大小及位置初始化完毕");

    //处理计时器
    mainTimer->setInterval(settings->timerInterval());
    mainTimer->start();
    write_log("计时器已开启");

    //创建托盘图标
	addTrayIcon();

    //关联信号和槽
    connect(mainTimer, &QTimer::timeout, this, &TimeWidget::on_mainTimer_timeOut);
    connect(bck, &BackgroundWidget::stpMoving, this, &TimeWidget::on_bck_stpMoving);
    connect(actionShow, &QAction::triggered, this, &TimeWidget::slotShow);
    connect(actionExit, &QAction::triggered, this, &TimeWidget::slotExit);
    connect(actionHide, &QAction::triggered, this, &TimeWidget::slotHide);
    write_log("信号和槽关联成功，初始化结束");

    actionShow->trigger();
}

//创建系统托盘图标
void TimeWidget::addTrayIcon()
{
    trayIcon = new QSystemTrayIcon(this);
    trayIcon->setIcon(appIcon);
    trayIcon->setToolTip("时间显示器");

    //创建右键菜单
    trayMenu->addAction(actionShow);
    trayMenu->addAction(actionHide);
    trayMenu->addSeparator();
    trayMenu->addAction(actionExit);
    trayIcon->setContextMenu(trayMenu);
    write_log("托盘右键菜单设置成功");

    trayIcon->show();
    write_log("系统托盘图标创建成功");
}

//从托盘中唤起
void TimeWidget::slotShow()
{
	show();
    actionShow->setDisabled(true);
    actionHide->setEnabled(true);
    write_log("主界面已显示");
}

//最小化
void TimeWidget::slotHide()
{
    movable = false;
    hide();
    bck->hide();
    sideBar->hide();
    actionShow->setEnabled(true);
    actionHide->setDisabled(true);
    write_log("已最小化");
}


//关机槽函数
void TimeWidget::slotShutDown()
{
    write_log("关机事件触发");
	shutdownPrerock();
}

//重启槽函数
void TimeWidget::slotRestart()
{
    write_log("重启事件触发");
    system("shutdown -r -t 600");
}

//显示消息槽函数
void TimeWidget::slotShowMessage(QString msg)
{
    trayIcon->showMessage("来自\"TimeShower\"的消息", msg, appIcon);
    write_log("已显示消息\"" + msg + "\"");
}

//退出槽函数
void TimeWidget::slotExit()
{
    write_log("退出事件触发");
    delete trayIcon;
    delete trayMenu;
    delete sideBar;
    delete bck;
    QApplication::quit();
}

//事件变更槽函数
void TimeWidget::slotEventChanged(QString name)
{
	ui->eventLabel->setText(name);

	//写日志
	write_log("当前事件:" + name);
}

void TimeWidget::mousePressEvent(QMouseEvent* e)
{
    if(movable)
    {
        fstPos = e->globalPosition().toPoint();
        write_log("鼠标按下");
    }
}

void TimeWidget::mouseMoveEvent(QMouseEvent *e)
{
    if(movable)
    {
        QPoint dP = e->globalPosition().toPoint() - fstPos;
        move(pos() + dP);
        fstPos = e->globalPosition().toPoint();
    }
}

void TimeWidget::mouseDoubleClickEvent(QMouseEvent* e)
{
    Q_UNUSED(e)
    if(!movable)
    {
        sideBar->show();
        bck->show();
    }
}

void TimeWidget::mouseReleaseEvent(QMouseEvent* e)
{
    if(!bck->isHidden())
    {
        movable = true;
        //自动对齐
        if(settings->doAutoAlign())
        {
			autoAlign(e->globalPosition().toPoint());
        }

        //调整侧边栏位置
        if(x() + width() + sideBar->width() > scrWid)
        {
            sideBar->setType(SideBarType::left);
        }
        else if(x() - sideBar->width() < 0)
        {
            sideBar->setType(SideBarType::right);
        }
		sideBar->autoMove();

        write_log("移动至：(" + QString::number(x()) + ", " + QString::number(y()) + ")");
    }
}

void TimeWidget::moveEvent(QMoveEvent* e)
{
    Q_UNUSED(e);

    if(sideBar != nullptr)
    {
        //移动侧边栏
		sideBar->autoMove();
    }
}

void TimeWidget::paintEvent(QPaintEvent* e)
{
    Q_UNUSED(e);
    round_corner(this, QColor(220, 220, 220, 100));
}

void TimeWidget::on_mainTimer_timeOut()
{
    mainTimer->start();
    curTime = QTime::currentTime();
    ui->timeLabel->setText(curTime.toString());
    evMgr->trigger();

	//测试代码
	updateSettings();
}

void TimeWidget::on_bck_stpMoving()
{
    bck->hide();
    sideBar->hide();
    movable = false;
    write_log("接收到停止移动信号，移动结束");
}


//自动对齐
void TimeWidget::autoAlign(QPoint pos)
{
    //获取网格宽度和高度
    double gridWid = scrWid * settings->size();
    double gridHei = scrHei * settings->size();

    int gridX = pos.x() / gridWid;
    int gridY = pos.y() / gridHei;
    int aX = width() * gridX;
    int aY = height() * gridY;
    move(aX, aY);
    write_log("已自动对齐至网格");
	qDebug() << gridX << "  " << gridY;
}

//真·关机前摇
void TimeWidget::shutdownPrerock()
{
	Dialog dlg(bck, scrSize.width(), "关机提示");
	dlg.resize(scrSize);
	QLabel content("您将在" + QString::number(settings->shutdownPrerock()) + "秒后被注销\n请保存好当前未完成的工作！");
	content.setFont(QFont("微软雅黑", 30, 1));
	//content.setWordWrap(true);
	content.setAlignment(Qt::AlignHCenter);
	content.adjustSize();
	dlg.setContent(&content);
	dlg.add_button("确定");
	QPushButton* btnShudown = dlg.add_button("我想现在关机");
	dlg.add_button("我想让电脑蓝瓶钙");

	shutDownTimer = new QTimer;
	shutDownTimer->start(settings->shutdownPrerock() * 1000);
	connect(shutDownTimer, &QTimer::timeout, this, [](){
		system("shutdown -s -t 0");
	});
	write_log("关机计时器已创建");

	bck->show();
	dlg.exec();
	bck->hide();

	if(dlg.get_button() == btnShudown)
	{
		system("shutdown -s -t 0");
	}
}

//自动resize
void TimeWidget::autoResize()
{
	resize(scrSize * settings->size());
}

//更新设置
void TimeWidget::updateSettings()
{
	settings->read_settings();
	autoResize();
	sideBar->autoResize();
	mainTimer->setInterval(settings->timerInterval());
}

TimeWidget::~TimeWidget()
{
    delete ui;
    write_log("主窗口被析构");
}
