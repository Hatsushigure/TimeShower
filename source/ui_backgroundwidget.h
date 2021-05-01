/********************************************************************************
** Form generated from reading UI file 'backgroundwidget.ui'
**
** Created by: Qt User Interface Compiler version 5.12.10
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_BACKGROUNDWIDGET_H
#define UI_BACKGROUNDWIDGET_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_BackgroundWidget
{
public:

    void setupUi(QWidget *BackgroundWidget)
    {
        if (BackgroundWidget->objectName().isEmpty())
            BackgroundWidget->setObjectName(QString::fromUtf8("BackgroundWidget"));
        BackgroundWidget->resize(1366, 768);
        BackgroundWidget->setWindowOpacity(1.000000000000000);

        retranslateUi(BackgroundWidget);

        QMetaObject::connectSlotsByName(BackgroundWidget);
    } // setupUi

    void retranslateUi(QWidget *BackgroundWidget)
    {
        BackgroundWidget->setWindowTitle(QApplication::translate("BackgroundWidget", "Form", nullptr));
    } // retranslateUi

};

namespace Ui {
    class BackgroundWidget: public Ui_BackgroundWidget {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_BACKGROUNDWIDGET_H
