/********************************************************************************
** Form generated from reading UI file 'mainwindow.ui'
**
** Created by: Qt User Interface Compiler version 5.15.2
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_MAINWINDOW_H
#define UI_MAINWINDOW_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QGraphicsView>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QMenu>
#include <QtWidgets/QMenuBar>
#include <QtWidgets/QStatusBar>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_MainWindow
{
public:
    QAction *actionNowa_gra;
    QAction *actioncofnij;
    QAction *actionprzejd;
    QAction *actionZako_cz;
    QWidget *centralwidget;
    QHBoxLayout *horizontalLayout;
    QGraphicsView *graphicsView;
    QMenuBar *menubar;
    QMenu *menu_Gra;
    QMenu *menuEdycja;
    QStatusBar *statusbar;

    void setupUi(QMainWindow *MainWindow)
    {
        if (MainWindow->objectName().isEmpty())
            MainWindow->setObjectName(QString::fromUtf8("MainWindow"));
        MainWindow->resize(800, 600);
        actionNowa_gra = new QAction(MainWindow);
        actionNowa_gra->setObjectName(QString::fromUtf8("actionNowa_gra"));
        actioncofnij = new QAction(MainWindow);
        actioncofnij->setObjectName(QString::fromUtf8("actioncofnij"));
        actionprzejd = new QAction(MainWindow);
        actionprzejd->setObjectName(QString::fromUtf8("actionprzejd"));
        actionZako_cz = new QAction(MainWindow);
        actionZako_cz->setObjectName(QString::fromUtf8("actionZako_cz"));
        centralwidget = new QWidget(MainWindow);
        centralwidget->setObjectName(QString::fromUtf8("centralwidget"));
        horizontalLayout = new QHBoxLayout(centralwidget);
        horizontalLayout->setObjectName(QString::fromUtf8("horizontalLayout"));
        graphicsView = new QGraphicsView(centralwidget);
        graphicsView->setObjectName(QString::fromUtf8("graphicsView"));

        horizontalLayout->addWidget(graphicsView);

        MainWindow->setCentralWidget(centralwidget);
        menubar = new QMenuBar(MainWindow);
        menubar->setObjectName(QString::fromUtf8("menubar"));
        menubar->setGeometry(QRect(0, 0, 800, 21));
        menu_Gra = new QMenu(menubar);
        menu_Gra->setObjectName(QString::fromUtf8("menu_Gra"));
        menuEdycja = new QMenu(menubar);
        menuEdycja->setObjectName(QString::fromUtf8("menuEdycja"));
        MainWindow->setMenuBar(menubar);
        statusbar = new QStatusBar(MainWindow);
        statusbar->setObjectName(QString::fromUtf8("statusbar"));
        MainWindow->setStatusBar(statusbar);

        menubar->addAction(menu_Gra->menuAction());
        menubar->addAction(menuEdycja->menuAction());
        menu_Gra->addAction(actionNowa_gra);
        menu_Gra->addSeparator();
        menu_Gra->addAction(actionZako_cz);
        menuEdycja->addAction(actioncofnij);
        menuEdycja->addAction(actionprzejd);

        retranslateUi(MainWindow);

        QMetaObject::connectSlotsByName(MainWindow);
    } // setupUi

    void retranslateUi(QMainWindow *MainWindow)
    {
        MainWindow->setWindowTitle(QCoreApplication::translate("MainWindow", "MainWindow", nullptr));
        actionNowa_gra->setText(QCoreApplication::translate("MainWindow", "Nowa gra", nullptr));
        actioncofnij->setText(QCoreApplication::translate("MainWindow", "Cofnij", nullptr));
        actionprzejd->setText(QCoreApplication::translate("MainWindow", "Przejd\305\272", nullptr));
        actionZako_cz->setText(QCoreApplication::translate("MainWindow", "Zako\305\204cz", nullptr));
        menu_Gra->setTitle(QCoreApplication::translate("MainWindow", "&Gra", nullptr));
        menuEdycja->setTitle(QCoreApplication::translate("MainWindow", "Edycja", nullptr));
    } // retranslateUi

};

namespace Ui {
    class MainWindow: public Ui_MainWindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MAINWINDOW_H
