#ifndef CUERPOPERSONAJEJUGADOR_H
#define CUERPOPERSONAJEJUGADOR_H
#include <QObject>
#include <QGraphicsItem>
#include <QTimer>
#include <QPixmap>
#include <QGraphicsPixmapItem>
#include <QPainter>
#include <QGraphicsScene>
#include <QKeyEvent>

class CuerpoPersonajeJugador:public QObject ,public QGraphicsItem
{   int r;
    int posx, posy;
    int velocidad = 5;// velocidad del jugador


    // variables para el pacman
    float dx, dy;  //variables para controlar las filas y las columnas del sprite
    float ancho,alto;

    QPixmap *pixmap; //variable pixap

public:
    CuerpoPersonajeJugador(int x, int y);
    // posicion x y y
    int getPosx() const;
    void setPosx(int px);
    int getPosy() const;
    void setPosy(int py);

    QRectF boundingRect() const;// para dibujar el cuerpo
    void paint(QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget *widget = nullptr);
    //void arriba();//Salto
    //abajo
    //void abajo();//Caida libre
    //izquierda
    void izquierda();//Movimiento lineal
    //derecha
    void  derecha();//Movimiento lineal

    void actualizar_sprite_derecha();   //funcion para actualizar el sprite para la derecha
   // void actualizar_sprite_arriba();    //funcion para actualizar el sprite para arriba
    void actualizar_sprite_izquierda(); //funcion para actualizar el sprite para la izquierda
    //void actualizar_sprite_abajo();     //funcion para actualizar el sprite para abajo


};

#endif // CUERPOPERSONAJEJUGADOR_H
