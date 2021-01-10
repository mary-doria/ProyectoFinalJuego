#include "cuerpopersonajejugador.h"
#include <QPixmap>
#include <QTimer>
CuerpoPersonajeJugador::CuerpoPersonajeJugador(int x, int y)
{
    posx=x;
    posy=y;
    // dar posicion
    setPos(posx,posy);
    pixmap = new QPixmap(":/Imagenes/Morty.png");
    dx = 0;
    dy =0;
    ancho = 66;
    alto=100;
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

/*void CuerpoPersonajeJugador::arriba()
{
    posy -= 2*velocidad;
    setPos(posx,posy);
}

void CuerpoPersonajeJugador::abajo()
{
    posy += 2*velocidad;
    setPos(posx,posy);
}*/

void CuerpoPersonajeJugador::izquierda()//MovimientoLineal
{
    posx -= 2*velocidad;
    setPos(posx,posy);
}
/*void CuerpoPersonajeJugador::arriba()
{
    posx -= 2*velocidad;
    setPos(posx,posy);
}*/
void CuerpoPersonajeJugador::derecha()//Movimiento Lineal
{
    posx += 2*velocidad;
    setPos(posx,posy);
}

void CuerpoPersonajeJugador::actualizar_sprite_derecha()
{
    dx=170;
    dy+=100;
    if(dy >=300)
    {
        dy=0;
    }
    this->update(-ancho/2,-alto/2,ancho,alto);


}

void CuerpoPersonajeJugador::actualizar_sprite_izquierda()
{
    dx=80;
    dy+=100;
    if(dy >= 300)
    {
        dy=0;
    }
    this->update(-ancho/2,-alto/2,ancho,alto);

}



