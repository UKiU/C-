/********************************************************************************
** Form generated from reading UI file 'Data.ui'
**
** Created by: Qt User Interface Compiler version 4.8.6
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_DATA_H
#define UI_DATA_H

#include <QtCore/QVariant>
#include <QtGui/QAction>
#include <QtGui/QApplication>
#include <QtGui/QButtonGroup>
#include <QtGui/QHBoxLayout>
#include <QtGui/QHeaderView>
#include <QtGui/QPushButton>
#include <QtGui/QSpacerItem>
#include <QtGui/QVBoxLayout>
#include <QtGui/QWidget>
#include "Paintpic.h"

QT_BEGIN_NAMESPACE

class Ui_Data
{
public:
    QVBoxLayout *verticalLayout;
    QHBoxLayout *horizontalLayout;
    QSpacerItem *horizontalSpacer;
    QPushButton *Restart;
    QSpacerItem *horizontalSpacer_2;
    Paintpic *frame;

    void setupUi(QWidget *Data)
    {
        if (Data->objectName().isEmpty())
            Data->setObjectName(QString::fromUtf8("Data"));
        Data->resize(400, 300);
        verticalLayout = new QVBoxLayout(Data);
        verticalLayout->setSpacing(6);
        verticalLayout->setContentsMargins(11, 11, 11, 11);
        verticalLayout->setObjectName(QString::fromUtf8("verticalLayout"));
        horizontalLayout = new QHBoxLayout();
        horizontalLayout->setSpacing(6);
        horizontalLayout->setObjectName(QString::fromUtf8("horizontalLayout"));
        horizontalSpacer = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout->addItem(horizontalSpacer);

        Restart = new QPushButton(Data);
        Restart->setObjectName(QString::fromUtf8("Restart"));

        horizontalLayout->addWidget(Restart);

        horizontalSpacer_2 = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout->addItem(horizontalSpacer_2);


        verticalLayout->addLayout(horizontalLayout);

        frame = new Paintpic(Data);
        frame->setObjectName(QString::fromUtf8("frame"));
        frame->setFrameShape(QFrame::StyledPanel);
        frame->setFrameShadow(QFrame::Raised);

        verticalLayout->addWidget(frame);


        retranslateUi(Data);

        QMetaObject::connectSlotsByName(Data);
    } // setupUi

    void retranslateUi(QWidget *Data)
    {
        Data->setWindowTitle(QApplication::translate("Data", "Data", 0, QApplication::UnicodeUTF8));
        Restart->setText(QApplication::translate("Data", "\351\207\215\346\226\260\345\274\200\345\247\213", 0, QApplication::UnicodeUTF8));
    } // retranslateUi

};

namespace Ui {
    class Data: public Ui_Data {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_DATA_H
