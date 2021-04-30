#ifndef SIDEBAR_H
#define SIDEBAR_H

#include <QWidget>
#include <QApplication>
#include <QMessageBox>
#include <QIcon>
#include "settings.h"

enum class SideBarType {left, right};

namespace Ui {
class SideBar;
}

class SideBar : public QWidget
{
    Q_OBJECT

public:
    explicit SideBar(Settings* st, QWidget *parent = nullptr);

    //设置类型
    void setType(SideBarType tp);

    //自动移动
    void auto_move();

    ~SideBar();

private slots:
    void on_closeButton_clicked();

    void on_settingsButton_clicked();

    void on_aboutButton_clicked();
private:
    Ui::SideBar *ui;
    Settings* settings;
    SideBarType curType;
    QWidget* par;
};

#endif // SIDEBAR_H
