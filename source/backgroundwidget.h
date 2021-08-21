#pragma once
#include "timeshower.h"
#include "globals.h"

namespace Ui {
class BackgroundWidget;
}

class BackgroundWidget : public QWidget
{
    Q_OBJECT

private:
    Ui::BackgroundWidget *ui;
public:
	explicit BackgroundWidget();

    void mousePressEvent(QMouseEvent* e);

    void paintEvent(QPaintEvent* e);

    ~BackgroundWidget();
signals:
    void stpMoving();
};
