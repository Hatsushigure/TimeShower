#include "sidebar.h"
#include "ui_sidebar.h"

SideBar::SideBar(const QSize &parSize, Settings* st, QWidget *parent) : QWidget(parent), ui(new Ui::SideBar)
{
    ui->setupUi(this);

    //初始化变量
    settings = st;
    curType = SideBarType::right;

    //窗口特效
    setWindowFlags(Qt::WindowStaysOnTopHint | Qt::Tool | Qt::FramelessWindowHint);
    setAttribute(Qt::WA_TranslucentBackground);

    int tmp = parSize.width() / SIZE_RATE;
    ui->closeButton->setIconSize(QSize(tmp, tmp));
    ui->settingsButton->setIconSize(QSize(tmp, tmp));
    ui->aboutButton->setIconSize(QSize(tmp, tmp));

    resize(tmp, parSize.height());

    hide();
}

void SideBar::on_settingsButton_clicked()
{
    MessageBox inf(this, QApplication::desktop()->width(), "    暂时不提供图形设置界面!", "提示");
    inf.exec();

    settings->write_log("设置按钮被点击");
}

void SideBar::on_closeButton_clicked()
{
    settings->write_log("关闭按钮被点击");
    QApplication::quit();
}

void SideBar::on_aboutButton_clicked()
{
    MessageBox about(this, QApplication::desktop()->width(), "    此应用为时间显示应用，可在屏幕上置顶显示时间。\n    当前版本:1.1.2\n    作者:czj_____", "关于 \"时间显示器\"");
    about.exec();
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

SideBar::~SideBar()
{
    settings->write_log("侧边栏被析构");
    delete ui;
}
