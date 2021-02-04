#ifndef PLATAFORMA_H
#define PLATAFORMA_H
#include <QGraphicsItem>
#include <QPainter>
#include <QPixmap>
#include <QTimer>


class Plataforma:public QObject, public QGraphicsItem//Se realiza herencia publica
{   int posx_, posy_;
    QPixmap *pixmapPlataforma; //variable pixmap

private:
    float dx,dy,ancho,alto;
public:
    Plataforma(int x,int y);//atributos que pose cada plataforma
    // para dibujar la plataforma
    QRectF boundingRect() const;
    void paint(QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget *widget = nullptr);
    //Posicion en y
    int posy() const;//Retorna un entero de la posicion en y
    void setPosy(int posy);//Actualiza la posicion en y
    //Posicion en x
    int posx() const;//Retorna un entero de la posicion en x
    void setPosx(int posx);//Actualiza la posicion en x
    //Ancho de la plataforma
    float getAncho() const;
    void setAncho(float value);
    //Alto de la plataforma
    float getAlto() const;
    void setAlto(float value);
};

#endif // PLATAFORMA_H
