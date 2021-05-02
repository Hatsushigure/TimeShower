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
public:
    explicit Dialog(QWidget *parent = nullptr);

    //事件过滤器
    bool eventFilter(QObject* watch, QEvent* e);

    ~Dialog();
};

#endif // DIALOG_H
