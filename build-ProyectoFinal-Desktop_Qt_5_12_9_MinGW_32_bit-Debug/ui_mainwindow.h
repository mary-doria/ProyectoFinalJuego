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
    QPushButton *bottonUsurario;
    QLineEdit *lineEdit;
    QPushButton *bottonReiniciar;
    QPushButton *pushButton_2;
    QPushButton *cargarPartida;
    QPushButton *eliminarPartida;
    QPushButton *salir;
    QPushButton *pushButton_3;
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
        bottonJugar->setGeometry(QRect(260, 240, 111, 51));
        bottonJugar->setStyleSheet(QString::fromUtf8("background-image: url(:/Imagenes/JugarRickMorty.png);"));
        bottonInstrucciones = new QPushButton(centralwidget);
        bottonInstrucciones->setObjectName(QString::fromUtf8("bottonInstrucciones"));
        bottonInstrucciones->setGeometry(QRect(440, 240, 191, 55));
        bottonInstrucciones->setMaximumSize(QSize(16777215, 55));
        bottonInstrucciones->setStyleSheet(QString::fromUtf8("background-image: url(:/Imagenes/instrucciones.png);"));
        bottonMultijugador = new QPushButton(centralwidget);
        bottonMultijugador->setObjectName(QString::fromUtf8("bottonMultijugador"));
        bottonMultijugador->setGeometry(QRect(340, 170, 171, 51));
        bottonMultijugador->setMaximumSize(QSize(16777215, 61));
        bottonMultijugador->setStyleSheet(QString::fromUtf8("background-image: url(:/Imagenes/2jugadores.png);"));
        radioButton = new QRadioButton(centralwidget);
        radioButton->setObjectName(QString::fromUtf8("radioButton"));
        radioButton->setGeometry(QRect(250, 240, 51, 61));
        radioButton->setStyleSheet(QString::fromUtf8("background-image: url(:/Imagenes/IconMorty.png);"));
        radioButton_2 = new QRadioButton(centralwidget);
        radioButton_2->setObjectName(QString::fromUtf8("radioButton_2"));
        radioButton_2->setGeometry(QRect(170, 240, 51, 61));
        radioButton_2->setStyleSheet(QString::fromUtf8("background-image: url(:/Imagenes/IconRick.png);"));
        label = new QLabel(centralwidget);
        label->setObjectName(QString::fromUtf8("label"));
        label->setGeometry(QRect(610, 100, 341, 281));
        label->setMaximumSize(QSize(360, 288));
        label->setStyleSheet(QString::fromUtf8("background-image: url(:/Imagenes/LlegamosCasa.gif);"));
        label_2 = new QLabel(centralwidget);
        label_2->setObjectName(QString::fromUtf8("label_2"));
        label_2->setEnabled(true);
        label_2->setGeometry(QRect(0, -10, 960, 516));
        label_2->setMinimumSize(QSize(960, 516));
        label_2->setMaximumSize(QSize(960, 516));
        label_2->setStyleSheet(QString::fromUtf8("background-image: url(:/Imagenes/instruccionesImagen.png);"));
        pushButton = new QPushButton(centralwidget);
        pushButton->setObjectName(QString::fromUtf8("pushButton"));
        pushButton->setGeometry(QRect(20, 410, 40, 40));
        pushButton->setMaximumSize(QSize(40, 40));
        pushButton->setStyleSheet(QString::fromUtf8("background-image: url(:/Imagenes/Atras.png);"));
        bottonUsurario = new QPushButton(centralwidget);
        bottonUsurario->setObjectName(QString::fromUtf8("bottonUsurario"));
        bottonUsurario->setGeometry(QRect(310, 220, 211, 51));
        bottonUsurario->setMaximumSize(QSize(220, 16777215));
        bottonUsurario->setStyleSheet(QString::fromUtf8("background-image: url(:/Imagenes/registrousuario.png);"));
        lineEdit = new QLineEdit(centralwidget);
        lineEdit->setObjectName(QString::fromUtf8("lineEdit"));
        lineEdit->setGeometry(QRect(530, 230, 141, 21));
        bottonReiniciar = new QPushButton(centralwidget);
        bottonReiniciar->setObjectName(QString::fromUtf8("bottonReiniciar"));
        bottonReiniciar->setGeometry(QRect(800, 10, 24, 24));
        bottonReiniciar->setMaximumSize(QSize(24, 24));
        bottonReiniciar->setStyleSheet(QString::fromUtf8("background-image: url(:/Imagenes/ReiniciarP.png);"));
        pushButton_2 = new QPushButton(centralwidget);
        pushButton_2->setObjectName(QString::fromUtf8("pushButton_2"));
        pushButton_2->setGeometry(QRect(160, 170, 147, 51));
        pushButton_2->setMaximumSize(QSize(147, 16777215));
        pushButton_2->setStyleSheet(QString::fromUtf8("background-image: url(:/Imagenes/1jugador.png);"));
        cargarPartida = new QPushButton(centralwidget);
        cargarPartida->setObjectName(QString::fromUtf8("cargarPartida"));
        cargarPartida->setGeometry(QRect(540, 170, 191, 51));
        cargarPartida->setStyleSheet(QString::fromUtf8("background-image: url(:/Imagenes/cargarpartida.png);"));
        eliminarPartida = new QPushButton(centralwidget);
        eliminarPartida->setObjectName(QString::fromUtf8("eliminarPartida"));
        eliminarPartida->setGeometry(QRect(320, 250, 211, 51));
        eliminarPartida->setStyleSheet(QString::fromUtf8("background-image: url(:/Imagenes/eliminarpartida.png);"));
        salir = new QPushButton(centralwidget);
        salir->setObjectName(QString::fromUtf8("salir"));
        salir->setGeometry(QRect(860, 10, 50, 23));
        salir->setMaximumSize(QSize(50, 16777215));
        salir->setStyleSheet(QString::fromUtf8("background-image: url(:/Imagenes/salir.png);"));
        pushButton_3 = new QPushButton(centralwidget);
        pushButton_3->setObjectName(QString::fromUtf8("pushButton_3"));
        pushButton_3->setGeometry(QRect(20, 430, 31, 31));
        pushButton_3->setStyleSheet(QString::fromUtf8("border-image: url(:/Imagenes/Sonido.png);"));
        MainWindow->setCentralWidget(centralwidget);
        graphicsView->raise();
        label_2->raise();
        label->raise();
        bottonReiniciar->raise();
        bottonUsurario->raise();
        bottonJugar->raise();
        bottonInstrucciones->raise();
        radioButton_2->raise();
        pushButton->raise();
        bottonMultijugador->raise();
        cargarPartida->raise();
        lineEdit->raise();
        eliminarPartida->raise();
        radioButton->raise();
        salir->raise();
        pushButton_3->raise();
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
#ifndef QT_NO_WHATSTHIS
        bottonInstrucciones->setWhatsThis(QString());
#endif // QT_NO_WHATSTHIS
        bottonInstrucciones->setText(QString());
        bottonMultijugador->setText(QString());
        radioButton->setText(QString());
        radioButton_2->setText(QString());
        label->setText(QString());
        label_2->setText(QString());
        pushButton->setText(QString());
        bottonUsurario->setText(QString());
        bottonReiniciar->setText(QString());
        pushButton_2->setText(QString());
        cargarPartida->setText(QString());
        eliminarPartida->setText(QString());
        salir->setText(QString());
        pushButton_3->setText(QString());
    } // retranslateUi

};

namespace Ui {
    class MainWindow: public Ui_MainWindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MAINWINDOW_H
