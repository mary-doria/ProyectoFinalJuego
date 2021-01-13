#ifndef PLATAFORMA_H
#define PLATAFORMA_H
#include <QGraphicsItem>
#include <QPainter>
#include <QPixmap>
#include <QTimer>


class Plataforma:public QObject, public QGraphicsItem
{   int posx_, posy_;
    QPixmap *pixmapPlataforma; //variable pixmap
private:
    float dx,dy,ancho,alto;
public:
    Plataforma(int x,int y);//atributos que pose cada plataforma
    // para dibujar la plataforma
    QRectF boundingRect() const;
    void paint(QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget *widget = nullptr);
    int posy() const;
    void setPosy(int posy);
    int posx() const;
    void setPosx(int posx);
};

#endif // PLATAFORMA_H
