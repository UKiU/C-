/********************************************************************************
** Form generated from reading UI file 'test2.ui'
**
** Created by: Qt User Interface Compiler version 4.8.6
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_TEST2_H
#define UI_TEST2_H

#include <QtCore/QVariant>
#include <QtGui/QAction>
#include <QtGui/QApplication>
#include <QtGui/QButtonGroup>
#include <QtGui/QHBoxLayout>
#include <QtGui/QHeaderView>
#include <QtGui/QMainWindow>
#include <QtGui/QMenuBar>
#include <QtGui/QPushButton>
#include <QtGui/QSpacerItem>
#include <QtGui/QStatusBar>
#include <QtGui/QTextEdit>
#include <QtGui/QToolBar>
#include <QtGui/QVBoxLayout>
#include <QtGui/QWidget>

QT_BEGIN_NAMESPACE

class Ui_test2Class
{
public:
    QWidget *centralWidget;
    QHBoxLayout *horizontalLayout_2;
    QVBoxLayout *verticalLayout;
    QHBoxLayout *horizontalLayout;
    QPushButton *btntest1;
    QSpacerItem *horizontalSpacer;
    QTextEdit *texttest1;
    QMenuBar *menuBar;
    QToolBar *mainToolBar;
    QStatusBar *statusBar;

    void setupUi(QMainWindow *test2Class)
    {
        if (test2Class->objectName().isEmpty())
            test2Class->setObjectName(QString::fromUtf8("test2Class"));
        test2Class->resize(445, 400);
        centralWidget = new QWidget(test2Class);
        centralWidget->setObjectName(QString::fromUtf8("centralWidget"));
        horizontalLayout_2 = new QHBoxLayout(centralWidget);
        horizontalLayout_2->setSpacing(6);
        horizontalLayout_2->setContentsMargins(11, 11, 11, 11);
        horizontalLayout_2->setObjectName(QString::fromUtf8("horizontalLayout_2"));
        verticalLayout = new QVBoxLayout();
        verticalLayout->setSpacing(6);
        verticalLayout->setObjectName(QString::fromUtf8("verticalLayout"));
        horizontalLayout = new QHBoxLayout();
        horizontalLayout->setSpacing(6);
        horizontalLayout->setObjectName(QString::fromUtf8("horizontalLayout"));
        btntest1 = new QPushButton(centralWidget);
        btntest1->setObjectName(QString::fromUtf8("btntest1"));

        horizontalLayout->addWidget(btntest1);

        horizontalSpacer = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout->addItem(horizontalSpacer);


        verticalLayout->addLayout(horizontalLayout);

        texttest1 = new QTextEdit(centralWidget);
        texttest1->setObjectName(QString::fromUtf8("texttest1"));

        verticalLayout->addWidget(texttest1);


        horizontalLayout_2->addLayout(verticalLayout);

        test2Class->setCentralWidget(centralWidget);
        menuBar = new QMenuBar(test2Class);
        menuBar->setObjectName(QString::fromUtf8("menuBar"));
        menuBar->setGeometry(QRect(0, 0, 445, 26));
        test2Class->setMenuBar(menuBar);
        mainToolBar = new QToolBar(test2Class);
        mainToolBar->setObjectName(QString::fromUtf8("mainToolBar"));
        test2Class->addToolBar(Qt::TopToolBarArea, mainToolBar);
        statusBar = new QStatusBar(test2Class);
        statusBar->setObjectName(QString::fromUtf8("statusBar"));
        test2Class->setStatusBar(statusBar);

        retranslateUi(test2Class);

        QMetaObject::connectSlotsByName(test2Class);
    } // setupUi

    void retranslateUi(QMainWindow *test2Class)
    {
        test2Class->setWindowTitle(QApplication::translate("test2Class", "test2", 0, QApplication::UnicodeUTF8));
        btntest1->setText(QApplication::translate("test2Class", "\346\265\213\350\257\225", 0, QApplication::UnicodeUTF8));
    } // retranslateUi

};

namespace Ui {
    class test2Class: public Ui_test2Class {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_TEST2_H
