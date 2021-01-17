#ifndef BALA_H
#define BALA_H
#include <QObject>
#include <QGraphicsItem>
#include <QTimer>
#include <QPixmap>

class bala : public QObject, public QGraphicsItem
{
    Q_OBJECT
public:
    bala(bool _bandera);
    bool bandera;
    QTimer *timer;
    QPixmap *pixmap;
    int getPosx() const;
    void setPosx(int value);
    QRectF boundingRect() const;// para dibujar el cuerpo
    void paint(QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget *widget = nullptr);
    int getPosy() const;
    void setPosy(int value);
    QTimer *timerrasholaser;

private:
    float dx, dy;  //variables para controlar las filas y las columnas del sprite
    float ancho,alto;
    int posx, posy;

signals:
public slots:
    void move();
    void sprite_rasholaser();

};

#endif // BALA_H
