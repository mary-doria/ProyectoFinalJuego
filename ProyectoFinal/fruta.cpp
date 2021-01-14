
#include "fruta.h"

fruta::fruta(int x, int y)
{

    this->pixmapfruta1 = new QPixmap(":/Imagenes/Morty.png");
    this->ancho =38;
    this->alto=40;

}

int fruta::getPosx() const
{
    return posx;
}

void fruta::setPosx(int value)
{
    posx = value;
}

int fruta::getPosy() const
{
    return posy;
}

void fruta::setPosy(int value)
{
    posy = value;
}

QRectF fruta::boundingRect() const
{
     return QRectF(-ancho/2,-alto/2,ancho,alto);
}

void fruta::paint(QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget *widget)
{
    painter->drawPixmap(-ancho/2,-alto/2,*pixmapfruta1,40,0,ancho,alto);
    painter->drawPixmap(-ancho/2,-alto/2,*pixmapfruta2,40,38,ancho,alto);
    painter->drawPixmap(-ancho/2,-alto/2,*pixmapfruta3,40,76,ancho,alto);
    painter->drawPixmap(-ancho/2,-alto/2,*pixmapfruta4,40,114,ancho,alto);
}

