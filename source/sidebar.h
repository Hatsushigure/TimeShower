#ifndef SIDEBAR_H
#define SIDEBAR_H

#include <QWidget>
#include <QApplication>
#include <QMessageBox>
#include <QIcon>
#include "settings.h"


namespace Ui {
class SideBar;
}

class SideBar : public QWidget
{
    Q_OBJECT

public:
    explicit SideBar(Settings* st, QWidget *parent = nullptr);
    ~SideBar();

private slots:
    void on_closeButton_clicked();

    void on_settingsButton_clicked();

    void on_aboutButton_clicked();

private:
    Ui::SideBar *ui;
    Settings* settings;
};

#endif // SIDEBAR_H
