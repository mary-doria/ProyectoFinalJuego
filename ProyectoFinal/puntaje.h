#ifndef PUNTAJE_H
#define PUNTAJE_H
#include <QGraphicsItem>

class Puntaje: public QGraphicsTextItem
{
public:
    Puntaje(QGraphicsItem *parent = nullptr);//Atributos de la clase puntaje
    void incrementar();//Funcion que incrementa los puntos
    int obtenerPuntos();//Funcion que guarda los puntos
    void reiniciarpuntos();//Funcion que convierte los puntos en 0
    void asignarPuntos(int puntos);//Funcion que asigna los puntos
private:
    int puntos;//Variable donde se guardan  los puntos
};

#endif // PUNTAJE_H
