#ifndef MAINWINDOW_H
#define MAINWINDOW_H
#include <QMainWindow>
#include <cuerpopersonajejugador.h>
#include <QList>
#include "spritegusano.h"
#include <QDesktopWidget>
#include <QDebug>
#include <QVector>
#include <iostream>//Flujo de entrada y salida para leer los archivos
#include <fstream>
#include "plataforma.h"
#include "nave.h"
//score
#include <score.h>


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
    bool bandera;
    Ui::MainWindow *ui;
    CuerpoPersonajeJugador *PersonajePrincipal;
    QGraphicsScene *scene;
    QTimer *timercaida;
    QTimer *timersalto;
    Plataforma *plataformaInicialPosicion;
    Plataforma *plataforma2;
    Plataforma *plataforma3;
    Plataforma *plataforma4;
    Plataforma *plataforma5;
    Plataforma *plataforma6;
    Plataforma *plataforma7;
    Plataforma *plataforma8;
    Plataforma *plataforma9;
    Plataforma *plataforma10;
    Plataforma *plataforma11;
    Plataforma *plataforma12;
    Plataforma *plataforma13;
    //Plataforma *plataforma8;
    //Plataforma *plataforma8;
    nave *naverickmorty;
    //void cargaArchivos();
    QList<Plataforma*> listaPlataformas;

    void keyPressEvent(QKeyEvent *evento);

    QList<spritegusano*> enemigos;// lista de enemigos gusanos
    QVector < int > V_posgusanos; // vector con las posiciones de los gusanos
    spritegusano *enemigo1; // crear el puntero para la clase gusano
    spritegusano *enemigo2; // crear el puntero para la clase gusano
    spritegusano *enemigo3; // crear el puntero para la clase gusano
    spritegusano *enemigo4; // crear el puntero para la clase gusano
    spritegusano *enemigo5; // crear el puntero para la clase gusano
    spritegusano *enemigo6; // crear el puntero para la clase gusano
    spritegusano *enemigo7; // crear el puntero para la clase gusano
    spritegusano *enemigo8; // crear el puntero para la clase gusano
    spritegusano *enemigo9; // crear el puntero para la clase gusano
    spritegusano *enemigo10; // crear el puntero para la clase gusano

    Score *score;

    //void DactivaG();
    float x,y,ancho,alto;
     void cargarPosgusano();
public slots:
    void moveEnemy();

    void activaG();//Actualizacion caida libre personaje esta hara el slot
    void activaSalto();
};
#endif // MAINWINDOW_H
