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
    spritemoscas(bool bandera);
    void actualizarPosyVel();
    QRectF boundingRect() const;
    void paint(QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget *widget = nullptr) override;
     void set_vel(float vx, float vy, float px, float py);
     void actual(float v_limit);
     float getPX() const;
     float getPY() const;
     float getMass() const;
     float getR() const;
     float getVX() const;
     float getVY() const;
     float getE() const;
     spritemoscas *mosca();
     QTimer *timer;
     QPixmap *pixmap;
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
