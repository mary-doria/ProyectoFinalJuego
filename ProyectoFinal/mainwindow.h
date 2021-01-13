#ifndef MAINWINDOW_H
#define MAINWINDOW_H
#include <QMainWindow>
#include <cuerpopersonajejugador.h>
#include <QList>
#include <QDebug>
#include "spritegusano.h"
//para el vector
#include <QVector> // puedo guardar posciones, pos de  figuras etc
//para los archivos
#include <fstream> // flujo de entrada y salida para leer los archivos
#include <iostream>// para mostrar en consola.



QT_BEGIN_NAMESPACE
namespace Ui { class MainWindow; }
QT_END_NAMESPACE

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();
private:
    Ui::MainWindow *ui;
    CuerpoPersonajeJugador *PersonajePrincipal;
    QGraphicsScene *scene;
    QTimer *timer;
    void keyPressEvent(QKeyEvent *evento);
    QList<spritegusano*> enemigos;// lista de enemigos gusanos
    QVector < int > V_posgusanos; // vector con las posiciones de los gusanos
    spritegusano *enemigo1; // crear el puntero para la clase gusano
    spritegusano *enemigo2; // crear el puntero para la clase gusano

    // funcion para cargar los archivos
     void cargarPosgusano();

public slots:
    void moveEnemy();
};
#endif // MAINWINDOW_H
