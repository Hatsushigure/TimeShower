#include "dialog.h"
#include "ui_dialog.h"

Dialog::Dialog(QWidget *parent) : QDialog(parent), ui(new Ui::Dialog)
{
    ui->setupUi(this);

    //初始化变量
    fstPos = QPoint();

    //窗口特效
    setWindowFlag(Qt::FramelessWindowHint);

    //安装事件过滤器
    ui->titleBar->installEventFilter(this);
}

//事件过滤器
bool Dialog::eventFilter(QObject* watch, QEvent* e)
{
    if(watch == ui->titleBar)
    {
        if(e->type() == QEvent::MouseButtonPress)
        {
            QMouseEvent* event = static_cast<QMouseEvent*>(e);
            fstPos = event->globalPos();
            return true;
        }
        if(e->type() == QEvent::MouseMove)
        {
            QMouseEvent* event = static_cast<QMouseEvent*>(e);
            QPoint dP = event->globalPos() - fstPos;
            move(pos() + dP);
            fstPos = event->globalPos();
            return true;
        }
    }
    return false;
}

Dialog::~Dialog()
{
    delete ui;
}
