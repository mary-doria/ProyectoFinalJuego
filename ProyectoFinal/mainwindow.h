#ifndef MAINWINDOW_H
#define MAINWINDOW_H
#include <QMainWindow>
#include <QList> // para utilizar el Qlist
#include <QDesktopWidget>
#include <QDebug>// para imprimir mensajes en la terminal
#include <QMessageBox> // para imprimir mensajes como recuadros
#include <QVector> // para usar los Qvector
#include <iostream>//Flujo de entrada y salida para leer los archivos
#include <fstream> // para los archivos
#include <QRectF>
#include <iterator>
#include <QMessageBox>
#include <QListWidget>
#include <QMediaPlayer>
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
    QString nombre;//Variable nombre del usuario
    int puedoguardar=0;//Contador
    bool Multijugador=false;//Variable Booleana
    int escogerPersonaje,escogerPersonaje2=1;//entero que dice cual de los dos personaje se jugara
    int puntosAcumulados;//Variable donde se guardaran los puntos que lleva el personaje
    QMessageBox msgBox;//Varible Cuadro de texto
    Puntaje * Puntos;//Creacion del puntero Puntos de la clase Puntaje
    CuerpoPersonajeJugador *PersonajePrincipal;//Creacion del puntero PersonajePrincipal con los atributos de CuerpoPersonajeJugador
    //Listas de objetos de diferentes clases
    QList<frutaBurbuja *> modificarFrutaBurbuja(QList<frutaBurbuja *> listaFrutaBurbuja, int posicion);
    QList<Vida *> modificarVida(QList<Vida *> listaVida, int posicion);
    QList<frutaBurbuja*> listaFrutaBurbuja;//Declaracion de la lista frutaBurbuja
    QList<Vida*> listaVida;
    QList<Plataforma*> listaPlataformas;
    //Vector
    QVector<spritegusano*>vectorAuxGusanos;
    QGraphicsScene *scene,scene2;
    QTimer *timercaida,*timersalto,*timerfrutaburbuja,*timerVida,*timerEnemigos;//Punteros de la clase QTimers
    frutaBurbuja *fruta1,*fruta2,*fruta3,*fruta4,*fruta5,*fruta6,*fruta7,*fruta8,*fruta9,*fruta10,*fruta11,*fruta12,*fruta13,*fruta14,*fruta15,*fruta16;
    Vida *vida1,*vida2,*vida3,*vida4,*vida5;//Creacion de punteros de la clase vida
    //PRIMER NIVEL PLATAFORMAS
    Plataforma *plataformaInicialPosicion;// crear el puntero para la clase plataforma
    Plataforma *plataforma2;// crear el puntero para la clase plataforma
    Plataforma *plataforma3;// crear el puntero para la clase plataforma
    Plataforma *plataforma4;// crear el puntero para la clase plataforma
    Plataforma *plataforma5;// crear el puntero para la clase plataforma
    Plataforma *plataforma6;// crear el puntero para la clase plataforma
    Plataforma *plataforma7;// crear el puntero para la clase plataforma
    Plataforma *plataforma8;// crear el puntero para la clase plataforma
    Plataforma *plataforma9;// crear el puntero para la clase plataforma
    Plataforma *plataforma10;// crear el puntero para la clase plataforma
    Plataforma *plataforma11;// crear el puntero para la clase plataforma
    Plataforma *plataforma12;// crear el puntero para la clase plataforma
    Plataforma *plataforma13;// crear el puntero para la clase plataforma
    //SEGUNDO NIVEL PLATAFORMAS
    Plataforma *plataformaInicialPosicion2;// crear el puntero para la clase plataforma
    Plataforma *plataforma14;// crear el puntero para la clase plataforma
    Plataforma *plataforma15;// crear el puntero para la clase plataforma
    Plataforma *plataforma16;// crear el puntero para la clase plataforma
    Plataforma *plataforma17;// crear el puntero para la clase plataforma
    Plataforma *plataforma18;// crear el puntero para la clase plataforma
    Plataforma *plataforma19;// crear el puntero para la clase plataforma
    QMessageBox *mensaje;//puntero para los mensajes
    QMessageBox Mensaje;// Multijugador variable para los mensajes
    nave *naverickmorty;//Puntero de la nave
    QTimer *timerMoscas;
    QTimer *timer2Moscas;
    int val=0;
    float dt;
    float h_limit;//limite horizontal
    float v_limit;//limite vertical
    void bordedelete(spritemoscas *b);//funcion para eliminar a las moscas del borde
    spritemoscas *mosca;// crear el puntero para la clase mosca
    QList<spritemoscas *> moscas; // crear el puntero de la lista para la clase mosca
    bool banderaMosca=true; // bandera usara para la clase mosca

    //sonidos aqui creamos los punteros para los sonidos de inicio y del disparo
    QMediaPlayer * music = new QMediaPlayer();
    QMediaPlayer * disparo = new QMediaPlayer();

    //Para el multijugador
    //Moscas
    spritemoscas *mosca1;// crear el puntero para la clase mosca para el multijugador
    spritemoscas *mosca2;// crear el puntero para la clase mosca para el multijugador
    int puntosJ1=0;//variable para guardar la cantidad de puntos del jugador 1
    int puntosJ2=0;//variable para guardar la cantidad de puntos del jugador 1
    bool banderaMulti;//bandera que se utilizara en el multijugador
    int contadorMulti=0;//variable que se usa en el multijugador

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
    Portal *portalRickMorty;
    QTimer *timerportalRickMorty;
    float x,y,ancho,alto;
     void keyPressEvent(QKeyEvent *evento);//funcion que permite el movimiento del personaje
     void cargarPosgusano(int nivel);//carga las posciones de los gusanos
     void sprite_burbuja();
     //NIVELES
     int nivelActual=0;
     void primerNivel();
     void segundoNivel();
     void nivelCasa();
     void muerte();
