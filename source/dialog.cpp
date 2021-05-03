#include "dialog.h"
#include "ui_dialog.h"

Dialog::Dialog(QWidget *parent, int aWid, const QString &aTitle) : QDialog(parent), ui(new Ui::Dialog)
{
    ui->setupUi(this);

    //初始化变量
    fstPos = QPoint();
    zoomRate = aWid / STD_SCR_WIDTH;
    m_content = nullptr;

    //窗口特效
    setWindowFlag(Qt::FramelessWindowHint);

    //改标题
    setWindowTitle(aTitle);

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

//设置内容
void Dialog::setContent(QWidget* wid)
{
    //给中心窗体加layout
    QHBoxLayout layout(ui->contentWidget);
    layout.addWidget(wid);
    ui->contentWidget->setLayout(&layout);
    wid->resize(width(), ui->contentWidget->height());
    m_content = wid;
}

//改变大小
void Dialog::resizeEvent(QResizeEvent* e)
{
    Q_UNUSED(e)

    ui->titleBar->move(0, 0);
    ui->titleBar->resize(width(), STD_TITLE_HEIGHT * zoomRate);

    ui->closeButton->setIconSize(QSize(ui->titleBar->height(), ui->titleBar->height()));
    ui->closeButton->resize(ui->titleBar->height(), ui->titleBar->height());
    ui->closeButton->move(ui->titleBar->width() - ui->closeButton->width(), 0);

    ui->contentWidget->move(0, ui->titleBar->height());
    ui->contentWidget->resize(width(), height() - 2 * ui->titleBar->height());

    ui->buttonWidget->move(0, ui->titleBar->height() + ui->contentWidget->height());
    ui->buttonWidget->resize(ui->titleBar->size());
}

//改标题槽函数
void Dialog::on_Dialog_windowTitleChanged(const QString &title)
{
    ui->titleLabel->setText(title);
}

Dialog::~Dialog()
{
    delete ui;
}
