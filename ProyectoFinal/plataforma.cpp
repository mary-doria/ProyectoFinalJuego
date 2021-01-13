#include "plataforma.h"
#include <QPixmap>
#include <QTimer>



int Plataforma::posy() const
{
    return posy_;
}

void Plataforma::setPosy(int posy)
{
    posy_ = posy;
}

int Plataforma::posx() const
{
    return posx_;
}

void Plataforma::setPosx(int posx)
{
    posx_ = posx;
}

Plataforma::Plataforma(int x, int y)
{
    this->posx_=x;
    this->posy_=y;
    // dar posicion
    setPos(posx_,posy_);
    this->pixmapPlataforma = new QPixmap(":/Imagenes/PlataformaEscenario2.png");
    this->dx = 0;
    this->dy =0;
    this->ancho = 148;
    this->alto=40;

}

QRectF Plataforma::boundingRect() const
{
    return QRectF(-ancho/2,-alto/2,ancho,alto);

}

void Plataforma::paint(QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget *widget)
{
 painter->drawPixmap(-ancho/2,-alto/2,*pixmapPlataforma,dx,dy,ancho,alto);
}
