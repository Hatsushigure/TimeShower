#ifndef MESSAGEBOX_H
#define MESSAGEBOX_H

#include "timeshower.h"
#include "dialog.h"

class MessageBox : public Dialog
{
    Q_OBJECT
public:
    MessageBox(QWidget* parent, int aWid, const QString& aText, const QString& aTitle);
};

#endif // MESSAGEBOX_H
