#ifndef DIALOG_H
#define DIALOG_H

#include "timeshower.h"

namespace Ui {
class Dialog;
}

class Dialog : public QDialog
{
    Q_OBJECT

private:
    Ui::Dialog *ui;
    QPoint fstPos;
    double zoomRate;
    QWidget* m_content;
public:
    explicit Dialog(QWidget* parent, int aWid, const QString& aTitle);

    //事件过滤器
    bool eventFilter(QObject* watch, QEvent* e);

    //设置内容
    void setContent(QWidget *wid);

    //改变大小
    void resizeEvent(QResizeEvent* e);

    //返回中心窗体
    QWidget* content() {return m_content;}

    ~Dialog();
private slots:
    //改标题槽函数
    void on_Dialog_windowTitleChanged(const QString &title);
};

#endif // DIALOG_H
