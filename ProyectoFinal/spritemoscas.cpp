#include "spritemoscas.h"
#include <math.h>
#include <cmath>
#include <QDebug>

spritemoscas::spritemoscas(bool bandera)
{
    alto=115;
    ancho=100;
    if(bandera==true){
    PX=950;//pos x
    VX=-20;// velo en x
    dy=0;

    }
    if(bandera==false){
    PX=50;//pos x
    VX=20;// velo en x
    dy=100;
    }

    PY=rand()%200;//pos y
    mass=5;//masa
    R=10; //radio

    VY=25; // velo en y
    angulo;
    AX=0;// acel en x
    AY=0; // acel en y
    g=1; //gravedad
    K=(rand()%10)/1000; // resistencia del aire
    //e=(0.5+(rand()%5)/10); // coeficiente de restitucion
    V=0; //vector de velocidad;
    dt=0.1; // delta de tiempo
    pixmap=new QPixmap(":/Imagenes/moscas_Izq_Der.png");
    setScale(0.5);

}

void spritemoscas::actualizarPosyVel()
{
    V = pow(((VX*VX)+(VY*VY)),(1/2));
    angulo = atan2(VY,VX);// arcotangente
    AX= -((K*(V*V)*(R*R))/mass)*cos(angulo);
    AY= (-((K*(V*V)*(R*R))/mass)*sin(angulo))-g;
    PX = PX + ((VX*(dt)))+(((AX*(dt*dt)))/2);
    PY = PY + ((VY*(dt)))+(((AY*(dt*dt)))/2);
    VX = VX + AX*dt;
    VY = VY + AY*dt;
}
QRectF spritemoscas::boundingRect() const
{
    // boundingrect, es donde se va a dibujar.
    return QRectF(-ancho/2,-alto/2,ancho,alto);
}

void spritemoscas::paint(QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget *widget)
{
    painter->drawPixmap(-ancho/2,-alto/2,*pixmap,dy,0,ancho,alto);

}

void spritemoscas::set_vel(float vx, float vy, float px, float py)
{
    VX=vx;
    VY=vy;
    PX=px;
    PY=py;
}

void spritemoscas::actual(float v_limit)
{
    this->actualizarPosyVel();
    setPos(this->getPX(),v_limit-this->getPY());
}

float spritemoscas::getPX() const
{
    return PX;
}

float spritemoscas::getPY() const
{
    return PY;
}

float spritemoscas::getMass() const
{
    return mass;
}

float spritemoscas::getR() const
{
    return R;
}

float spritemoscas::getVX() const
{
    return VX;
}

float spritemoscas::getVY() const
{
    return VY;
}

spritemoscas *spritemoscas::mosca()
{
    return mosca();
}

