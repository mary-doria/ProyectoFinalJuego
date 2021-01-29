#ifndef MAINWINDOW_H
#define MAINWINDOW_H
#include <QMainWindow>
#include <QList>
#include <QDesktopWidget>
#include <QDebug>
#include <QMessageBox>
#include <QVector>
#include <iostream>//Flujo de entrada y salida para leer los archivos
#include <fstream>
#include <QRectF>
#include <iterator>
//Clases creadas
#include <cuerpopersonajejugador.h>
#include "plataforma.h"
#include "nave.h"
#include "frutaburbuja.h"
#include "bala.h"
#include "vida.h"
#include "portal.h"
#include "spritegusano.h"
#include "puntaje.h"
#include "spritemoscas.h"
#include <QMessageBox>
#include <QListWidget>


using namespace std;

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
    bool bandera;
    Ui::MainWindow *ui;
    QString nombre;
    int puedoguardar=0;
    QMessageBox msgBox;
    QList<frutaBurbuja*> listaFrutaBurbuja;
    CuerpoPersonajeJugador *PersonajePrincipal;
    QList<frutaBurbuja *> modificarFrutaBurbuja(QList<frutaBurbuja *> listaFrutaBurbuja, int posicion);
    QList<Vida *> modificarVida(QList<Vida *> listaVida, int posicion);
    QVector<spritegusano*>vectorAuxGusanos;
    QGraphicsScene *scene,scene2;
    QList<Vida*> listaVida;
    bool Multijugador=false;
    int escogerPersonaje,escogerPersonaje2=1;
    Puntaje * Puntos;
    int puntosAcumulados;
    QTimer *timercaida,*timersalto,*timerfrutaburbuja,*timerVida,*timerEnemigos;
    frutaBurbuja *fruta1,*fruta2,*fruta3,*fruta4,*fruta5,*fruta6,*fruta7,*fruta8,*fruta9,*fruta10,*fruta11,*fruta12,*fruta13,*fruta14,*fruta15,*fruta16;
    Vida *vida1,*vida2,*vida3,*vida4,*vida5;
    //PRIMER NIVEL PLATAFORMAS
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
    //SEGUNDO NIVEL PLATAFORMAS
    Plataforma *plataformaInicialPosicion2;
    Plataforma *plataforma14;
    Plataforma *plataforma15;
    Plataforma *plataforma16;
    Plataforma *plataforma17;
    Plataforma *plataforma18;
    Plataforma *plataforma19;
    QMessageBox *mensaje;
    QMessageBox Mensaje;// Multijugador

    nave *naverickmorty;
    QList<Plataforma*> listaPlataformas;
    QTimer *timerMoscas;
    QTimer *timer2Moscas;
    int val=0;
    float dt;
    float h_limit;
    float v_limit;
    void bordedelete(spritemoscas *b);
    spritemoscas *mosca;
    QList<spritemoscas *> moscas;
    bool banderaMosca=true;

    //Para el multijugador
    //Moscas
    spritemoscas *mosca1;
    spritemoscas *mosca2;
    int puntosJ1=0;
    int puntosJ2=0;
    bool banderaMulti;
    int contadorMulti=0;

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

    Portal *portalRickMorty,*portalRickMorty2;
    QTimer *timerportalRickMorty;

    int nivelActual=0;

    float x,y,ancho,alto;
     void keyPressEvent(QKeyEvent *evento);
     void cargarPosgusano(int nivel);
     void sprite_burbuja();
     void segundoNivel();
     void nivelCasa();
     void primerNivel();
     void muerte();
public slots:
    void moveEnemy();
    void activaG();//Actualizacion caida libre personaje esta hara el slot
    void activaSalto();
    void actualizar_frutaburbuja();
    void actualizar_vida();
    void actualizar_portal();
    void crearMoscas();
    void actualizarMoscas();


private slots:

    void on_bottonJugar_clicked();
    void on_bottonInstrucciones_clicked();
    //void on_bottonUsuario_clicked();
    void on_bottonMultijugador_clicked();
    void on_radioButton_2_clicked();
    void on_radioButton_clicked();

    void on_label_windowTitleChanged(const QString &title);
    void on_label_2_windowTitleChanged(const QString &title);
    void on_pushButton_clicked();
    void on_label_3_windowTitleChanged(const QString &title);

    void on_lineEdit_windowTitleChanged(const QString &title);

    void on_bottonUsurario_clicked();

    void on_bottonReiniciar_clicked();
    void on_pushButton_2_clicked();
    void on_cargarPartida_clicked();
    void on_eliminarPartida_clicked();
    void on_salir_clicked();
};
#endif // MAINWINDOW_H
