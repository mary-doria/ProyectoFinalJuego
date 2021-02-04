#include "cuerpopersonajejugador.h"
#include <QPixmap>
#include <QTimer>
#include <math.h>
#include <cmath>

//Retorna un booleano que permite afirma si el personaje colisiona o no con las plataformas
bool CuerpoPersonajeJugador::getEnTierra() const
{
    return enTierra;
}
//Actualizacion del valor del booleano ,este valor puede cambiar segun la condicion
void CuerpoPersonajeJugador::setEnTierra(bool value)
{
    enTierra = value;
}
//Retorna el valor del tiempo lo cual es una constante
float CuerpoPersonajeJugador::getTiempo() const
{
    return tiempo;
}
//Obtiene el valor del tiempo ,este segun la implementacion va actualizandose
void CuerpoPersonajeJugador::setTiempo(float value)
{
    tiempo = value;
}
//Retorna un booleano que permite afirma si el personaje esta en el aire o no.
bool CuerpoPersonajeJugador::getSaltando() const
{
    return saltando;
}
//Actulizacion del booleano segun la condiciones que se usen ,este valor varia
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
//Retorna el valor de la velocidad a la que se somete el personaje
int CuerpoPersonajeJugador::getVelocidad() const
{
    return velocidad;
}
//Actualizacion de la velocidad del personaje en sus movimientos:derecha ,izquierda y salto.
void CuerpoPersonajeJugador::setVelocidad(int value)
{
    velocidad = value;
}

float CuerpoPersonajeJugador::getAncho() const
{
    return ancho;
}

void CuerpoPersonajeJugador::setAncho(float value)
{
    ancho = value;
}

float CuerpoPersonajeJugador::getAlto() const
{
    return alto;
}

void CuerpoPersonajeJugador::setAlto(float value)
{
    alto = value;
}

CuerpoPersonajeJugador::CuerpoPersonajeJugador(int x, int y,int rickMorty)//Constructor que recibe como atributos la posicion x y y un valor entero que decide que personaje seleccionar
{ //Se usa this para indicar el objeto actual en el que se trabajo, esto para evitar confusiones con las variables locales y dar seguridad que se esta trabajando en esta
    this->posx=x;//Posicion en x del personaje
    this->posy=y;//Posicion en y del personaje
    // dar posicion
    setPos(posx,posy);
    //opcion 1 es Rick ,Opcion 2 es Morty
    if (rickMorty==1){//Se escoge el personaje Rick
    this->pixmap = new QPixmap(":/Imagenes/Rick.png");}
    else if(rickMorty==2)//Se escoge el personaje Morty
    this->pixmap = new QPixmap(":/Imagenes/Morty.png");
    //Distancia en x y y  a la que el personaje esta de la margen(sprite)
    this->dx = 4;
    this->dy =4;
    //Ancho y alto de la imagen del personaje(pixmap: en este caso cada imagen)
    this->ancho = 124;
    this->alto=160;
    //Tiempo inicial el cual el personaje esta defrente y estatico sobre una plataforma
    this->tiempo=0;
    //Gravedad del personaje
    this->G=1;
    //Booleano que indica si el personaje esta en tierra o no
    this->enTierra=true;
    //Booleano que indica si el personaje esta en el aire o no
    this->saltando = false;

}
//Retorna el valor de la posicion del personaje en el eje x
int CuerpoPersonajeJugador::getPosx() const
{
    return posx;
}
//Actualiza el valor de la posicion del personaje en el eje x
void CuerpoPersonajeJugador::setPosx(int value)
{
    posx = value;
}
//Retorna el valor de la posicion del personaje en el eje y
int CuerpoPersonajeJugador::getPosy() const
{
    return posy;
}
//Actualiza el valor de la posicion del personaje en el eje y
void CuerpoPersonajeJugador::setPosy(int value)
{
    posy = value;
}

QRectF CuerpoPersonajeJugador::boundingRect() const
{
    // Boundingrect, es donde se va a dibujar el personaje.
    return QRectF(-ancho/2,-alto/2,ancho,alto);
}

void CuerpoPersonajeJugador::paint(QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget *widget)
{   //Paint dibuja al personaje ,su imagen ,altura, ancho ,largo
    painter->drawPixmap(-ancho/2,-alto/2,*pixmap,dy,dx,ancho,alto);

}

void CuerpoPersonajeJugador::caidaLibre()
{   //Movimiento de Caida libre
    if(this->posy>450 ){
        enTierra=true;
        this->saltando = false;
        tiempo = 0;
    }
    //Se verifica si el personaje esta en el aire o no
    if (enTierra==false){
        if (saltando == true){
            posy+=(-(this->velocidad)+((G*(this->tiempo))));//Ecuacion caida libre
        } else{
            posy+=((G*(this->tiempo)));//Ecuacion caida libre
        }
        tiempo+=0.5; }//Incremento del tiempo
        //Se obtiene la posicion del personaje cuando se realizo el movimiento de caida libre
        setPos(posx,posy);
    this->update(-ancho/2,-alto/2,ancho,alto);//Actualizacion de la posicion en todo instante de tiempo

}
//Funcion que permite saltar al personaje si el tiempo es 0 esto quiere decir que esta tierra,si se confirma puede saltar de lo contrario no
void CuerpoPersonajeJugador::saltar()
{   //Funcion saltar
    if (this->tiempo == 0){
        this->tiempo = 1;
        posy-= this->velocidad*this->tiempo;//Formula de caida Libre
        this->saltando = true;//Se verifica si esta en el aire o no
    }
    //Se obtiene la posicion del personaje cuando se realizo el salto
      setPos(posx,posy);

}
//Movimiento Lineal hacia la izquierda
void CuerpoPersonajeJugador::izquierda()
{   if(posx>10){//Se limita el movimiento del personaje en la escena
    posx -= (velocidad/2);
    setPos(posx,posy);}
}
//Movimiento Lineal hacia la derecha
void CuerpoPersonajeJugador::derecha()
{   if(posx<940){//Se limita el movimiento del personaje en la escena
    posx += (velocidad/2);
    setPos(posx,posy);}
}
//Funcion que verifica si el personaje esta en tierra a traves del booleano enTierra
void CuerpoPersonajeJugador::choque()
{
    enTierra=true;
    this->saltando = false;
    tiempo = 0;
}
//Se actualiza recorre el sprite como una matriz 3x4 tanto para la izquierda como derecha
//Estas cantidades estan en Pixeles
void CuerpoPersonajeJugador::actualizar_sprite_derecha()
{   //Se recorre la matriz y se varia dy de a 128 pixeles para que el personaje se vea caminando
    //dx es estatico dado que solo recorre la tercera fila
    dx=333;
    dy+=128;
    if(dy >=128*4)
    {
        dy=0;
    }
    this->update(-ancho/2,-alto/2,ancho,alto);//Se actualiza la aparicion del personaje en pantalla
}

void CuerpoPersonajeJugador::actualizar_sprite_izquierda()
{
    //Se recorre la matriz y se varia dy de a 128 pixeles para que el personaje se vea caminando
    //dx es estatico dado que solo recorre la segunda fila
    dx=168;
    dy+=128;
    if(dy >= 128*4)
    {
        dy=0;
    }
    this->update(-ancho/2,-alto/2,ancho,alto);//Se actualiza la aparicion del personaje en pantalla

}



