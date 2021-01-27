#include "portal.h"



float Portal::getPosy() const
{
    return posy;
}

void Portal::setPosy(float value)
{
    posy = value;
}

float Portal::getPosx() const
{
    return posx;
}

void Portal::setPosx(float value)
{
    posx = value;
}

float Portal::getVelX() const
{
    return velX;
}

void Portal::setVelX(float value)
{
    velX = value;
}

float Portal::getVelY() const
{
    return velY;
}

void Portal::setVelY(float value)
{
    velY = value;
}

QRectF Portal::boundingRect() const
{
    return QRectF(-ancho/2,-alto/2,ancho,alto);
}

void Portal::paint(QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget *widget)
{
    painter->drawPixmap(-ancho/2,-alto/2,*pixmapPortal,dy,dx,ancho,alto);

}

Portal::Portal(float x,float y,float vx ,float vy)
{
    this->posx=x;
    this->posy=y;
    this->dx = 4;
    this->dy =4;
    this->ancho = 124;
    this->alto=160;
    this->contadorPos=0;
    this->velX = vx;
    this->velY = vy;
    this->posyInicial=y;
    pixmapPortal = new QPixmap(":/Imagenes/portalrickandmorty.png");
    setPos(posx,posy);
}

void Portal::ActualizarPosicionPortal()
{
        if(this->posx>960 || this->posx<40){
        velX=-velX;
        }
        this->posx = (posx - velX*delta);
        this->contadorPos= contadorPos + delta;
        this->posy=30*sin(2*3.1415*contadorPos/2)+posyInicial;
        setPos(posx,posy);

}





