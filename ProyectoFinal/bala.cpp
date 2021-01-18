#include "bala.h"
#include <QTimer>// para lo del connect
#include <QGraphicsScene>
#include <QDebug>
#include "spritegusano.h"
#include <mainwindow.h>


bala::bala(bool _bandera)
{
    bandera=_bandera;
    //connect
 QTimer *timer = new QTimer;
 connect(timer,SIGNAL(timeout()),this,SLOT(move()));
 /* el connect solo funciona con los objetos macros esos que tiene el QObject y public QObject*/
 timer->start(50);// el tiempo en milisegundos

setPixmap(QPixmap(":/Imagenes/bala_verde_12.png"));
setScale(0.5);
}

void bala::move()
{ QList<QGraphicsItem *> colliding_items= collidingItems();
    for (int i=0; i < colliding_items.size();i++){
        if (typeid (*(colliding_items[i]))==typeid (spritegusano)){
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
}
