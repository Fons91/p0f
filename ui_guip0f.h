/********************************************************************************
** Form generated from reading UI file 'guip0f.ui'
**
** Created: Mon Jul 8 14:45:45 2013
**      by: Qt User Interface Compiler version 4.8.1
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_GUIP0F_H
#define UI_GUIP0F_H

#include <QtCore/QVariant>
#include <QtGui/QAction>
#include <QtGui/QApplication>
#include <QtGui/QButtonGroup>
#include <QtGui/QComboBox>
#include <QtGui/QHeaderView>
#include <QtGui/QMainWindow>
#include <QtGui/QPushButton>
#include <QtGui/QStatusBar>
#include <QtGui/QToolBar>
#include <QtGui/QWidget>
#include <QNetworkInterface>

QT_BEGIN_NAMESPACE

class Ui_GUIp0f
{
public:
    QWidget *centralWidget;
    QPushButton *pushButton;
    QComboBox *list_interface;
    QToolBar *mainToolBar;
    QStatusBar *statusBar;

    void setupUi(QMainWindow *GUIp0f)
    {
        if (GUIp0f->objectName().isEmpty())
            GUIp0f->setObjectName(QString::fromUtf8("GUIp0f"));
        GUIp0f->resize(400, 300);
        centralWidget = new QWidget(GUIp0f);
        centralWidget->setObjectName(QString::fromUtf8("centralWidget"));
        pushButton = new QPushButton(centralWidget);
        pushButton->setObjectName(QString::fromUtf8("pushButton"));
        pushButton->setGeometry(QRect(150, 190, 80, 26));
        list_interface = new QComboBox(centralWidget);
        list_interface->setObjectName(QString::fromUtf8("list_interface"));
        list_interface->setGeometry(QRect(150, 110, 78, 24));
        GUIp0f->setCentralWidget(centralWidget);
        mainToolBar = new QToolBar(GUIp0f);
        mainToolBar->setObjectName(QString::fromUtf8("mainToolBar"));
        GUIp0f->addToolBar(Qt::TopToolBarArea, mainToolBar);
        statusBar = new QStatusBar(GUIp0f);
        statusBar->setObjectName(QString::fromUtf8("statusBar"));
        GUIp0f->setStatusBar(statusBar);
        create_list();
        retranslateUi(GUIp0f);
        QObject::connect(pushButton, SIGNAL(clicked()), GUIp0f, SLOT(set_name_interface()));

        QMetaObject::connectSlotsByName(GUIp0f);
    } // setupUi

    void create_list(){
        QNetworkInterface* network = new QNetworkInterface();
        foreach(QNetworkInterface interface,network->allInterfaces())
            list_interface->addItem(interface.humanReadableName());
     }

    void retranslateUi(QMainWindow *GUIp0f)
    {
        GUIp0f->setWindowTitle(QApplication::translate("GUIp0f", "GUIp0f", 0, QApplication::UnicodeUTF8));
        pushButton->setText(QApplication::translate("GUIp0f", "PushButton", 0, QApplication::UnicodeUTF8));
    } // retranslateUi

};

namespace Ui {
    class GUIp0f: public Ui_GUIp0f {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_GUIP0F_H
