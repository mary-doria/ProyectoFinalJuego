#ifndef CUERPOPERSONAJEJUGADOR_H
#define CUERPOPERSONAJEJUGADOR_H
#include <QObject>
#include <QGraphicsItem>
#include <QTimer>
#include <QPixmap>
#include <QGraphicsPixmapItem>
#include <QPainter>
#include <QGraphicsScene>
#include <QKeyEvent>
#include <QDebug>

class CuerpoPersonajeJugador:public QObject ,public QGraphicsItem
{    //Q_OBJECT
    int posx, posy;
    float dx, dy;  //variables para controlar las filas y las columnas del sprite
    float ancho,alto;

    int velocidad =10;//
    float tiempo,friccion;
    int G;
    bool enTierra;
    bool saltando;

    QPixmap *pixmap; //variable pixmap
    QTimer *timer;//tiempo
    //Variable para movimiento hacia arriba:


public:
    //explicit CuerpoPersonajeJugador(QObject *parent = nullptr);
    CuerpoPersonajeJugador(int x, int y,int rickMorty);
    // posicion x y y
    int getPosx() const;
    void setPosx(int px);
    int getPosy() const;
    void setPosy(int py);
    QRectF boundingRect() const;// para dibujar el cuerpo
    void paint(QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget *widget = nullptr);
    void izquierda();//Movimiento lineal
    void  derecha();//Movimiento lineal
    void choque();

    bool getEnTierra() const;
    void setEnTierra(bool value);

    float getTiempo() const;
    void setTiempo(float value);

    bool getSaltando() const;
    void setSaltando(bool value);

signals:
public slots:
    void actualizar_sprite_derecha();   //funcion para actualizar el sprite para la derecha
    void actualizar_sprite_izquierda(); //funcion para actualizar el sprite para la izquierda
    void caidaLibre();//funcion para la caida libre de los personajes
    void saltar();
};

#endif // CUERPOPERSONAJEJUGADOR_H
