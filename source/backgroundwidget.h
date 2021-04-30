#pragma once
#include <QWidget>
#include <QPalette>
#include <QColor>
#include <QMouseEvent>
#include <QPaintEvent>
#include <QPainter>
#include <QDesktopWidget>

namespace Ui {
class BackgroundWidget;
}

class BackgroundWidget : public QWidget
{
    Q_OBJECT

public:
    explicit BackgroundWidget(QWidget *parent = nullptr);

    void mousePressEvent(QMouseEvent* e);

    void paintEvent(QPaintEvent* e);

    ~BackgroundWidget();

private:
    Ui::BackgroundWidget *ui;
    int scrWid;
    int scrHei;

signals:
    void stpMoving();
};
