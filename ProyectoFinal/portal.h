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

class Portal: public QGraphicsItem
{
    float posy, posx, velX, velY;
    float delta = 1;
    float dx, dy;
    float ancho,alto,contadorPos;

    QPixmap *pixmapPortal; //variable pixap
public:
    QRectF boundingRect() const;
    void paint(QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget *widget);
    Portal(float x,float y,float vx,float vy );
    void ActualizarPosicionPortal();




    float getPosy() const;
    void setPosy(float value);
    float getPosx() const;
    void setPosx(float value);
    float getVelX() const;
    void setVelX(float value);
    float getVelY() const;
    void setVelY(float value);
};

#endif // PORTAL_H
