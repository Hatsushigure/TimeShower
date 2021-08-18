#include "sidebar.h"
#include "ui_sidebar.h"

SideBar::SideBar(const QSize &parSize, QWidget *parent) : QWidget(parent), ui(new Ui::SideBar)
{
    ui->setupUi(this);

    //初始化变量
    curType = SideBarType::right;

    //窗口特效
    setWindowFlags(Qt::WindowStaysOnTopHint | Qt::Tool | Qt::FramelessWindowHint);
    setAttribute(Qt::WA_TranslucentBackground);

    int tmp = parSize.width() / 8;  //待修复的magic number
    ui->minimizeButton->setIconSize(QSize(tmp, tmp));
    ui->settingsButton->setIconSize(QSize(tmp, tmp));
    ui->aboutButton->setIconSize(QSize(tmp, tmp));

    resize(tmp, parSize.height());

    hide();

    write_log("菜单侧边栏创建成功");
}

void SideBar::on_settingsButton_clicked()
{
    write_log("“设置”按钮被点击");

    MessageBox inf(this, scrSize.width(), "    暂时不提供图形设置界面!", "提示");
    inf.add_button("确定");
    inf.exec();
}

void SideBar::on_minimizeButton_clicked()
{
    write_log("最小化按钮被点击");
    emit signalHide();
    write_log("已发送最小化信号");
}

void SideBar::on_aboutButton_clicked()
{
    write_log("“关于”按钮被点击");

	MessageBox about(this, scrSize.width(), "    此应用为时间显示应用，可在屏幕上置顶显示时间。\n    当前版本:1.2.2\n    作者:czj_____", "关于 \"时间显示器\"");
    QPushButton* btn = about.add_button("关于Qt");
    about.add_button("确定");
    about.exec();
    if(about.get_button() == btn)
    {
        QApplication::aboutQt();
    }
}

//自动移动
void SideBar::auto_move(QPoint aPos, QSize aWH)
{
    switch(curType)
    {
    case SideBarType::right:
        move(aPos + QPoint(aWH.width(), 0));
        break;
    case SideBarType::left:
        move(aPos - QPoint(width(), 0));
        break;
    default:
        break;
    }
}

//设置类型
void SideBar::setType(SideBarType tp)
{
    curType = tp;
}

void SideBar::paintEvent(QPaintEvent* e)
{
    Q_UNUSED(e)
    round_corner(this, QColor(220, 220, 220, 100));
}

SideBar::~SideBar()
{
    delete ui;
    write_log("侧边栏被析构");
}
