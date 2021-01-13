#ifndef MAINWINDOW_H
#define MAINWINDOW_H
#include <QMainWindow>
#include <cuerpopersonajejugador.h>
#include <QList>
#include <QDebug>
#include "spritegusano.h"
#include <QDesktopWidget>
#include <QDebug>
#include <QVector>
#include <iostream>//Flujo de entrada y salida para leer los archivos
#include <fstream>
#include "plataforma.h"




QT_BEGIN_NAMESPACE
namespace Ui { class MainWindow; }
QT_END_NAMESPACE

class MainWindow : public QMainWindow
{
    Q_OBJECT


public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();
    //QVector < Plataforma *> vectorPlataformas;

private:
    Ui::MainWindow *ui;
    CuerpoPersonajeJugador *PersonajePrincipal;
    QGraphicsScene *scene;
    QTimer *timercaida;
    Plataforma *plataformaPiso;
    /*Plataforma *plataforma2;
    Plataforma *plataforma3;
    Plataforma *plataforma4;
    Plataforma *plataforma5;
    Plataforma *plataforma6;
    Plataforma *plataforma7;



    void cargaArchivos();*/


    void keyPressEvent(QKeyEvent *evento);

    QList<spritegusano*> enemigos;// lista de enemigos gusanos
    QVector < int > V_posgusanos; // vector con las posiciones de los gusanos
    spritegusano *enemigo1; // crear el puntero para la clase gusano
    spritegusano *enemigo2; // crear el puntero para la clase gusano

     float x,y,ancho,alto;
    // funcion para cargar los archivos
     void cargarPosgusano();

public slots:
    void moveEnemy();
    void activaG();//Actualizacion caida libre personaje esta hara el slot
};
#endif // MAINWINDOW_H
