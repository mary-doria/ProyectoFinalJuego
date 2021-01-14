#ifndef FRUTA_H
#define FRUTA_H
#include <QObject>
#include <QGraphicsItem>
#include <QTimer>
#include <QPixmap>
#include <QGraphicsPixmapItem>
#include <QPainter>
#include <QGraphicsScene>




class fruta
{
    int posx, posy;
    //float dx, dy;
    float ancho,alto;
    QPixmap *pixmapfruta1,*pixmapfruta2,*pixmapfruta3,*pixmapfruta4;
public:
    fruta(int  x,int  y);
    int getPosx() const;
    void setPosx(int value);
    int getPosy() const;
    void setPosy(int value);
    QRectF boundingRect() const;// para dibujar el cuerpo
    void paint(QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget *widget = nullptr);
};

#endif // FRUTA_H
