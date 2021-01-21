#include "vida.h"



int Vida::getPosy() const
{
    return posy;
}

void Vida::setPosy(int value)
{
    posy = value;
}

QRectF Vida::boundingRect() const
{
    return QRectF(-ancho/2,-alto/2,ancho,alto);
}

void Vida::paint(QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget *widget)
{
    painter->drawPixmap(-ancho/2,-alto/2,*pixmapVidaCerveza,dx,dy,ancho,alto);
}
int Vida::getPosx() const
{
    return posx;
}

void Vida::setPosx(int value)
{
    posx = value;
}


Vida::Vida(int x, int y)
{
    this->posx=x;
    this->posy=y;
    this->dx = 0;
    this->dy =0;
    this->pixmapVidaCerveza=new QPixmap(":/Imagenes/CervezaVidaRickMorty.png");
    this->ancho=60;
    this->alto=60;
    setPos(posx,posy);

}

