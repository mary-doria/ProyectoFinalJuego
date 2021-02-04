#include "bala.h"
#include <QTimer>// para lo del connect
#include <QGraphicsScene>
#include <QDebug>
#include "spritegusano.h"
#include "spritemoscas.h"
#include <mainwindow.h>

//Score *score;
bala::bala(bool _bandera, QList<spritegusano*> listaGusanos,QList<spritemoscas*> listaMoscas)//constructor de la clase
{//63x80
    this->gusanos = listaGusanos;//Qlist de la clase gusano usada en esta clase
    this->moscas = listaMoscas;//Qlist de la clase mosca usada en esta clase
    dy =0;//posi de la fila del sprite
    ancho = 64;//dimencion del ancho del sprite
    alto=70;//dimencion del alto del sprite
    bandera=_bandera;//bandera de la clase para el mov de la bala
    //connect
 QTimer *timer = new QTimer;//timer de la clase
 connect(timer,SIGNAL(timeout()),this,SLOT(move()));//para conecter el quitimer con la funcion de slot del mov
 /* el connect solo funciona con los objetos macros esos que tiene el QObject y public QObject*/
 timer->start(30);// el tiempo en milisegundos para empezar el slot
pixmap = new QPixmap(":/Imagenes/bala_verde_12.png");//ruta de la imagen para implementarla en el pixmap

setScale(0.5);//scalamos la bala para el juego
}
QRectF bala::boundingRect() const
{
    // boundingrect, es donde se va a dibujar.
    return QRectF(-ancho/2,-alto/2,ancho,alto);
}

void bala::paint(QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget *widget)
{
    painter->drawPixmap(-ancho/2,-alto/2,*pixmap,dy,0,ancho,alto);//para realizar el dibujo del sprite

}


int bala::getPosx() const
{
    return posx;//posicion en x
}

void bala::setPosx(int value)
{
    posx = value;//posicion en x
}

int bala::getPosy() const
{
    return posy;//posicion en y
}

void bala::setPosy(int value)
{
    posy = value;//posicion en y
}


void bala::move()//funcion del slot para el mov. de la bala
{
    bool colisiona = false;//bandera para detectar colision
    QList<QGraphicsItem *> colliding_items= collidingItems();//se realiza una Qlist con los items de la scene
    for (int i=0; i < colliding_items.size();i++){//recorrer todos los items de la scena
        if (typeid (*(colliding_items.at(i)))==typeid (spritegusano) || typeid (*(colliding_items.at(i)))==typeid (spritemoscas)){//verificar la colision de la scena con las clases gusano y la clase mosca
            //score->increase();g
            scene()->removeItem(colliding_items.at(i));//remueve el items de la scena
            colisiona = true;//cambia la bandera que detecta la colision
            }
    }



if(bandera == true){//bandera de mov. para ver hacia donde se dirigir la bala
    setPos(x()+10,y());//posicion hacia donde se mov la bala
    if(pos().x()+50>1200)//limite para eliminar las balas
    {scene()->removeItem(this);//remover la bala del scenario
     delete  this; //eliminar de la memoria.
     //qDebug() << "se elimino";
    }}
    if(bandera == false){//bandera de mov de la bala
    setPos(x()-10,y());//posicion hacia donde se mov la bala
    if(pos().x()+50<0)//limite para eliminar las balas
    {scene()->removeItem(this);// remover de la scena
     delete  this; //eliminar de la memoria.
     //qDebug() << "se elimino";

    }}
    sprite_rasholaser();//sprite de la clase bala

    if(colisiona==true){//bandera para la deteccion de la colision
        scene()->removeItem(this);//remover de la scena si se detecta colision

        delete this;//eliminarla de la memoria
    }
}

void bala::sprite_rasholaser()//sprite del mov
{

        dy+=70;//aumenta el ancho del sprite
        if(dy >=70*4)//condicion para reiniciar el sprite
        {
            dy=0;
        }
        this->update(-ancho/2,-alto/2,ancho,alto);//actualizar el sprite
}

