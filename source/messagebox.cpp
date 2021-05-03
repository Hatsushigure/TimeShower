#include "messagebox.h"

MessageBox::MessageBox(QWidget *parent, int aWid, const QString &aText, const QString &aTitle) : Dialog(parent, aWid, aTitle)
{
    //初始化内容
    QLabel* msg = new QLabel;
    msg->setText(aText);
    QFont ft = msg->font();
    ft.setFamily("微软雅黑");
    ft.setPointSize(10);
    ft.setBold(true);
    msg->setFont(ft);
    msg->setAlignment(Qt::AlignLeft | Qt::AlignVCenter);
    qDebug() << msg->width();
    qDebug() << width();

    setContent(msg);
}
