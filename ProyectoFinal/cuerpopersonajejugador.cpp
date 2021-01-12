#include "cuerpopersonajejugador.h"
#include <QPixmap>
#include <QTimer>
#include <math.h>
#include <cmath>



/*CuerpoPersonajeJugador::CuerpoPersonajeJugador(QObject *parent)
{   timer = new QTimer();
    dx =4;
    dy =4;
    pixmap = new QPixmap(":/Imagenes/Morty.png");

    // dimensiones de las imagenes
    ancho =124;
    alto =160;
    timer->start(100);
    connect(timer,&QTimer::timeout,this,&CuerpoPersonajeJugador::caidaLibre);
}*/

CuerpoPersonajeJugador::CuerpoPersonajeJugador(int x, int y)
{
    posx=x;
    posy=y;
    // dar posicion
    setPos(posx,posy);
    pixmap = new QPixmap(":/Imagenes/Rick.png");
    dx = 4;
    dy =4;
    ancho = 124;
    alto=160;
    tiempo=1;
    G=5;
}



int CuerpoPersonajeJugador::getPosx() const
{
    return posx;
}

void CuerpoPersonajeJugador::setPosx(int value)
{
    posx = value;
}

int CuerpoPersonajeJugador::getPosy() const
{
    return posy;
}

void CuerpoPersonajeJugador::setPosy(int value)
{
    posy = value;
}

QRectF CuerpoPersonajeJugador::boundingRect() const
{
    // boundingrect, es donde se va a dibujar.
    return QRectF(-ancho/2,-alto/2,ancho,alto);
}

void CuerpoPersonajeJugador::paint(QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget *widget)
{
    painter->drawPixmap(-ancho/2,-alto/2,*pixmap,dy,dx,ancho,alto);

}

void CuerpoPersonajeJugador::caidaLibre()
{
    posy+=(this->velocidad*this->tiempo+((G*(this->tiempo*this->tiempo))/2));//Ecuacion caida libre
    tiempo+=0.1;
    setPos(posx,posy);
    this->update(-ancho/2,-alto/2,ancho,alto);//Actualizacion de la posicion en todo instante de tiempo
}

void CuerpoPersonajeJugador::izquierda()//MovimientoLineal
{
    posx -= 2*velocidad;
    setPos(posx,posy);
}

void CuerpoPersonajeJugador::derecha()//Movimiento Lineal
{
    posx += 2*velocidad;
    setPos(posx,posy);
}

void CuerpoPersonajeJugador::actualizar_sprite_derecha()
{
    dx=333;
    dy+=128;
    if(dy >=128*4)
    {
        dy=0;
    }
    this->update(-ancho/2,-alto/2,ancho,alto);


}


void CuerpoPersonajeJugador::actualizar_sprite_izquierda()
{
    dx=168;
    dy+=128;
    if(dy >= 128*4)
    {
        dy=0;
    }
    this->update(-ancho/2,-alto/2,ancho,alto);

}



