#ifndef BALA_H
#define BALA_H
#include <QObject>
#include <QGraphicsItem>
#include <QTimer>
#include <QPixmap>
#include "spritegusano.h"
#include "spritemoscas.h"

class bala : public QObject, public QGraphicsItem
{
    Q_OBJECT
public:
    bala(bool _bandera, QList<spritegusano*> listaGusanos,QList<spritemoscas*> listaMoscas);// constructor de la clase bala
    bool bandera;//bandera para verificar hacia donde se movera la bala
    QTimer *timer;//Qtimer para el sprite
    QPixmap *pixmap;// Pixmap para el sprite
    int getPosx() const;// posicion en x donde esta la bala
    void setPosx(int value);//posicion en x donde iniciara la bala
    QRectF boundingRect() const;// para dibujar el cuerpo
    void paint(QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget *widget = nullptr);//para dibujar
    int getPosy() const;// posicion en y donde esta la bala
    void setPosy(int value);//posicion en y donde iniciara la bala
    QTimer *timerrasholaser;//Qtimer para el sprite
    QList<spritegusano*> gusanos; //Qlist donde se encontraran los gusanos de la clase gusano
    QList<spritemoscas*> moscas;//Qlist donde se encontraran las moscas de la clase mosca


private:
    float dx, dy;  //variables para controlar las filas y las columnas del sprite
    float ancho,alto;//ancho y alto para el sprite
    int posx, posy;//variables enteras para la posicion x y y
signals:
public slots: //funciones slot para el sprite y para el movimiento de la bala
    void move();//funcion que permite el mov. de la bala
    void sprite_rasholaser();//fucion que realiza el sprite de la bala

};

#endif // BALA_H
