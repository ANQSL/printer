/********************************************************************************
** Form generated from reading UI file 'widget.ui'
**
** Created by: Qt User Interface Compiler version 5.14.2
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_WIDGET_H
#define UI_WIDGET_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QGridLayout>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QLabel>
#include <QtWidgets/QListWidget>
#include <QtWidgets/QProgressBar>
#include <QtWidgets/QToolButton>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_Widget
{
public:
    QGridLayout *gridLayout;
    QHBoxLayout *horizontalLayout;
    QLabel *user_name;
    QProgressBar *print_Progress;
    QLabel *print_page;
    QToolButton *print_btn;
    QListWidget *print_user;

    void setupUi(QWidget *Widget)
    {
        if (Widget->objectName().isEmpty())
            Widget->setObjectName(QString::fromUtf8("Widget"));
        Widget->resize(464, 341);
        gridLayout = new QGridLayout(Widget);
        gridLayout->setObjectName(QString::fromUtf8("gridLayout"));
        horizontalLayout = new QHBoxLayout();
        horizontalLayout->setObjectName(QString::fromUtf8("horizontalLayout"));
        user_name = new QLabel(Widget);
        user_name->setObjectName(QString::fromUtf8("user_name"));

        horizontalLayout->addWidget(user_name);

        print_Progress = new QProgressBar(Widget);
        print_Progress->setObjectName(QString::fromUtf8("print_Progress"));
        print_Progress->setValue(0);

        horizontalLayout->addWidget(print_Progress);

        print_page = new QLabel(Widget);
        print_page->setObjectName(QString::fromUtf8("print_page"));

        horizontalLayout->addWidget(print_page);

        print_btn = new QToolButton(Widget);
        print_btn->setObjectName(QString::fromUtf8("print_btn"));

        horizontalLayout->addWidget(print_btn);


        gridLayout->addLayout(horizontalLayout, 0, 0, 1, 1);

        print_user = new QListWidget(Widget);
        print_user->setObjectName(QString::fromUtf8("print_user"));

        gridLayout->addWidget(print_user, 1, 0, 1, 1);


        retranslateUi(Widget);

        QMetaObject::connectSlotsByName(Widget);
    } // setupUi

    void retranslateUi(QWidget *Widget)
    {
        Widget->setWindowTitle(QCoreApplication::translate("Widget", "Widget", nullptr));
        user_name->setText(QCoreApplication::translate("Widget", "TextLabel", nullptr));
        print_page->setText(QCoreApplication::translate("Widget", "0/0", nullptr));
        print_btn->setText(QCoreApplication::translate("Widget", "...", nullptr));
    } // retranslateUi

};

namespace Ui {
    class Widget: public Ui_Widget {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_WIDGET_H
