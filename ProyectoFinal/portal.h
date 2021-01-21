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
    double posy, posx, velX, velY;
    double delta = 1;
    double masa;
    int r;
    QPixmap *pixmapportal; //variable pixap
public:
    QRectF boundingRect() const;
    void paint(QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget *widget);
    Portal(double x, double y, double vx, double vy, double m, int r_);
    void ActualizarPosicion(double acel_x, double acel_y);


    double getPosy() const;
    void setPosy(double value);
    double getPosx() const;
    void setPosx(double value);
    double getVelX() const;
    void setVelX(double value);
    double getVelY() const;
    void setVelY(double value);

    double getMasa() const;
    void setMasa(double value);
};

#endif // PORTAL_H
