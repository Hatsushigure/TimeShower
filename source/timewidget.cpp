#include "timewidget.h"
#include "ui_timewidget.h"
#include "main.cpp"

TimeWidget::TimeWidget(QWidget *parent) : QWidget(parent), ui(new Ui::TimeWidget)
{
    ui->setupUi(this);

    //初始化变量
    settings = new Settings;
    settings->write_log("设置对象已创建");
    scrWid = QApplication::desktop()->width();
    scrHei = QApplication::desktop()->height();
    settings->write_log(QString("成功获取屏幕宽高: ").append(QString::number(scrWid)).append(", ").append(QString::number(scrHei)));
    movable = false;
    settings->write_log("设置为不可移动");
    fstPos = QPoint();
    curTime = QTime();
    mainTimer = new QTimer(this);
    settings->write_log("计时器已创建");
    size = settings->size();
    bck = new BackgroundWidget;
    settings->write_log("菜单背景窗体创建成功");
    sideBar = nullptr;

    //窗口效果
    setWindowFlags(Qt::WindowStaysOnTopHint | Qt::FramelessWindowHint | Qt::Tool);
    setAttribute(Qt::WA_TranslucentBackground);
    settings->write_log("窗口特效设置完毕");

    //移动及改变大小
    move(0, 0);
    resize(scrWid * size / SIZE_RATE, scrHei * size / SIZE_RATE);
    settings->write_log("窗口大小及位置初始化完毕");

    //处理侧边栏
    sideBar = new SideBar(settings, this);
    settings->write_log("菜单侧边栏创建成功");

    //处理计时器
    mainTimer->setInterval(TIMER_INTERVAL);
    mainTimer->start();
    settings->write_log("计时器已开启");

    //关联信号和槽
    connect(mainTimer, &QTimer::timeout, this, &TimeWidget::on_mainTimer_timeOut);
    connect(bck, &BackgroundWidget::stpMoving, this, &TimeWidget::on_bck_stpMoving);
    settings->write_log("信号和槽关联成功，初始化结束");
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
    Q_UNUSED(e)
    if(!bck->isHidden())
    {
        movable = true;
        settings->write_log("可移动设置为true");
    }
}

void TimeWidget::moveEvent(QMoveEvent* e)
{
    if(sideBar != nullptr)
    {
        sideBar->move(e->pos().x() + width(), e->pos().y());
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

TimeWidget::~TimeWidget()
{
    delete ui;
    settings->write_log("主窗口被析构");
}
