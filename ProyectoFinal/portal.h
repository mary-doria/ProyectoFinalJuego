#ifndef PORTAL_H
#define PORTAL_H
#include <QMainWindow>
#include <QObject>
#include <QWidget>
#include <math.h>
#include <QGraphicsItem>
#include <QPainter>
#include <string.h>
#include <QPixmap>
#include <QGraphicsPixmapItem>

class Portal: public QGraphicsItem//Se realiza herencia publica
{
    float posy, posx, velX, velY;//Variables de Posicion y velocidad del portal
    float delta = 0.2;//Variable delta,Cambio en el tiempo del portal
    float dx, dy;
    float ancho,alto,contadorPos;//Varible Ancho,alto de la imagen del portal y contador la posicion del portal
    float posyInicial;//Varible Posicion en y inicial
    QPixmap *pixmapPortal; //variable pixmap:Imagen del portal
    public:
    QRectF boundingRect() const;
    void paint(QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget *widget);
    Portal(float x,float y,float vx,float vy );//Constructor de la clase portal
    //Funcion donde se actualiza el movimiento senoidal en todo instante de tiempo
    void ActualizarPosicionPortal();
    //Posicion en y
    float getPosy() const;//Retorna un entero de la posicion en y
    void setPosy(float value);//Actualiza la posicion en y
    //Posicion en x
    float getPosx() const;//Retorna un entero de la posicion en x
    void setPosx(float value);//Actualiza la posicion en x
    //Velocidad en x
    float getVelX() const;//Retorna un entero de la velocidad en x
    void setVelX(float value);//Actualiza la velocidad en x
    //Velocidad en y
    float getVelY() const;//Retorna un entero de la velocidad en y
    void setVelY(float value);//Actualiza la velocidad en y
};

#endif // PORTAL_H
