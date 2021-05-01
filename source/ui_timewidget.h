/********************************************************************************
** Form generated from reading UI file 'timewidget.ui'
**
** Created by: Qt User Interface Compiler version 5.12.10
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_TIMEWIDGET_H
#define UI_TIMEWIDGET_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QLabel>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_TimeWidget
{
public:
    QVBoxLayout *verticalLayout;
    QLabel *currentLabel;
    QLabel *timeLabel;
    QLabel *eventLabel;

    void setupUi(QWidget *TimeWidget)
    {
        if (TimeWidget->objectName().isEmpty())
            TimeWidget->setObjectName(QString::fromUtf8("TimeWidget"));
        TimeWidget->resize(170, 96);
        TimeWidget->setStyleSheet(QString::fromUtf8(""));
        verticalLayout = new QVBoxLayout(TimeWidget);
        verticalLayout->setObjectName(QString::fromUtf8("verticalLayout"));
        currentLabel = new QLabel(TimeWidget);
        currentLabel->setObjectName(QString::fromUtf8("currentLabel"));
        QFont font;
        font.setPointSize(5);
        font.setItalic(true);
        currentLabel->setFont(font);

        verticalLayout->addWidget(currentLabel);

        timeLabel = new QLabel(TimeWidget);
        timeLabel->setObjectName(QString::fromUtf8("timeLabel"));
        QFont font1;
        font1.setFamily(QString::fromUtf8("Microsoft YaHei"));
        font1.setPointSize(25);
        font1.setBold(true);
        font1.setWeight(75);
        timeLabel->setFont(font1);
        timeLabel->setStyleSheet(QString::fromUtf8("color: rgb(255, 255, 255);"));

        verticalLayout->addWidget(timeLabel);

        eventLabel = new QLabel(TimeWidget);
        eventLabel->setObjectName(QString::fromUtf8("eventLabel"));
        QFont font2;
        font2.setBold(false);
        font2.setItalic(true);
        font2.setWeight(50);
        eventLabel->setFont(font2);

        verticalLayout->addWidget(eventLabel);


        retranslateUi(TimeWidget);

        QMetaObject::connectSlotsByName(TimeWidget);
    } // setupUi

    void retranslateUi(QWidget *TimeWidget)
    {
        TimeWidget->setWindowTitle(QApplication::translate("TimeWidget", "TimeWidget", nullptr));
        currentLabel->setText(QApplication::translate("TimeWidget", "\345\275\223\345\211\215\346\227\266\351\227\264\357\274\232", nullptr));
        timeLabel->setText(QApplication::translate("TimeWidget", "00:00:00", nullptr));
        eventLabel->setText(QApplication::translate("TimeWidget", "(\346\234\252\345\220\257\347\224\250)", nullptr));
    } // retranslateUi

};

namespace Ui {
    class TimeWidget: public Ui_TimeWidget {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_TIMEWIDGET_H
