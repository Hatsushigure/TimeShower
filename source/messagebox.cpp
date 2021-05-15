#include "messagebox.h"

MessageBox::MessageBox(QWidget *parent, int aWid, const QString &aText, const QString &aTitle) : Dialog(parent, aWid, aTitle)
{
    //初始化内容
    QLabel* msg = new QLabel;
    msg->setText(aText);
    QFont ft = msg->font();
    ft.setFamily("楷体");
    ft.setPointSize(10);
    msg->setFont(ft);
    msg->setAlignment(Qt::AlignLeft | Qt::AlignTop);
    msg->setWordWrap(true);
    msg->adjustSize();

    setContent(msg);
}
