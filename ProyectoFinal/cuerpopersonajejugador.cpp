#include "cuerpopersonajejugador.h"
#include <QPixmap>
#include <QTimer>
#include <math.h>
#include <cmath>


bool CuerpoPersonajeJugador::getEnTierra() const
{
    return enTierra;
}

void CuerpoPersonajeJugador::setEnTierra(bool value)
{
    enTierra = value;
}

float CuerpoPersonajeJugador::getTiempo() const
{
    return tiempo;
}

void CuerpoPersonajeJugador::setTiempo(float value)
{
    tiempo = value;
}

bool CuerpoPersonajeJugador::getSaltando() const
{
    return saltando;
}

void CuerpoPersonajeJugador::setSaltando(bool value)
{
    saltando = value;
}

bool CuerpoPersonajeJugador::getPlataformaNave() const
{
    return plataformaNave;
}

void CuerpoPersonajeJugador::setPlataformaNave(bool value)
{
    plataformaNave = value;
}

CuerpoPersonajeJugador::CuerpoPersonajeJugador(int x, int y,int rickMorty)
{ //Se usa this para indicar el objeto actual en el que se trabaj esto para evitar confusiones con las variables locales y dar seguridad que se esta trabajando en esta
    this->posx=x;
    this->posy=y;
    // dar posicion
    setPos(posx,posy);
    //opcion 1 es Rick ,Opcion 2 es Morty
    if (rickMorty==1){
    this->pixmap = new QPixmap(":/Imagenes/Rick.png");}
    else if(rickMorty==2)
    this->pixmap = new QPixmap(":/Imagenes/Morty.png");
    this->dx = 4;
    this->dy =4;
    this->ancho = 124;
    this->alto=160;
    this->tiempo=0;
    this->G=1;
    this->enTierra=false;
    this->saltando = false;

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

    if(this->posy>450 ){
        enTierra=true;
        this->saltando = false;
        tiempo = 0;
    }



    if (enTierra==false){
        if (saltando == true){
            posy+=(-(this->velocidad)+((G*(this->tiempo))));//Ecuacion caida libre
        } else{
            posy+=((G*(this->tiempo)));//Ecuacion caida libre
        }
        tiempo+=0.5; }
    /*posy+=(this->velocidad*this->tiempo+((G*(this->tiempo*this->tiempo))/2));//Ecuacion caida libre
    tiempo+=0.1;*/
        setPos(posx,posy);

    this->update(-ancho/2,-alto/2,ancho,alto);//Actualizacion de la posicion en todo instante de tiempo

}

void CuerpoPersonajeJugador::saltar()
{   if (this->tiempo == 0){
        this->tiempo = 1;
        posy-= this->velocidad*this->tiempo;
        this->saltando = true;
    }
      setPos(posx,posy);

}

void CuerpoPersonajeJugador::izquierda()//MovimientoLineal
{   if(posx>10){
    posx -= (velocidad/2);
    setPos(posx,posy);}
}

void CuerpoPersonajeJugador::derecha()//Movimiento Lineal
{   if(posx<940){
    posx += (velocidad/2);
    setPos(posx,posy);}
}

void CuerpoPersonajeJugador::choque()
{
    /*posy-=(this->velocidad*this->tiempo+((0*(this->tiempo*this->tiempo))/2));//Ecuacion caida libre
    setPos(posx,posy);*/

    enTierra=true;
    this->saltando = false;
    tiempo = 0;
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



