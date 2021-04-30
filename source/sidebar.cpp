#include "sidebar.h"
#include "ui_sidebar.h"

SideBar::SideBar(Settings* st, QWidget *parent) : QWidget(nullptr), ui(new Ui::SideBar)
{
    ui->setupUi(this);

    settings = st;

    setWindowFlags(Qt::WindowStaysOnTopHint | Qt::Tool | Qt::FramelessWindowHint);
    setAttribute(Qt::WA_TranslucentBackground);
    int tmp = parent->width() / 8;
    ui->closeButton->setIconSize(QSize(tmp, tmp));
    ui->settingsButton->setIconSize(QSize(tmp, tmp));
    ui->aboutButton->setIconSize(QSize(tmp, tmp));
    resize(tmp, parent->height());
    hide();
}

void SideBar::on_settingsButton_clicked()
{
    QMessageBox::information(this, "", "暂时不提供图形设置界面！");
    settings->write_log("设置按钮被点击");
}

void SideBar::on_closeButton_clicked()
{
    settings->write_log("关闭按钮被点击");
    QApplication::quit();
}

void SideBar::on_aboutButton_clicked()
{
    settings->write_log("关于按钮被点击");
    QMessageBox aboutMessage(this);
    aboutMessage.setWindowTitle("关于 \"时间显示器\"");
    aboutMessage.setText("    此应用为时间显示应用，可在屏幕上置顶显示时间。\n    当前版本:1.0.1\n    作者:czj_____");
    QPushButton aboutQtButton("关于 \"Qt\"", &aboutMessage);
    aboutMessage.addButton(QMessageBox::StandardButton::Ok);
    aboutMessage.addButton(&aboutQtButton, QMessageBox::ButtonRole::HelpRole);
    aboutMessage.exec();
    if(aboutMessage.clickedButton() == &aboutQtButton)
    {
        QMessageBox::aboutQt(this);
    }
}

SideBar::~SideBar()
{
    settings->write_log("侧边栏被析构");
    delete ui;
}
