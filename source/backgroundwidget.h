#pragma once
#include "timeshower.h"

namespace Ui {
class BackgroundWidget;
}

class BackgroundWidget : public QWidget
{
    Q_OBJECT

private:
    Ui::BackgroundWidget *ui;
public:
    explicit BackgroundWidget(int aWid, int aHei, QWidget *parent = nullptr);

    void mousePressEvent(QMouseEvent* e);

    void paintEvent(QPaintEvent* e);

    ~BackgroundWidget();
signals:
    void stpMoving();
};
