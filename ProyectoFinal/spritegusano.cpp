#include "spritegusano.h"
#include <QPixmap>

spritegusano::spritegusano(QObject *parent) : QObject(parent)
{
    timer = new QTimer();
    fila =0;
    columna =0;
    pixmap = new QPixmap(":/imagen/gusanos_loks_sinFondo_cuadrado.png");

    // dimensiones de las imagenes
    ancho =122;
    alto =122;
    timer->start(100);
    connect(timer,&QTimer::timeout,this,&spritegusano::actualizacionGusano);

}

spritegusano::spritegusano(bool _bande, int x, int y)
{
    posx = x;
    posy = y;
    bande = _bande;
    setPos(posx,posy);// posicion del enemigo.
    timer = new QTimer();
    fila =0;
    columna =0;
    pixmap = new QPixmap(":/Imagenes/gusanos_loks_sinFondo_cuadrado.png");

    // dimensiones de las imagenes
    ancho =122;
    alto =122;
    timer->start(100);
    connect(timer,&QTimer::timeout,this,&spritegusano::actualizacionGusano);


}
int spritegusano::getPosx() const
{
    return posx;
}

void spritegusano::setPosx(int px)
{
    posx = px;
}

int spritegusano::getPosy() const
{
    return posy;
}

void spritegusano::setPosy(int py)
{
    posy = py;
}

void spritegusano::left(int velocidad)
{
    posx -= 1*velocidad;
    fila =190;
    setPos(posx, posy);
}

void spritegusano::right(int velocidad)
{

    posx += 1*velocidad;
    fila =350;
    setPos(posx, posy);
}


void spritegusano::actualizacionGusano()
{
    columna += 122;
    if(columna >= 400){
        columna = 0;
    }
    this->update(-ancho/2,-alto/2,ancho,alto);

}

QRectF spritegusano::boundingRect() const
{
    return QRectF(-ancho/2,-alto/2,ancho,alto);
}

void spritegusano::paint(QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget *widget)
{
   painter->drawPixmap(-ancho/2,-alto/2,*pixmap,columna,fila,ancho,alto);

}
