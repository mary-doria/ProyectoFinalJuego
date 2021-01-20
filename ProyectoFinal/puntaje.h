#ifndef PUNTAJE_H
#define PUNTAJE_H
#include <QGraphicsItem>

class Puntaje: public QGraphicsTextItem
{
public:
    Puntaje(QGraphicsItem *parent = nullptr);
    void incrementar();
    int obtenerPuntos();
private:
    int puntos;
};

#endif // PUNTAJE_H
