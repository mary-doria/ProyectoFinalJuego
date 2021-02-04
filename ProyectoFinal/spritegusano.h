#ifndef SPRITEGUSANO_H
#define SPRITEGUSANO_H

#include <QObject>
#include <QGraphicsItem>
#include <QTimer>
#include <QPixmap>
#include <QGraphicsPixmapItem>
#include <QPainter>
#include <QGraphicsScene>

class spritegusano : public QObject, public QGraphicsItem
{

    Q_OBJECT

public:
    explicit spritegusano(QObject *parent = nullptr);
    spritegusano(bool _bande, int x, int y);//constructor de la clase

    QTimer *timer;//timer para la el mov. del sprite
    QPixmap *pixmap;//pixmal para el sprite

    float columna, fila;//fila y columna que usaremos en el sprite
    float ancho,alto;//fila y columna para el sprite
    //aplicamos la funcion de los fantasmas del packman
    bool bande;// variable para el cambio de direccion
    int posx, posy;// variables x y y para las posiciones iniciales


    int getPosx() const;//posicion actual x
    void setPosx(int px);//posicion del cuerpo en x
    int getPosy() const;//posicion actual y
    void setPosy(int py);//posicion del cuerpo en y
    void left(int velocidad);// mov izqueirda
    void right(int velocidad);// mov derecha


    // para graficar el objeto
    QRectF boundingRect() const;
    void paint(QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget *widget = nullptr);


signals:

public slots:
    void actualizacionGusano();// actualizacion del prite

};

#endif // SPRITEGUSANO_H
