/********************************************************************************
** Form generated from reading UI file 'mainwindow.ui'
**
** Created by: Qt User Interface Compiler version 5.12.9
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_MAINWINDOW_H
#define UI_MAINWINDOW_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QGraphicsView>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QMenuBar>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QRadioButton>
#include <QtWidgets/QStatusBar>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_MainWindow
{
public:
    QWidget *centralwidget;
    QGraphicsView *graphicsView;
    QPushButton *bottonJugar;
    QPushButton *bottonInstrucciones;
    QPushButton *bottonMultijugador;
    QPushButton *bottonUsuario;
    QRadioButton *radioButton;
    QRadioButton *radioButton_2;
    QMenuBar *menubar;
    QStatusBar *statusbar;

    void setupUi(QMainWindow *MainWindow)
    {
        if (MainWindow->objectName().isEmpty())
            MainWindow->setObjectName(QString::fromUtf8("MainWindow"));
        MainWindow->resize(960, 519);
        MainWindow->setMinimumSize(QSize(960, 519));
        MainWindow->setMaximumSize(QSize(960, 519));
        MainWindow->setStyleSheet(QString::fromUtf8(""));
        centralwidget = new QWidget(MainWindow);
        centralwidget->setObjectName(QString::fromUtf8("centralwidget"));
        centralwidget->setMaximumSize(QSize(960, 519));
        graphicsView = new QGraphicsView(centralwidget);
        graphicsView->setObjectName(QString::fromUtf8("graphicsView"));
        graphicsView->setGeometry(QRect(0, 0, 960, 519));
        graphicsView->setMaximumSize(QSize(960, 519));
        graphicsView->setStyleSheet(QString::fromUtf8("background-image: url(:/Imagenes/FondoMenu.png);"));
        graphicsView->setVerticalScrollBarPolicy(Qt::ScrollBarAlwaysOff);
        graphicsView->setHorizontalScrollBarPolicy(Qt::ScrollBarAlwaysOff);
        bottonJugar = new QPushButton(centralwidget);
        bottonJugar->setObjectName(QString::fromUtf8("bottonJugar"));
        bottonJugar->setGeometry(QRect(150, 220, 121, 61));
        bottonJugar->setStyleSheet(QString::fromUtf8("background-image: url(:/Imagenes/JugarRickMorty.png);"));
        bottonInstrucciones = new QPushButton(centralwidget);
        bottonInstrucciones->setObjectName(QString::fromUtf8("bottonInstrucciones"));
        bottonInstrucciones->setGeometry(QRect(290, 220, 201, 61));
        bottonInstrucciones->setStyleSheet(QString::fromUtf8("background-image: url(:/Imagenes/Instrucciones.png);\n"
""));
        bottonMultijugador = new QPushButton(centralwidget);
        bottonMultijugador->setObjectName(QString::fromUtf8("bottonMultijugador"));
        bottonMultijugador->setGeometry(QRect(500, 220, 191, 61));
        bottonMultijugador->setMaximumSize(QSize(16777215, 61));
        bottonMultijugador->setStyleSheet(QString::fromUtf8("background-image: url(:/Imagenes/Multijugador.png);"));
        bottonUsuario = new QPushButton(centralwidget);
        bottonUsuario->setObjectName(QString::fromUtf8("bottonUsuario"));
        bottonUsuario->setGeometry(QRect(710, 220, 140, 61));
        bottonUsuario->setMaximumSize(QSize(140, 61));
        bottonUsuario->setStyleSheet(QString::fromUtf8("background-image: url(:/Imagenes/Usuario.png);"));
        radioButton = new QRadioButton(centralwidget);
        radioButton->setObjectName(QString::fromUtf8("radioButton"));
        radioButton->setGeometry(QRect(280, 290, 51, 61));
        radioButton->setStyleSheet(QString::fromUtf8("background-image: url(:/Imagenes/IconMorty.png);"));
        radioButton_2 = new QRadioButton(centralwidget);
        radioButton_2->setObjectName(QString::fromUtf8("radioButton_2"));
        radioButton_2->setGeometry(QRect(200, 290, 51, 61));
        radioButton_2->setStyleSheet(QString::fromUtf8("background-image: url(:/Imagenes/IconRick.png);"));
        MainWindow->setCentralWidget(centralwidget);
        menubar = new QMenuBar(MainWindow);
        menubar->setObjectName(QString::fromUtf8("menubar"));
        menubar->setGeometry(QRect(0, 0, 960, 21));
        MainWindow->setMenuBar(menubar);
        statusbar = new QStatusBar(MainWindow);
        statusbar->setObjectName(QString::fromUtf8("statusbar"));
        statusbar->setMaximumSize(QSize(960, 519));
        MainWindow->setStatusBar(statusbar);

        retranslateUi(MainWindow);

        QMetaObject::connectSlotsByName(MainWindow);
    } // setupUi

    void retranslateUi(QMainWindow *MainWindow)
    {
        MainWindow->setWindowTitle(QApplication::translate("MainWindow", "MainWindow", nullptr));
        bottonJugar->setText(QString());
        bottonInstrucciones->setText(QString());
        bottonMultijugador->setText(QString());
        bottonUsuario->setText(QString());
        radioButton->setText(QString());
        radioButton_2->setText(QString());
    } // retranslateUi

};

namespace Ui {
    class MainWindow: public Ui_MainWindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MAINWINDOW_H
