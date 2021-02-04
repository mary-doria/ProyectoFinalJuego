#include "spritegusano.h"
#include <QPixmap>

spritegusano::spritegusano(QObject *parent) : QObject(parent)//constructor
{
    timer = new QTimer();//timer para sprite
    fila =0;//inicio la fila del sprite
    columna =0;//inicio de la columna del sprite
    pixmap = new QPixmap(":/imagen/gusanos_loks_sinFondo_cuadrado.png");//direccion del Qpixmap

    // dimensiones de las imagenes
    ancho =122;
    alto =122;
    timer->start(100);//timer del sprite
    connect(timer,&QTimer::timeout,this,&spritegusano::actualizacionGusano);//sprite para el gusano

}

spritegusano::spritegusano(bool _bande, int x, int y)//constructor sobre cargado de la clase
{
    posx = x;//posicion del objeto en x
    posy = y;//posicion del objeto en y
    bande = _bande;//bandera para el mov del gusano
    setPos(posx,posy);// posicion del enemigo.
    timer = new QTimer();//timer para el sprite
    fila =0;//fila para el sprite
    columna =0;//columna para el sprite
    pixmap = new QPixmap(":/Imagenes/gusanos_loks_sinFondo_cuadrado.png");//direccion del Qpixmap

    // dimensiones de las imagenes
    ancho =122;
    alto =122;
    timer->start(100);// timer del sprite
    connect(timer,&QTimer::timeout,this,&spritegusano::actualizacionGusano);//actualizar el sprite para el gusano


}
int spritegusano::getPosx() const
{
    return posx;//dar pos en x
}

void spritegusano::setPosx(int px)
{
    posx = px;//posicion actual X
}

int spritegusano::getPosy() const
{
    return posy;//dar la pos en y
}

void spritegusano::setPosy(int py)
{
    posy = py;//posicion actual Y
}

void spritegusano::left(int velocidad)
{
    posx -= 1*velocidad;//velocidad para el mov
    fila =190;//fila para el mov del gusano
    setPos(posx, posy);//posicion x y y del gusano
}

void spritegusano::right(int velocidad)
{

    posx += 1*velocidad;//velocidad para el mov
    fila =350;// fila para el mov del gusano
    setPos(posx, posy);//posicion x y y del gusano
}


void spritegusano::actualizacionGusano()
{
    columna += 122;//sumar columna para el moc del gusano
    if(columna >= 400){
        columna = 0;//reiniciar columna
    }
    this->update(-ancho/2,-alto/2,ancho,alto);//actualizar sprite

}

QRectF spritegusano::boundingRect() const
{
    return QRectF(-ancho/2,-alto/2,ancho,alto);
}

void spritegusano::paint(QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget *widget)
{
   painter->drawPixmap(-ancho/2,-alto/2,*pixmap,columna,fila,ancho,alto);

}
