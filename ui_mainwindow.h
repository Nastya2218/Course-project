/********************************************************************************
** Form generated from reading UI file 'mainwindow.ui'
**
** Created by: Qt User Interface Compiler version 5.14.2
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_MAINWINDOW_H
#define UI_MAINWINDOW_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QMenuBar>
#include <QtWidgets/QStatusBar>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_heightInput
{
public:
    QWidget *centralwidget;
    QMenuBar *menubar;
    QStatusBar *statusbar;

    void setupUi(QMainWindow *heightInput)
    {
        if (heightInput->objectName().isEmpty())
            heightInput->setObjectName(QString::fromUtf8("heightInput"));
        heightInput->resize(800, 600);
        centralwidget = new QWidget(heightInput);
        centralwidget->setObjectName(QString::fromUtf8("centralwidget"));
        heightInput->setCentralWidget(centralwidget);
        menubar = new QMenuBar(heightInput);
        menubar->setObjectName(QString::fromUtf8("menubar"));
        menubar->setGeometry(QRect(0, 0, 800, 21));
        heightInput->setMenuBar(menubar);
        statusbar = new QStatusBar(heightInput);
        statusbar->setObjectName(QString::fromUtf8("statusbar"));
        heightInput->setStatusBar(statusbar);

        retranslateUi(heightInput);

        QMetaObject::connectSlotsByName(heightInput);
    } // setupUi

    void retranslateUi(QMainWindow *heightInput)
    {
        heightInput->setWindowTitle(QCoreApplication::translate("heightInput", "MainWindow", nullptr));
    } // retranslateUi

};

namespace Ui {
    class heightInput: public Ui_heightInput {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MAINWINDOW_H