public slots:
    void moveEnemy();//Actualiza el mov de los gusanos
    void activaG();//Actualizacion caida libre personaje esta hara el slot
    void activaSalto();//Actualizacion salto personaje
    void actualizar_frutaburbuja();//Se actualiza la cantidad de frutasBurbujas que hay
    void actualizar_vida();//Se actualiza la cantidad de vidas que hay
    void actualizar_portal();//Se actualiza la posicion del portal
    void crearMoscas();//para crear la lista con todas las moscas utilizadas en la scena
    void actualizarMoscas();//para actualizar la posicion de las moscas que hay en scena

//Funciones Slots Privadas
private slots:
    //Labels que contienen imagenes estaticas o en movimiento
    void on_label_windowTitleChanged(const QString &title);
    void on_label_2_windowTitleChanged(const QString &title);
    void on_lineEdit_windowTitleChanged(const QString &title);//Cuadro de texto donde se inserta el nombre de usuario
    //Botones del menu
    void on_bottonJugar_clicked();//Funcion jugar,Ligada a un boton ,se debe hacer click para realice la funcion
    void on_bottonInstrucciones_clicked();//Funcion instrucciones,Ligada a un boton ,se debe hacer click para realice la funcion
    void on_bottonMultijugador_clicked();//Funcion multijugador,Ligada a un boton ,se debe hacer click para realice la funcion
    void on_radioButton_2_clicked();//Funcion que contiene un entero el cual es uno de los dos personajes
    void on_radioButton_clicked();//Funcion que contiene un entero el cual es uno de los dos personajes
    void on_bottonReiniciar_clicked();//Funcion reiniciar en el nivel 1
    void on_bottonUsurario_clicked();//Funcion registro
    void on_cargarPartida_clicked();//Funcion Cargar partida
    void on_eliminarPartida_clicked();//Funcion eliminar partida
    void on_salir_clicked();//Funcion salir del juego
    void on_pushButton_clicked();//Boton para ir hacia atras en la instrucciones
    void on_pushButton_2_clicked();//Boton 1 solo jugador
    void on_pushButton_3_clicked();//Boton quitar sonido

};
#endif // MAINWINDOW_H
