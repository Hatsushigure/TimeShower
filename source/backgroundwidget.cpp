#include "backgroundwidget.h"
#include "ui_backgroundwidget.h"

BackgroundWidget::BackgroundWidget(int aWid, int aHei, QWidget *parent) : QWidget(parent), ui(new Ui::BackgroundWidget)
{
    ui->setupUi(this);

    //窗口特效
    setWindowFlags(Qt::Tool | Qt::FramelessWindowHint);
    setAttribute(Qt::WA_TranslucentBackground);

    //窗口大小及位置
    resize(aWid, aHei);
    move(0, 0);

    hide();
}

void BackgroundWidget::mousePressEvent(QMouseEvent* e)
{
    Q_UNUSED(e)
    emit stpMoving();
}

void BackgroundWidget::paintEvent(QPaintEvent* e)
{
    Q_UNUSED(e)
    QPainter painter(this);
    QPixmap pix;
    pix.load(":/resources/background.png");
    painter.setOpacity(0.3);
    painter.drawPixmap(QRect(0, 0, width(), height()), pix);
}

BackgroundWidget::~BackgroundWidget()
{
    delete ui;
}
