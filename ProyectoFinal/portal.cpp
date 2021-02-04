#include "portal.h"


//Retorna el valor de la posicion en y del portal
float Portal::getPosy() const
{
    return posy;
}
//Actualiza posicion en y del portal
void Portal::setPosy(float value)
{
    posy = value;
}
//Retorna el valor posicion en x del portal
float Portal::getPosx() const
{
    return posx;
}
//Actualiza posicion en x del portal
void Portal::setPosx(float value)
{
    posx = value;
}
//Retorna velocidad en x del portal
float Portal::getVelX() const
{
    return velX;
}
//Actualiza velocidad en x del portal
void Portal::setVelX(float value)
{
    velX = value;
}
//Retorna velocidad en y del portal
float Portal::getVelY() const
{
    return velY;
}
//Actualiza velocidad en y del portal
void Portal::setVelY(float value)
{
    velY = value;
}
// Boundingrect, es donde se va a dibujar al portal
QRectF Portal::boundingRect() const
{
    return QRectF(-ancho/2,-alto/2,ancho,alto);
}
//Paint dibuja al portal ,su imagen ,altura, ancho y largo
void Portal::paint(QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget *widget)
{
    painter->drawPixmap(-ancho/2,-alto/2,*pixmapPortal,dy,dx,ancho,alto);

}

Portal::Portal(float x,float y,float vx ,float vy)
{   //Posicion en x y y del portal
    this->posx=x;
    this->posy=y;
    //Distancia en x y y del portal con la margen
    this->dx = 4;
    this->dy =4;
    //Ancho y alto de la imagen del portal
    this->ancho = 124;
    this->alto=160;
    //Contador
    this->contadorPos=0;
    //Velocidad en x y y del portal
    this->velX = vx;
    this->velY = vy;
    //Posicion inicial la cual no variara
    this->posyInicial=y;
    pixmapPortal = new QPixmap(":/Imagenes/portalrickandmorty.png");//Pixmap:Imagen del portal
    //Actualizacion de la posicion del portal
    setPos(posx,posy);
}

void Portal::ActualizarPosicionPortal()
{
        if(this->posx>960 || this->posx<40)//Se limite el movimiento del portal en la escena
        {
        velX=-velX;
        }
        this->posx = (posx - velX*delta);//Posicion en x del portal
        this->contadorPos= contadorPos + delta;//x=La distancia que recorre la onda
        this->posy=30*sin(2*3.1415*contadorPos/2)+posyInicial;//Posicion en y del portal,Formula del movimiento senosoidal
        setPos(posx,posy);//Actualizacion de la poscion en x y y

}





