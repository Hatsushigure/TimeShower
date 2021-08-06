#pragma once
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
    QPushButton* selected;
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

    //返回当前选中的按钮
    QPushButton* get_button() {return selected;}

    //添加按钮
    QPushButton* add_button(const QString& text);

    void paintEvent(QPaintEvent* e);

    ~Dialog();
private slots:
    //改标题槽函数
    void on_Dialog_windowTitleChanged(const QString &title);
    void on_buttonWidget_clicked(QAbstractButton *button);
};
