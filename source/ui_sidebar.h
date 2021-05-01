/********************************************************************************
** Form generated from reading UI file 'sidebar.ui'
**
** Created by: Qt User Interface Compiler version 5.12.10
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_SIDEBAR_H
#define UI_SIDEBAR_H

#include <QtCore/QVariant>
#include <QtGui/QIcon>
#include <QtWidgets/QApplication>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QSpacerItem>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_SideBar
{
public:
    QVBoxLayout *verticalLayout;
    QPushButton *closeButton;
    QSpacerItem *verticalSpacer_2;
    QPushButton *aboutButton;
    QSpacerItem *verticalSpacer;
    QPushButton *settingsButton;

    void setupUi(QWidget *SideBar)
    {
        if (SideBar->objectName().isEmpty())
            SideBar->setObjectName(QString::fromUtf8("SideBar"));
        SideBar->resize(36, 153);
        verticalLayout = new QVBoxLayout(SideBar);
        verticalLayout->setSpacing(0);
        verticalLayout->setObjectName(QString::fromUtf8("verticalLayout"));
        verticalLayout->setContentsMargins(0, 0, 0, 0);
        closeButton = new QPushButton(SideBar);
        closeButton->setObjectName(QString::fromUtf8("closeButton"));
        QSizePolicy sizePolicy(QSizePolicy::Expanding, QSizePolicy::Expanding);
        sizePolicy.setHorizontalStretch(0);
        sizePolicy.setVerticalStretch(0);
        sizePolicy.setHeightForWidth(closeButton->sizePolicy().hasHeightForWidth());
        closeButton->setSizePolicy(sizePolicy);
        QIcon icon;
        icon.addFile(QString::fromUtf8(":/resources/fluentStyle/buttons/close.svg"), QSize(), QIcon::Normal, QIcon::Off);
        closeButton->setIcon(icon);
        closeButton->setIconSize(QSize(24, 24));
        closeButton->setFlat(true);

        verticalLayout->addWidget(closeButton);

        verticalSpacer_2 = new QSpacerItem(20, 40, QSizePolicy::Minimum, QSizePolicy::Expanding);

        verticalLayout->addItem(verticalSpacer_2);

        aboutButton = new QPushButton(SideBar);
        aboutButton->setObjectName(QString::fromUtf8("aboutButton"));
        QIcon icon1;
        icon1.addFile(QString::fromUtf8(":/resources/fluentStyle/buttons/about.svg"), QSize(), QIcon::Normal, QIcon::Off);
        aboutButton->setIcon(icon1);
        aboutButton->setIconSize(QSize(24, 24));
        aboutButton->setFlat(true);

        verticalLayout->addWidget(aboutButton);

        verticalSpacer = new QSpacerItem(20, 40, QSizePolicy::Minimum, QSizePolicy::Expanding);

        verticalLayout->addItem(verticalSpacer);

        settingsButton = new QPushButton(SideBar);
        settingsButton->setObjectName(QString::fromUtf8("settingsButton"));
        sizePolicy.setHeightForWidth(settingsButton->sizePolicy().hasHeightForWidth());
        settingsButton->setSizePolicy(sizePolicy);
        QIcon icon2;
        icon2.addFile(QString::fromUtf8(":/resources/fluentStyle/buttons/settings.svg"), QSize(), QIcon::Normal, QIcon::Off);
        settingsButton->setIcon(icon2);
        settingsButton->setIconSize(QSize(24, 24));
        settingsButton->setFlat(true);

        verticalLayout->addWidget(settingsButton);


        retranslateUi(SideBar);

        QMetaObject::connectSlotsByName(SideBar);
    } // setupUi

    void retranslateUi(QWidget *SideBar)
    {
        SideBar->setWindowTitle(QString());
        closeButton->setText(QString());
        aboutButton->setText(QString());
        settingsButton->setText(QString());
    } // retranslateUi

};

namespace Ui {
    class SideBar: public Ui_SideBar {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_SIDEBAR_H
