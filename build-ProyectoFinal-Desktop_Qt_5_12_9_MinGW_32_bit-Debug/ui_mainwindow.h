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
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
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
    QRadioButton *radioButton;
    QRadioButton *radioButton_2;
    QLabel *label;
    QLabel *label_2;
    QPushButton *pushButton;
    QLabel *label_3;
    QPushButton *bottonUsurario;
    QLineEdit *lineEdit;
    QPushButton *bottonReiniciar;
    QPushButton *pushButton_2;
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
        graphicsView->setEnabled(true);
        graphicsView->setGeometry(QRect(0, 0, 960, 519));
        graphicsView->setMaximumSize(QSize(960, 519));
        graphicsView->setStyleSheet(QString::fromUtf8("background-image: url(:/Imagenes/FondoMenu.png);"));
        graphicsView->setVerticalScrollBarPolicy(Qt::ScrollBarAlwaysOff);
        graphicsView->setHorizontalScrollBarPolicy(Qt::ScrollBarAlwaysOff);
        bottonJugar = new QPushButton(centralwidget);
        bottonJugar->setObjectName(QString::fromUtf8("bottonJugar"));
        bottonJugar->setGeometry(QRect(290, 230, 121, 61));
        bottonJugar->setStyleSheet(QString::fromUtf8("background-image: url(:/Imagenes/JugarRickMorty.png);"));
        bottonInstrucciones = new QPushButton(centralwidget);
        bottonInstrucciones->setObjectName(QString::fromUtf8("bottonInstrucciones"));
        bottonInstrucciones->setGeometry(QRect(440, 230, 201, 61));
        bottonInstrucciones->setStyleSheet(QString::fromUtf8("background-image: url(:/Imagenes/Instrucciones.png);\n"
""));
        bottonMultijugador = new QPushButton(centralwidget);
        bottonMultijugador->setObjectName(QString::fromUtf8("bottonMultijugador"));
        bottonMultijugador->setGeometry(QRect(190, 230, 191, 61));
        bottonMultijugador->setMaximumSize(QSize(16777215, 61));
        bottonMultijugador->setStyleSheet(QString::fromUtf8("background-image: url(:/Imagenes/Multijugador.png);"));
        radioButton = new QRadioButton(centralwidget);
        radioButton->setObjectName(QString::fromUtf8("radioButton"));
        radioButton->setGeometry(QRect(670, 290, 51, 61));
        radioButton->setStyleSheet(QString::fromUtf8("background-image: url(:/Imagenes/IconMorty.png);"));
        radioButton_2 = new QRadioButton(centralwidget);
        radioButton_2->setObjectName(QString::fromUtf8("radioButton_2"));
        radioButton_2->setGeometry(QRect(580, 290, 51, 61));
        radioButton_2->setStyleSheet(QString::fromUtf8("background-image: url(:/Imagenes/IconRick.png);"));
        label = new QLabel(centralwidget);
        label->setObjectName(QString::fromUtf8("label"));
        label->setGeometry(QRect(610, 100, 341, 281));
        label->setMaximumSize(QSize(360, 288));
        label->setStyleSheet(QString::fromUtf8("background-image: url(:/Imagenes/LlegamosCasa.gif);"));
        label_2 = new QLabel(centralwidget);
        label_2->setObjectName(QString::fromUtf8("label_2"));
        label_2->setEnabled(true);
        label_2->setGeometry(QRect(0, 0, 960, 516));
        label_2->setMinimumSize(QSize(960, 516));
        label_2->setMaximumSize(QSize(960, 516));
        label_2->setStyleSheet(QString::fromUtf8("background-image: url(:/Imagenes/instruccionesImagen.png);"));
        pushButton = new QPushButton(centralwidget);
        pushButton->setObjectName(QString::fromUtf8("pushButton"));
        pushButton->setGeometry(QRect(20, 410, 40, 40));
        pushButton->setMaximumSize(QSize(40, 40));
        pushButton->setStyleSheet(QString::fromUtf8("background-image: url(:/Imagenes/Atras.png);"));
        label_3 = new QLabel(centralwidget);
        label_3->setObjectName(QString::fromUtf8("label_3"));
        label_3->setGeometry(QRect(220, 80, 341, 321));
        label_3->setStyleSheet(QString::fromUtf8("background-image: url(:/Imagenes/mortyllorando.gif);"));
        bottonUsurario = new QPushButton(centralwidget);
        bottonUsurario->setObjectName(QString::fromUtf8("bottonUsurario"));
        bottonUsurario->setGeometry(QRect(300, 160, 140, 61));
        bottonUsurario->setMaximumSize(QSize(140, 16777215));
        bottonUsurario->setStyleSheet(QString::fromUtf8("background-image: url(:/Imagenes/Usuario.png);"));
        lineEdit = new QLineEdit(centralwidget);
        lineEdit->setObjectName(QString::fromUtf8("lineEdit"));
        lineEdit->setGeometry(QRect(450, 179, 141, 21));
        bottonReiniciar = new QPushButton(centralwidget);
        bottonReiniciar->setObjectName(QString::fromUtf8("bottonReiniciar"));
        bottonReiniciar->setGeometry(QRect(800, 10, 24, 24));
        bottonReiniciar->setMaximumSize(QSize(24, 24));
        bottonReiniciar->setStyleSheet(QString::fromUtf8("background-image: url(:/Imagenes/ReiniciarP.png);"));
        pushButton_2 = new QPushButton(centralwidget);
        pushButton_2->setObjectName(QString::fromUtf8("pushButton_2"));
        pushButton_2->setGeometry(QRect(130, 150, 161, 71));
        pushButton_2->setStyleSheet(QString::fromUtf8("background-image: url(:/Imagenes/Jugador.png);"));
        MainWindow->setCentralWidget(centralwidget);
        graphicsView->raise();
        lineEdit->raise();
        label_2->raise();
        label_3->raise();
        label->raise();
        bottonReiniciar->raise();
        bottonUsurario->raise();
        bottonJugar->raise();
        bottonInstrucciones->raise();
        radioButton_2->raise();
        radioButton->raise();
        pushButton->raise();
        bottonMultijugador->raise();
        pushButton_2->raise();
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
        radioButton->setText(QString());
        radioButton_2->setText(QString());
        label->setText(QString());
        label_2->setText(QString());
        pushButton->setText(QString());
        label_3->setText(QString());
        bottonUsurario->setText(QString());
        bottonReiniciar->setText(QString());
        pushButton_2->setText(QString());
    } // retranslateUi

};

namespace Ui {
    class MainWindow: public Ui_MainWindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MAINWINDOW_H
