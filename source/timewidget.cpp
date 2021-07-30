#include "timewidget.h"
#include "ui_timewidget.h"

TimeWidget::TimeWidget(QWidget *parent) : QWidget(parent), ui(new Ui::TimeWidget)
{
    ui->setupUi(this);

    //初始化变量
    settings = new Settings;
    settings->write_log("设置对象已创建");
    scrWid = QApplication::desktop()->width();
    scrHei = QApplication::desktop()->height();
    settings->write_log(QString("成功获取屏幕宽高:").append(QString::number(scrWid)).append(", ").append(QString::number(scrHei)));
    movable = false;
    settings->write_log("设置为不可移动");
    fstPos = QPoint();
    curTime = QTime();
    mainTimer = new QTimer(this);
    settings->write_log("计时器已创建");
    bck = new BackgroundWidget(scrWid, scrHei);
    settings->write_log("菜单背景窗体创建成功");
    sideBar = nullptr;
    trayIcon = nullptr;
    actionExit = new QAction("退出");
    actionShow = new QAction("显示主界面");
    actionHide = new QAction("隐藏");
    trayMenu = new QMenu(this);

    //窗口效果
    setWindowFlags(Qt::WindowStaysOnTopHint | Qt::FramelessWindowHint | Qt::Tool);
    setAttribute(Qt::WA_TranslucentBackground);
    settings->write_log("窗口特效设置完毕");

    //设置界面元素显示效果
    ui->timeLabel->setStyleSheet("color:#E0E0E0");
    ui->currentLabel->setStyleSheet("color:#F7F7F7");
    ui->eventLabel->setStyleSheet("color:yellow");

    //移动及改变大小
    move(0, 0);
    resize(scrWid * settings->size() / SIZE_RATE, scrHei * settings->size() / SIZE_RATE);
    settings->write_log("窗口大小及位置初始化完毕");

    //处理侧边栏
    sideBar = new SideBar(size(), settings, this);
    settings->write_log("菜单侧边栏创建成功");

    //处理计时器
    mainTimer->setInterval(settings->timerInterval());
    mainTimer->start();
    settings->write_log("计时器已开启");

    //创建托盘图标
    add_tray_icon();

    //关联信号和槽
    connect(mainTimer, &QTimer::timeout, this, &TimeWidget::on_mainTimer_timeOut);
    connect(bck, &BackgroundWidget::stpMoving, this, &TimeWidget::on_bck_stpMoving);
    connect(sideBar, &SideBar::app_minimize, this, &TimeWidget::slotHide);
    connect(actionShow, &QAction::triggered, this, &TimeWidget::slotShow);
    connect(actionExit, &QAction::triggered, this, &QApplication::quit);
    connect(actionHide, &QAction::triggered, this, &TimeWidget::slotHide);
    settings->write_log("信号和槽关联成功，初始化结束");

    actionShow->trigger();
}

//创建系统托盘图标
void TimeWidget::add_tray_icon()
{
    trayIcon = new QSystemTrayIcon(this);
    trayIcon->setIcon(APP_ICON);
    trayIcon->setToolTip("时间显示器");

    //创建右键菜单
    trayMenu->addAction(actionShow);
    trayMenu->addAction(actionHide);
    trayMenu->addSeparator();
    trayMenu->addAction(actionExit);
    trayIcon->setContextMenu(trayMenu);
    settings->write_log("托盘右键菜单设置成功");

    trayIcon->show();
    settings->write_log("系统托盘图标创建成功");

    //测试
    trayIcon->showMessage("title", "message", APP_ICON);
}

//从托盘中唤起
void TimeWidget::slotShow()
{
    show();
    actionShow->setDisabled(true);
    actionHide->setEnabled(true);
    settings->write_log("主界面已显示");
}

//最小化
void TimeWidget::slotHide()
{
    movable = false;
    hide();
    bck->hide();
    actionShow->setEnabled(true);
    actionHide->setDisabled(true);
    settings->write_log("已最小化");
}


//关机槽函数
void TimeWidget::slotShutDown()
{
    system("shutdown -s -t 600");
}

//重启槽函数
void TimeWidget::slotRestart()
{
    system("shutdown -r -t 600");
}

//显示消息槽函数
void TimeWidget::slotShowMessage(QString msg)
{
    trayIcon->showMessage("来自\"TimeShower\"的消息", msg, APP_ICON);
}

void TimeWidget::mousePressEvent(QMouseEvent* e)
{
    if(movable)
    {
        fstPos = e->globalPos();
        settings->write_log("鼠标按下，开始移动");
    }
}

void TimeWidget::mouseMoveEvent(QMouseEvent *e)
{
    if(movable)
    {
        QPoint dP = e->globalPos() - fstPos;
        move(pos() + dP);
        fstPos = e->globalPos();
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
            auto_align(e->globalX(), e->globalY());
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
        sideBar->auto_move(pos(), size());

        settings->write_log(QString("移动至:(")
                            .append(QString::number(pos().x()))
                            .append(",")
                            .append(QString::number(pos().y()))
                            .append(")"));
    }
}

void TimeWidget::moveEvent(QMoveEvent* e)
{
    Q_UNUSED(e);

    if(sideBar != nullptr)
    {
        //移动侧边栏
        sideBar->auto_move(pos(), size());
    }
}

void TimeWidget::paintEvent(QPaintEvent* e)
{
    Q_UNUSED(e);

    QPainter painter(this);

    //绘制背景
    QPixmap tmp(":/resources/background.png");
    painter.setOpacity(0.3);
    painter.drawPixmap(QRect(0, 0, width(), height()), tmp);
}

void TimeWidget::on_mainTimer_timeOut()
{
    mainTimer->start();
    curTime = QTime::currentTime();
    ui->timeLabel->setText(curTime.toString());

    if(curTime.hour() == 21 && curTime.minute() == 53 && curTime.second() == 0)
    {
        settings->write_log("检测是否自动关机:true");
        system("shutdown -s -t 300");
    }
}

void TimeWidget::on_bck_stpMoving()
{
    bck->hide();
    sideBar->hide();
    movable = false;
    settings->write_log("接收到停止移动信号，移动结束");
}


//自动对齐
void TimeWidget::auto_align(int aX, int aY)
{
    //获取网格宽度和高度
    double gridWid = double(scrWid) * double(settings->size()) / double(SIZE_RATE);
    double gridHei = double(scrHei) * double(settings->size()) / double(SIZE_RATE);

    int gridX = aX / gridWid;
    int gridY = aY / gridHei;
    move(width() * gridX, height() * gridY);
    settings->write_log("已自动对齐至网格");
}

TimeWidget::~TimeWidget()
{
    delete ui;
    settings->write_log("主窗口被析构");
}
