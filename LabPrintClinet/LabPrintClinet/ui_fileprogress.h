/********************************************************************************
** Form generated from reading UI file 'fileprogress.ui'
**
** Created by: Qt User Interface Compiler version 5.14.2
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_FILEPROGRESS_H
#define UI_FILEPROGRESS_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QGridLayout>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QLabel>
#include <QtWidgets/QProgressBar>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_FileProgress
{
public:
    QGridLayout *gridLayout;
    QHBoxLayout *horizontalLayout;
    QLabel *fillename;
    QProgressBar *progressBar;
    QPushButton *pushButton;

    void setupUi(QWidget *FileProgress)
    {
        if (FileProgress->objectName().isEmpty())
            FileProgress->setObjectName(QString::fromUtf8("FileProgress"));
        FileProgress->resize(540, 25);
        gridLayout = new QGridLayout(FileProgress);
        gridLayout->setObjectName(QString::fromUtf8("gridLayout"));
        gridLayout->setHorizontalSpacing(0);
        gridLayout->setVerticalSpacing(10);
        gridLayout->setContentsMargins(0, 0, 0, 0);
        horizontalLayout = new QHBoxLayout();
        horizontalLayout->setObjectName(QString::fromUtf8("horizontalLayout"));
        fillename = new QLabel(FileProgress);
        fillename->setObjectName(QString::fromUtf8("fillename"));
        fillename->setMinimumSize(QSize(100, 20));
        fillename->setMaximumSize(QSize(100, 20));

        horizontalLayout->addWidget(fillename);

        progressBar = new QProgressBar(FileProgress);
        progressBar->setObjectName(QString::fromUtf8("progressBar"));
        progressBar->setValue(0);

        horizontalLayout->addWidget(progressBar);

        pushButton = new QPushButton(FileProgress);
        pushButton->setObjectName(QString::fromUtf8("pushButton"));

        horizontalLayout->addWidget(pushButton);


        gridLayout->addLayout(horizontalLayout, 0, 1, 1, 1);


        retranslateUi(FileProgress);

        QMetaObject::connectSlotsByName(FileProgress);
    } // setupUi

    void retranslateUi(QWidget *FileProgress)
    {
        FileProgress->setWindowTitle(QCoreApplication::translate("FileProgress", "Form", nullptr));
        fillename->setText(QCoreApplication::translate("FileProgress", "\346\226\207\344\273\266", nullptr));
        pushButton->setText(QCoreApplication::translate("FileProgress", "\345\210\240\351\231\244", nullptr));
    } // retranslateUi

};

namespace Ui {
    class FileProgress: public Ui_FileProgress {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_FILEPROGRESS_H
