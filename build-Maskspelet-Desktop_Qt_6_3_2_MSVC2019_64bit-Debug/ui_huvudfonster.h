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
#include <QtWidgets/QGridLayout>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QMenuBar>
#include <QtWidgets/QStatusBar>
#include <QtWidgets/QWidget>
#include "spelplan.h"

QT_BEGIN_NAMESPACE

class Ui_Huvudfonster
{
public:
    QWidget *m_pCentralwidget;
    QGridLayout *gridLayout;
    Spelplan *m_pSpelplan;
    QMenuBar *m_pMenubar;
    QStatusBar *m_pStatusbar;

    void setupUi(QMainWindow *Huvudfonster)
    {
        if (Huvudfonster->objectName().isEmpty())
            Huvudfonster->setObjectName(QString::fromUtf8("Huvudfonster"));
        Huvudfonster->resize(800, 600);
        m_pCentralwidget = new QWidget(Huvudfonster);
        m_pCentralwidget->setObjectName(QString::fromUtf8("m_pCentralwidget"));
        gridLayout = new QGridLayout(m_pCentralwidget);
        gridLayout->setObjectName(QString::fromUtf8("gridLayout"));
        m_pSpelplan = new Spelplan(m_pCentralwidget);
        m_pSpelplan->setObjectName(QString::fromUtf8("m_pSpelplan"));

        gridLayout->addWidget(m_pSpelplan, 0, 0, 1, 1);

        Huvudfonster->setCentralWidget(m_pCentralwidget);
        m_pMenubar = new QMenuBar(Huvudfonster);
        m_pMenubar->setObjectName(QString::fromUtf8("m_pMenubar"));
        m_pMenubar->setGeometry(QRect(0, 0, 800, 22));
        Huvudfonster->setMenuBar(m_pMenubar);
        m_pStatusbar = new QStatusBar(Huvudfonster);
        m_pStatusbar->setObjectName(QString::fromUtf8("m_pStatusbar"));
        Huvudfonster->setStatusBar(m_pStatusbar);

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
