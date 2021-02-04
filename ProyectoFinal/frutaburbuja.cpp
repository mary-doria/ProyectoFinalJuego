#include "frutaburbuja.h"


//Retorna el valor de la posicion de la frutaburbuja en el eje x
int frutaBurbuja::getPosx() const
{
    return posx;
}
//Actualiza el valor de la posicion del personaje en el eje x
void frutaBurbuja::setPosx(int value)
{
    posx = value;
}
//Retorna el valor de la posicion de la frutaburbuja en el eje y
int frutaBurbuja::getPosy() const
{
    return posy;
}
//Actualiza el valor de la posicion de la frutaburbuja en el eje y
void frutaBurbuja::setPosy(int value)
{
    posy = value;
}

frutaBurbuja::frutaBurbuja( QObject *parent): QObject(parent)
{
    pixmap = new QPixmap(":/Imagenes/frutaburbuja.png");
    dy =0;
    ancho = 50;//Ancho del pixmap
    alto=50;//Alto del pixmap

}

// Boundingrect, es donde se va a dibujar a la frutaburbuja
QRectF frutaBurbuja::boundingRect() const
{
    return QRectF(-ancho/2,-alto/2,ancho,alto);
}
//Paint dibuja a la frutaburbuja ,su imagen ,altura, ancho y largo
void frutaBurbuja::paint(QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget *widget)
{
    painter->drawPixmap(-ancho/2,-alto/2,*pixmap,dy,0,ancho,alto);
}

//Sprite de la fruta burbuja que recorre la imagen como una matriz de 1x6
void frutaBurbuja::sprite_burbuja()
{   dx=0;
    dy+=50;//Varia dy porque la imagen de recorre hacia la derecha por esto es una sumatoria de posiciones
    if(dy >= 50*6)
    {
        dy=0;
    }
    this->update(-ancho/2,-alto/2,ancho,alto);//Actualizacion de la imagen
}



