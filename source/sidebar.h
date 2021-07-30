#ifndef SIDEBAR_H
#define SIDEBAR_H

#include "timeshower.h"
#include "settings.h"
#include "messagebox.h"

namespace Ui {
class SideBar;
}

class SideBar : public QWidget
{
    Q_OBJECT

private:
    Ui::SideBar *ui;
    Settings* settings;
    SideBarType curType;
public:
    explicit SideBar(const QSize& parSize, Settings* st, QWidget *parent = nullptr);

    //设置类型
    void setType(SideBarType tp);

    //自动移动
    void auto_move(QPoint aPos, QSize aWH);    //后一个参数代表父窗体的宽高

    ~SideBar();

private slots:
    void on_minimizeButton_clicked();

    void on_settingsButton_clicked();

    void on_aboutButton_clicked();
signals:
    void app_minimize();
};

#endif // SIDEBAR_H
