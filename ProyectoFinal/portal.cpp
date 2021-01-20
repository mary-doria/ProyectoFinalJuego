#include "portal.h"


double Portal::getPosx() const
{
    return posx;
}

void Portal::setPosx(double value)
{
    posx = value;
}

double Portal::getVelX() const
{
    return velX;
}

void Portal::setVelX(double value)
{
    velX = value;
}

double Portal::getVelY() const
{
    return velY;
}

void Portal::setVelY(double value)
{
    velY = value;
}



double Portal::getMasa() const
{
    return masa;
}

void Portal::setMasa(double value)
{
    masa = value;
}

QRectF Portal::boundingRect() const
{
    return QRectF(-r,-r,2*r,2*r);
}

void Portal::paint(QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget *widget)
{
    painter->drawPixmap(-r,-r,*pixmapportal,0,0,2*r,2*r);

}

Portal::Portal(double x, double y, double vx, double vy, double m, int r_)
{
    this->r=r_;
    this->posx=x;
    this->posy=y;
    this->velX = vx;
    this->velY = vy;
    this->masa = m;
    pixmapportal = new QPixmap(":/Imagenes/portalrickandmorty.png");
    setPos(posx,posy);
}

void Portal::ActualizarPosicion(double acel_x, double acel_y)
{
    this->velX = velX + acel_x*delta;
    this->velY = velY + acel_y*delta;
    this->posx= posx + velX*delta + (0.5)*acel_x*(delta*delta);
    this->posy= posy + velY*delta + (0.5)*acel_y*(delta*delta);

}

double Portal::getPosy() const
{
    return posy;
}

void Portal::setPosy(double value)
{
    posy = value;
}
