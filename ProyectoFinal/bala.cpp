#include "bala.h"
#include <QTimer>// para lo del connect
#include <QGraphicsScene>
#include <QDebug>
#include "spritegusano.h"
#include <mainwindow.h>

Score *score;
bala::bala(bool _bandera)
{//63x80

    dy =0;
    ancho = 64;
    alto=70;
    bandera=_bandera;
    //connect
 QTimer *timer = new QTimer;
 connect(timer,SIGNAL(timeout()),this,SLOT(move()));
 /* el connect solo funciona con los objetos macros esos que tiene el QObject y public QObject*/
 timer->start(50);// el tiempo en milisegundos
pixmap = new QPixmap(":/Imagenes/bala_verde_12.png");

setScale(0.5);
}
QRectF bala::boundingRect() const
{
    // boundingrect, es donde se va a dibujar.
    return QRectF(-ancho/2,-alto/2,ancho,alto);
}

void bala::paint(QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget *widget)
{
    painter->drawPixmap(-ancho/2,-alto/2,*pixmap,dy,0,ancho,alto);

}


int bala::getPosx() const
{
    return posx;
}

void bala::setPosx(int value)
{
    posx = value;
}

int bala::getPosy() const
{
    return posy;
}

void bala::setPosy(int value)
{
    posy = value;
}

void bala::move()
{ QList<QGraphicsItem *> colliding_items= collidingItems();
    for (int i=0; i < colliding_items.size();i++){
        if (typeid (*(colliding_items[i]))==typeid (spritegusano)){
            //score->increase();
            scene()->removeItem(colliding_items[i]);
            scene()->removeItem(this);
            //delete colliding_items[i];
            delete this;}}


if(bandera == true){
    setPos(x()+10,y());
    if(pos().x()+50>1200)
    {scene()->removeItem(this);
     delete  this; //eliminar de la memoria.
     //qDebug() << "se elimino";
    }}
    if(bandera == false){
    setPos(x()-10,y());
    if(pos().x()+50<0)
    {scene()->removeItem(this);
     delete  this; //eliminar de la memoria.
     //qDebug() << "se elimino";

    }}
    sprite_rasholaser();
}

void bala::sprite_rasholaser()
{
        //dx=0;
        dy+=70;
        if(dy >=70*4)
        {
            dy=0;
        }
        this->update(-ancho/2,-alto/2,ancho,alto);
}

