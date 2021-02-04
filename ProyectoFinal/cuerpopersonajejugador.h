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

class CuerpoPersonajeJugador:public QObject ,public QGraphicsItem//Se realiza herencia publica
{
    int posx, posy;//variable posicion x y y del personajeJugador
    int velocidad =10;//variable velocidad personajeJugador
    int G;//Gravedad
    float dx, dy;  //variables para controlar las filas y las columnas del sprite
    float ancho,alto;//Ancho y alto de la imagen del personaje
    float tiempo;//Tiempo
    bool enTierra;//Booleano que indica si esta en tierra o no
    bool saltando;//Booleano que indica si esta saltando o no
    bool plataformaNave;

    QPixmap *pixmap; //Pixmap:IMAGEN PERSONAJE
    QTimer *timer;//Timer Tiempo
public:
    //explicit CuerpoPersonajeJugador(QObject *parent = nullptr);
    CuerpoPersonajeJugador(int x, int y,int rickMorty);//Atributos que pose el personaje
    // Posicion en x
    int getPosx() const;//Retorna un entero de la posicion en x
    void setPosx(int px);//Actualiza la posicion en x
    // Posicion en y
    int getPosy() const;//Retorna un entero de la posicion en y
    void setPosy(int py);//Actualiza la posicion en y
    QRectF boundingRect() const;// para dibujar el cuerpo
    void paint(QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget *widget = nullptr);
    void izquierda();//Movimiento lineal
    void  derecha();//Movimiento lineal
    void choque();//Choque del personaje con el suelo
    //Booleano que indica si esta en tierra o no
    bool getEnTierra() const;//Retorna su valor
    void setEnTierra(bool value);//Actualiza su valor
    //Valor entero del tiempo
    float getTiempo() const;//Retorna su valor
    void setTiempo(float value);//Actualiza su valor
    //Booleano que indica si esta en el aire o no
    bool getSaltando() const;//Retorna su valor
    void setSaltando(bool value);//Actualiza su valor

    bool getPlataformaNave() const;//Retorna su valor
    void setPlataformaNave(bool value);//Actualiza su valor
    //Valor entero de la velocidad
    int getVelocidad() const;//Retorna su valor
    void setVelocidad(int value);//Actualiza su valor
    //Ancho del pixmap
    float getAncho() const;//Retorna su valor
    void setAncho(float value);//Actualiza su valor
    //Alto del pixmap
    float getAlto() const;//Retorna su valor
    void setAlto(float value);//Actualiza su valor

signals:
public slots:
    void actualizar_sprite_derecha();   //Funcion para actualizar el sprite para la derecha
    void actualizar_sprite_izquierda(); //Funcion para actualizar el sprite para la izquierda
    void caidaLibre();//Funcion para la caida libre de los personajes
    void saltar();//Funcion para el salto de los personajes
};

#endif // CUERPOPERSONAJEJUGADOR_H
