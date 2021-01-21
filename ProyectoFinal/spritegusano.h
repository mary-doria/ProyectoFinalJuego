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
    spritegusano(bool _bande, int x, int y);

    QTimer *timer;
    QPixmap *pixmap;

    float columna, fila;
    float ancho,alto;
    //aplicamos la funcion de los fantasmas del packman
    bool bande;// variable para el cambio de direccion
    int posx, posy;// variables x y y para las posiciones iniciales


    int getPosx() const;
    void setPosx(int px);
    int getPosy() const;
    void setPosy(int py);
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
