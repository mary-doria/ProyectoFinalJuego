#ifndef FRUTABURBUJA_H
#define FRUTABURBUJA_H
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


class frutaBurbuja: public QObject, public QGraphicsItem
{//Q_OBJECT
public:
    /*frutaBurbuja(float x,int y);*/
    int posx, posy;
    explicit frutaBurbuja(QObject *parent = nullptr);
    float dx, dy;  //variables para controlar las filas y las columnas del sprite
    float ancho,alto;
    QPixmap *pixmap; //variable pixmap
    QTimer *timerfrutaburbuja;


    QRectF boundingRect() const;// para dibujar el cuerpo
    void paint(QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget *widget = nullptr);



    int getPosx() const;
    void setPosx(int value);

    int getPosy() const;
    void setPosy(int value);

public slots:
    void sprite_burbuja();
};

#endif // FRUTABURBUJA_H
