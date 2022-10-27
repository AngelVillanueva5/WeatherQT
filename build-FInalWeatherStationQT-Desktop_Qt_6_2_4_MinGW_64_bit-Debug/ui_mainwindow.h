/********************************************************************************
** Form generated from reading UI file 'mainwindow.ui'
**
** Created by: Qt User Interface Compiler version 6.2.4
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_MAINWINDOW_H
#define UI_MAINWINDOW_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QGridLayout>
#include <QtWidgets/QLabel>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QMenuBar>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QStatusBar>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_MainWindow
{
public:
    QWidget *centralwidget;
    QWidget *gridLayoutWidget;
    QGridLayout *gridLayout_2;
    QLabel *lblTemp;
    QLabel *lblAir;
    QLabel *lblHum;
    QLabel *label_4;
    QLabel *label_5;
    QLabel *label_6;
    QLabel *lblAvgTemp;
    QPushButton *btnStart;
    QLabel *lblAvgHum;
    QLabel *lblAvgPres;
    QMenuBar *menubar;
    QStatusBar *statusbar;

    void setupUi(QMainWindow *MainWindow)
    {
        if (MainWindow->objectName().isEmpty())
            MainWindow->setObjectName(QString::fromUtf8("MainWindow"));
        MainWindow->resize(800, 600);
        centralwidget = new QWidget(MainWindow);
        centralwidget->setObjectName(QString::fromUtf8("centralwidget"));
        gridLayoutWidget = new QWidget(centralwidget);
        gridLayoutWidget->setObjectName(QString::fromUtf8("gridLayoutWidget"));
        gridLayoutWidget->setGeometry(QRect(70, 350, 191, 181));
        gridLayout_2 = new QGridLayout(gridLayoutWidget);
        gridLayout_2->setObjectName(QString::fromUtf8("gridLayout_2"));
        gridLayout_2->setContentsMargins(0, 0, 0, 0);
        lblTemp = new QLabel(gridLayoutWidget);
        lblTemp->setObjectName(QString::fromUtf8("lblTemp"));

        gridLayout_2->addWidget(lblTemp, 1, 0, 1, 1);

        lblAir = new QLabel(gridLayoutWidget);
        lblAir->setObjectName(QString::fromUtf8("lblAir"));

        gridLayout_2->addWidget(lblAir, 1, 2, 1, 1);

        lblHum = new QLabel(gridLayoutWidget);
        lblHum->setObjectName(QString::fromUtf8("lblHum"));

        gridLayout_2->addWidget(lblHum, 1, 1, 1, 1);

        label_4 = new QLabel(gridLayoutWidget);
        label_4->setObjectName(QString::fromUtf8("label_4"));

        gridLayout_2->addWidget(label_4, 0, 0, 1, 1);

        label_5 = new QLabel(gridLayoutWidget);
        label_5->setObjectName(QString::fromUtf8("label_5"));

        gridLayout_2->addWidget(label_5, 0, 1, 1, 1);

        label_6 = new QLabel(gridLayoutWidget);
        label_6->setObjectName(QString::fromUtf8("label_6"));

        gridLayout_2->addWidget(label_6, 0, 2, 1, 1);

        lblAvgTemp = new QLabel(centralwidget);
        lblAvgTemp->setObjectName(QString::fromUtf8("lblAvgTemp"));
        lblAvgTemp->setGeometry(QRect(320, 250, 49, 16));
        btnStart = new QPushButton(centralwidget);
        btnStart->setObjectName(QString::fromUtf8("btnStart"));
        btnStart->setGeometry(QRect(450, 400, 80, 24));
        lblAvgHum = new QLabel(centralwidget);
        lblAvgHum->setObjectName(QString::fromUtf8("lblAvgHum"));
        lblAvgHum->setGeometry(QRect(490, 240, 49, 16));
        lblAvgPres = new QLabel(centralwidget);
        lblAvgPres->setObjectName(QString::fromUtf8("lblAvgPres"));
        lblAvgPres->setGeometry(QRect(650, 260, 49, 16));
        MainWindow->setCentralWidget(centralwidget);
        menubar = new QMenuBar(MainWindow);
        menubar->setObjectName(QString::fromUtf8("menubar"));
        menubar->setGeometry(QRect(0, 0, 800, 21));
        MainWindow->setMenuBar(menubar);
        statusbar = new QStatusBar(MainWindow);
        statusbar->setObjectName(QString::fromUtf8("statusbar"));
        MainWindow->setStatusBar(statusbar);

        retranslateUi(MainWindow);

        QMetaObject::connectSlotsByName(MainWindow);
    } // setupUi

    void retranslateUi(QMainWindow *MainWindow)
    {
        MainWindow->setWindowTitle(QCoreApplication::translate("MainWindow", "MainWindow", nullptr));
        lblTemp->setText(QCoreApplication::translate("MainWindow", "TextLabel", nullptr));
        lblAir->setText(QCoreApplication::translate("MainWindow", "TextLabel", nullptr));
        lblHum->setText(QCoreApplication::translate("MainWindow", "TextLabel", nullptr));
        label_4->setText(QCoreApplication::translate("MainWindow", "Temperature", nullptr));
        label_5->setText(QCoreApplication::translate("MainWindow", "Humidity", nullptr));
        label_6->setText(QCoreApplication::translate("MainWindow", "Airpressure", nullptr));
        lblAvgTemp->setText(QCoreApplication::translate("MainWindow", "TextLabel", nullptr));
        btnStart->setText(QCoreApplication::translate("MainWindow", "PushButton", nullptr));
        lblAvgHum->setText(QCoreApplication::translate("MainWindow", "TextLabel", nullptr));
        lblAvgPres->setText(QCoreApplication::translate("MainWindow", "TextLabel", nullptr));
    } // retranslateUi

};

namespace Ui {
    class MainWindow: public Ui_MainWindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MAINWINDOW_H
