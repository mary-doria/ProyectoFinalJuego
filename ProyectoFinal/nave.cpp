#include "nave.h"



int nave::getPosy() const
{
    return posy;
}

void nave::setPosy(int value)
{
    posy = value;
}

QRectF nave::boundingRect() const
{
    return QRectF(-ancho/2,-alto/2,ancho,alto);
}

void nave::paint(QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget *widget)
{
    painter->drawPixmap(-ancho/2,-alto/2,*pixmapnave,dx,dy,ancho,alto);
}
int nave::getPosx() const
{
    return posx;
}

void nave::setPosx(int value)
{
    posx = value;
}


nave::nave(int x, int y)
{
    this->posx=x;
    this->posy=y;
    this->dx = 0;
    this->dy =0;
    this->pixmapnave=new QPixmap(":/Imagenes/uforickandmorty.png");
    this->ancho=300;
    this->alto=234;
    setPos(posx,posy);

}

