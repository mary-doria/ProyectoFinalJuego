#ifndef NAVE_H
#define NAVE_H
#include <QPixmap>
#include <QGraphicsItem>
#include <QPainter>


class nave:public QObject, public QGraphicsItem

{ int posx,posy;
  QPixmap *pixmapnave;
private:
  int dx,dy,ancho,alto;
public:
    nave(int x,int y);
    int getPosx() const;
    void setPosx(int value);
    int getPosy() const;
    void setPosy(int value);
    QRectF boundingRect() const;// para dibujar el cuerpo
    void paint(QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget *widget = nullptr);
};

#endif // NAVE_H
