#include "dialog.h"
#include "ui_dialog.h"
#include "globals.h"

Dialog::Dialog(QWidget *parent, int aWid, const QString &aTitle) : QDialog(parent), ui(new Ui::Dialog)
{
    ui->setupUi(this);

    //初始化变量
    fstPos = QPoint();
    zoomRate = aWid / STD_SCR_WIDTH;
    m_content = nullptr;
    selected = nullptr;

    //改大小
    resize(DialogDefines::STD_MAX_WIDTH * zoomRate, height());

    //窗口特效
    setWindowFlag(Qt::FramelessWindowHint);
    setAttribute(Qt::WA_TranslucentBackground);
    ui->titleBar->setAttribute(Qt::WA_TranslucentBackground);
    ui->buttonWidget->setAttribute(Qt::WA_TranslucentBackground);

    //改标题
    setWindowTitle(aTitle);

    //安装事件过滤器
    ui->titleBar->installEventFilter(this);

    write_log("对话框\"" + this->windowTitle() + "\"已创建");
}

//事件过滤器
bool Dialog::eventFilter(QObject* watch, QEvent* e)
{
    if(watch == ui->titleBar)
    {
        if(e->type() == QEvent::MouseButtonPress)
        {
			QMouseEvent* event = static_cast<QMouseEvent*>(e);
            fstPos = event->globalPosition().toPoint();
            return true;
        }
        if(e->type() == QEvent::MouseMove)
        {
            QMouseEvent* event = static_cast<QMouseEvent*>(e);
            QPoint dP = event->globalPosition().toPoint() - fstPos;
            move(pos() + dP);
            fstPos = event->globalPosition().toPoint();
            return true;
        }
		if(e->type() == QEvent::Paint)
		{
			Q_UNUSED(e)
			QWidget* wid = static_cast<QWidget*>(watch);
			round_corner(wid, QColor(238, 238, 238));
			QPainter painter(wid);
			painter.setPen(QPen(QColor(160, 160, 160)));
			painter.setBrush(QBrush(QColor(238, 238, 238)));
			painter.drawRect(0, 5, wid->width(), wid->height() - 5);
			painter.setPen(QColor(238, 238, 238));
			painter.drawLine(1, 5, wid->width() - 1, 5);

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
    if(wid->width() > width())
    {
        wid->resize(width(), wid->height());
    }

    //这一行修复了某些奇妙的BUG
    ui->titleBar->resize(wid->width(), DialogDefines::STD_TITLE_HEIGHT * zoomRate);

    resize(wid->width(), wid->height() + 2 * ui->titleBar->height());

    ui->contentWidget->setLayout(&layout);
    wid->resize(width(), ui->contentWidget->height());
    m_content = wid;
}

//改变大小
void Dialog::resizeEvent(QResizeEvent* e)
{
    QSize sz = e->size();

    //标题栏
    ui->titleBar->move(0, 0);
    ui->titleBar->resize(sz.width(), DialogDefines::STD_TITLE_HEIGHT * zoomRate);

    //标题
    ui->titleLabel->resize(sz.width(), ui->titleBar->height());

    //关闭按钮
    ui->closeButton->setIconSize(QSize(ui->titleBar->height(), ui->titleBar->height()));
    ui->closeButton->resize(ui->titleBar->height(), ui->titleBar->height());
    ui->closeButton->move(ui->titleBar->width() - ui->closeButton->width(), 0);

    //中心窗体
    ui->contentWidget->move(0, ui->titleBar->height());
    ui->contentWidget->resize(sz.width(), sz.height() - 2 * ui->titleBar->height());

    //底部按钮窗体
    ui->buttonWidget->move(0, ui->titleBar->height() + ui->contentWidget->height());
    ui->buttonWidget->resize(ui->titleBar->size());
}

//改标题槽函数
void Dialog::on_Dialog_windowTitleChanged(const QString &title)
{
    ui->titleLabel->setText(title);
}

//底部按钮点击
void Dialog::on_buttonWidget_clicked(QAbstractButton *button)
{
    selected = static_cast<QPushButton*>(button);
    hide();
    write_log("对话框\"" + this->windowTitle() + "\"关闭，选择了按钮\"" + selected->text() + "\"");
}

//添加按钮
QPushButton *Dialog::add_button(const QString &text)
{
    return ui->buttonWidget->addButton(text, QDialogButtonBox::NoRole);
}

void Dialog::paintEvent(QPaintEvent* e)
{
    Q_UNUSED(e)
	round_corner(this, QColor(249, 249, 249));
}

Dialog::~Dialog()
{
	qDeleteAll(ui->buttonWidget->buttons());
	delete ui;
}
