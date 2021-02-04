#ifndef NAVE_H
#define NAVE_H
#include <QPixmap>
#include <QGraphicsItem>
#include <QPainter>


class nave:public QObject, public QGraphicsItem

{
    int posx,posy;//Posicion en x y y de la nave
    private:
    int dx,dy,ancho,alto;
    QPixmap *pixmapnave;//pixmap:Imagen de la nave
    public:
    nave(int x,int y);//Atributos que pose la nave
    //Posicion en x
    int getPosx() const;//Retorna un entero de la posicion en x
    void setPosx(int value);//Actualizar un entero de la posicion en x
    //Posicion en y
    int getPosy() const;//Retorna un entero de la posicion en y
    void setPosy(int value);//Actualizar un entero de la posicion en y
    QRectF boundingRect() const;// para dibujar el cuerpo
    void paint(QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget *widget = nullptr);
};

#endif // NAVE_H
