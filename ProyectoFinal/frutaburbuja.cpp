#include "frutaburbuja.h"



int frutaBurbuja::getPosx() const
{
    return posx;
}

void frutaBurbuja::setPosx(int value)
{
    posx = value;
}

int frutaBurbuja::getPosy() const
{
    return posy;
}

void frutaBurbuja::setPosy(int value)
{
    posy = value;
}

frutaBurbuja::frutaBurbuja( QObject *parent): QObject(parent)
{
    //timerfrutaburbuja=new QTimer();
    //connect(timerfrutaburbuja,SIGNAL(timeout()),this,SLOT(actualizar_burbuja()));
   // timerfrutaburbuja->start(50);

    // dar posicion

    pixmap = new QPixmap(":/Imagenes/frutaburbuja.png");
    dy =0;
    ancho = 50;
    alto=50;

}


QRectF frutaBurbuja::boundingRect() const
{
    return QRectF(-ancho/2,-alto/2,ancho,alto);
}

void frutaBurbuja::paint(QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget *widget)
{
    painter->drawPixmap(-ancho/2,-alto/2,*pixmap,dy,0,ancho,alto);
}


void frutaBurbuja::sprite_burbuja()
{   dx=0;
    dy+=50;
    if(dy >= 50*6)
    {
        dy=0;
    }
    this->update(-ancho/2,-alto/2,ancho,alto);
}



