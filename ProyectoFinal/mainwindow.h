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
#include "frutaburbuja.h"
#include <QRectF>
#include <iterator>





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
    QTimer *timersalto;
    QTimer *timerfrutaburbuja;
    frutaBurbuja *fruta1,*fruta2,*fruta3,*fruta4,*fruta5,*fruta6,*fruta7,*fruta8,*fruta9,*fruta10,*fruta11,*fruta12,*fruta13,*fruta14,*fruta15,*fruta16;
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



    nave *naverickmorty;

    QList<Plataforma*> listaPlataformas;
    QList<frutaBurbuja*> listaFrutaBurbuja;

    void keyPressEvent(QKeyEvent *evento);

    QList<spritegusano*> enemigos;// lista de enemigos gusanos
    QVector < int > V_posgusanos; // vector con las posiciones de los gusanos
    spritegusano *enemigo1; // crear el puntero para la clase gusano
    spritegusano *enemigo2; // crear el puntero para la clase gusano

    int dx, dy;
    //void DactivaG();
    float x,y,ancho,alto;
     void cargarPosgusano();
     void sprite_burbuja();
public slots:
    void moveEnemy();
    void activaG();//Actualizacion caida libre personaje esta hara el slot
    void activaSalto();

    void actualizar_frutaburbuja();
};
#endif // MAINWINDOW_H
