#ifndef VIDA_H
#define VIDA_H
#include <QObject>
#include <QGraphicsItem>
#include <QTimer>
#include <QPixmap>
#include <QGraphicsPixmapItem>
#include <QPainter>
#include <QGraphicsScene>
#include <QMainWindow>
#include <QObject>
#include <QWidget>

class Vida: public QObject, public QGraphicsItem
{int posx,posy;
    QPixmap *pixmapVidaCerveza;
  private:
    int dx,dy,ancho,alto;
  public:
      Vida(int x,int y);
      int getPosx() const;
      void setPosx(int value);
      int getPosy() const;
      void setPosy(int value);
      QRectF boundingRect() const;// para dibujar el cuerpo
      void paint(QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget *widget = nullptr);
  };


#endif // VIDA_H
