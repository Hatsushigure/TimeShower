#pragma once
#include "timeshower.h"
#include "dialog.h"

class MessageBox : public Dialog
{
    Q_OBJECT
public:
    MessageBox(QWidget* parent, int aWid, const QString& aText, const QString& aTitle);
};
