#include "plataforma.h"
#include <QPixmap>
#include <QTimer>


//Retorna el valor de la posicion de la nave en el eje y
int Plataforma::posy() const
{
    return posy_;
}
//Actualiza el valor de la posicion de la nave en el eje y
void Plataforma::setPosy(int posy)
{
    posy_ = posy;
}
//Retorna el valor de la posicion de la nave en el eje x
int Plataforma::posx() const
{
    return posx_;
}
//Actualiza el valor de la posicion de la nave en el eje x
void Plataforma::setPosx(int posx)
{
    posx_ = posx;
}
//Retorna el ancho de la nave
float Plataforma::getAncho() const
{
    return ancho;
}
//Actualiza el ancho de la nave
void Plataforma::setAncho(float value)
{
    ancho = value;
}
//Retorna el Alto de la nave
float Plataforma::getAlto() const
{
    return alto;
}
//Retorna el Alto de la nave
void Plataforma::setAlto(float value)
{
    alto = value;
}

Plataforma::Plataforma(int x, int y)//Constructor que recibe como atributos la posicion x y
{
    this->posx_=x;//Posicion de la plataforma en x
    this->posy_=y;//Posicion de la plataforma en y
    // dar posicion
    setPos(posx_,posy_);
    this->pixmapPlataforma = new QPixmap(":/Imagenes/PlataformaEscenario2.png");//Pixmap:Imagen de la plataforma
    this->dx = 0;//Distancia de la plataforma de la margen en x
    this->dy =0;//Distancia de la plataforma de la margen en y
    this->ancho = 145;//Ancho de la plataforma
    this->alto=40;//Alto de la plataforma


}
// Boundingrect, es donde se va a dibujar la plataforma
QRectF Plataforma::boundingRect() const
{
    return QRectF(-ancho/2,-alto/2,ancho,alto);

}
//Paint dibuja la plataforma ,su imagen ,altura, ancho y largo
void Plataforma::paint(QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget *widget)
{
 painter->drawPixmap(-ancho/2,-alto/2,*pixmapPlataforma,dx,dy,ancho,alto);
}
