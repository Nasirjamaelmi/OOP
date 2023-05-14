/********************************************************************************
** Form generated from reading UI file 'huvudfonster.ui'
**
** Created by: Qt User Interface Compiler version 6.3.2
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_HUVUDFONSTER_H
#define UI_HUVUDFONSTER_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QMenuBar>
#include <QtWidgets/QStatusBar>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_Huvudfonster
{
public:
    QWidget *centralwidget;
    QMenuBar *menubar;
    QStatusBar *statusbar;

    void setupUi(QMainWindow *Huvudfonster)
    {
        if (Huvudfonster->objectName().isEmpty())
            Huvudfonster->setObjectName(QString::fromUtf8("Huvudfonster"));
        Huvudfonster->resize(800, 600);
        centralwidget = new QWidget(Huvudfonster);
        centralwidget->setObjectName(QString::fromUtf8("centralwidget"));
        Huvudfonster->setCentralWidget(centralwidget);
        menubar = new QMenuBar(Huvudfonster);
        menubar->setObjectName(QString::fromUtf8("menubar"));
        Huvudfonster->setMenuBar(menubar);
        statusbar = new QStatusBar(Huvudfonster);
        statusbar->setObjectName(QString::fromUtf8("statusbar"));
        Huvudfonster->setStatusBar(statusbar);

        retranslateUi(Huvudfonster);

        QMetaObject::connectSlotsByName(Huvudfonster);
    } // setupUi

    void retranslateUi(QMainWindow *Huvudfonster)
    {
        Huvudfonster->setWindowTitle(QCoreApplication::translate("Huvudfonster", "Huvudfonster", nullptr));
    } // retranslateUi

};

namespace Ui {
    class Huvudfonster: public Ui_Huvudfonster {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_HUVUDFONSTER_H
