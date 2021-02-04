#include "nave.h"


//Retorna el valor de la posicion de la nave en el eje y
int nave::getPosy() const
{
    return posy;
}
//Actualiza el valor de la posicion de la nave en el eje y
void nave::setPosy(int value)
{
    posy = value;
}
// Boundingrect, es donde se va a dibujar a la nave
QRectF nave::boundingRect() const
{
    return QRectF(-ancho/2,-alto/2,ancho,alto);
}
//Paint dibuja a la nave ,su imagen ,altura, ancho y largo
void nave::paint(QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget *widget)
{
    painter->drawPixmap(-ancho/2,-alto/2,*pixmapnave,dx,dy,ancho,alto);
}
//Retorna el valor de la posicion de la nave en el eje x
int nave::getPosx() const
{
    return posx;
}
//Actualiza el valor de la posicion de la nave en el eje x
void nave::setPosx(int value)
{
    posx = value;
}

nave::nave(int x, int y)//Constructor de la nave que recibe la posicion x y y
{
    this->posx=x;//Posicion en x de la nave
    this->posy=y;//Posicion en y de la nave
    this->dx = 0;//Distancia en x de la nave
    this->dy =0;//Distancia en y de la nave
    this->pixmapnave=new QPixmap(":/Imagenes/uforickandmorty.png");//Pixmap:Imagen de la nave
    this->ancho=300;//Ancho de la imagen de la nave
    this->alto=234;//Alto de la imagen de la nave
    setPos(posx,posy);//La posicion del objeto en todo instante

}

