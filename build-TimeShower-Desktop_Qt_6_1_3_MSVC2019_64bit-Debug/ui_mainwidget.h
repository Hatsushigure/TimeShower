/********************************************************************************
** Form generated from reading UI file 'mainwidget.ui'
**
** Created by: Qt User Interface Compiler version 6.1.3
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_MAINWIDGET_H
#define UI_MAINWIDGET_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QLabel>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_MainWidget
{
public:
    QVBoxLayout *verticalLayout;
    QWidget *titleBar;
    QHBoxLayout *horizontalLayout;
    QLabel *titleText;
    QLabel *redDot;
    QLabel *timeLabel;
    QLabel *eventLabel;

    void setupUi(QWidget *MainWidget)
    {
        if (MainWidget->objectName().isEmpty())
            MainWidget->setObjectName(QString::fromUtf8("MainWidget"));
        MainWidget->resize(170, 96);
        verticalLayout = new QVBoxLayout(MainWidget);
        verticalLayout->setObjectName(QString::fromUtf8("verticalLayout"));
        titleBar = new QWidget(MainWidget);
        titleBar->setObjectName(QString::fromUtf8("titleBar"));
        horizontalLayout = new QHBoxLayout(titleBar);
        horizontalLayout->setSpacing(0);
        horizontalLayout->setObjectName(QString::fromUtf8("horizontalLayout"));
        horizontalLayout->setContentsMargins(0, 0, 0, 0);
        titleText = new QLabel(titleBar);
        titleText->setObjectName(QString::fromUtf8("titleText"));
        QSizePolicy sizePolicy(QSizePolicy::Preferred, QSizePolicy::Fixed);
        sizePolicy.setHorizontalStretch(0);
        sizePolicy.setVerticalStretch(0);
        sizePolicy.setHeightForWidth(titleText->sizePolicy().hasHeightForWidth());
        titleText->setSizePolicy(sizePolicy);
        QFont font;
        font.setPointSize(9);
        titleText->setFont(font);

        horizontalLayout->addWidget(titleText);

        redDot = new QLabel(titleBar);
        redDot->setObjectName(QString::fromUtf8("redDot"));
        QSizePolicy sizePolicy1(QSizePolicy::Preferred, QSizePolicy::Preferred);
        sizePolicy1.setHorizontalStretch(0);
        sizePolicy1.setVerticalStretch(0);
        sizePolicy1.setHeightForWidth(redDot->sizePolicy().hasHeightForWidth());
        redDot->setSizePolicy(sizePolicy1);
        redDot->setFont(font);

        horizontalLayout->addWidget(redDot);


        verticalLayout->addWidget(titleBar);

        timeLabel = new QLabel(MainWidget);
        timeLabel->setObjectName(QString::fromUtf8("timeLabel"));
        QSizePolicy sizePolicy2(QSizePolicy::Preferred, QSizePolicy::Expanding);
        sizePolicy2.setHorizontalStretch(0);
        sizePolicy2.setVerticalStretch(0);
        sizePolicy2.setHeightForWidth(timeLabel->sizePolicy().hasHeightForWidth());
        timeLabel->setSizePolicy(sizePolicy2);
        QFont font1;
        font1.setFamilies({QString::fromUtf8("Microsoft YaHei")});
        font1.setPointSize(26);
        timeLabel->setFont(font1);

        verticalLayout->addWidget(timeLabel);

        eventLabel = new QLabel(MainWidget);
        eventLabel->setObjectName(QString::fromUtf8("eventLabel"));
        sizePolicy.setHeightForWidth(eventLabel->sizePolicy().hasHeightForWidth());
        eventLabel->setSizePolicy(sizePolicy);

        verticalLayout->addWidget(eventLabel);


        retranslateUi(MainWidget);

        QMetaObject::connectSlotsByName(MainWidget);
    } // setupUi

    void retranslateUi(QWidget *MainWidget)
    {
        MainWidget->setWindowTitle(QCoreApplication::translate("MainWidget", "TimeShower\344\270\273\347\252\227\345\217\243", nullptr));
        titleText->setText(QCoreApplication::translate("MainWidget", "TimeShower", nullptr));
        redDot->setText(QCoreApplication::translate("MainWidget", "\345\260\217\347\272\242\347\202\271", nullptr));
        timeLabel->setText(QCoreApplication::translate("MainWidget", "00:00:00", nullptr));
        eventLabel->setText(QCoreApplication::translate("MainWidget", "(\346\227\240\344\272\213\344\273\266)", nullptr));
    } // retranslateUi

};

namespace Ui {
    class MainWidget: public Ui_MainWidget {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MAINWIDGET_H
