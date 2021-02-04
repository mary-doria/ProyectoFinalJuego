#ifndef SPRITEMOSCAS_H
#define SPRITEMOSCAS_H
#include <QObject>
#include <QPainter>
#include <QGraphicsItem>
#include <QGraphicsScene>
#include <stdlib.h>
#include <time.h>
#include <QGraphicsPixmapItem>
#include <QTimer>
#include <QPixmap>

class spritemoscas:public QObject, public QGraphicsItem
{
    Q_OBJECT
public:
    spritemoscas(bool bandera);//constructor de la clase
    void actualizarPosyVel();//actualizarla posicion y la velocidad de la clase
    QRectF boundingRect() const;//para dibujar
    void paint(QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget *widget = nullptr) override;//para dibujar al sprite
     void set_vel(float vx, float vy, float px, float py);//dar parameros de posicon x,y y de velodad en x y y
     void actual(float v_limit);//parametros actual
     float getPX() const;//dar pos x
     float getPY() const;//dar pos y
     float getMass() const;//dar masa
     float getR() const;//radio
     float getVX() const;//velocidad en x
     float getVY() const;//velocidad en y
     float getE() const;//coeficiente
     spritemoscas *mosca();//puntero de la clase mosca
     QTimer *timer;//timer de para la clase
     QPixmap *pixmap;//pixmap para el sprite de las moscas
private:
     float PX;//pos x
    float PY;//pos y
    float mass;//masa
    float R; //radio
    float VX;// velo en x
    float VY; // velo en y
    float angulo;
    float AX;// acel en x
    float AY; // acel en y
    float g; //gravedad
    float K; // resistencia del aire
    float V; //vector de velocidad;
    float dt; // delta de tiempo
    //pixmap
    int ancho;
    int alto;
    int dy;

};

#endif // spritemoscas_H
