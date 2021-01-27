#ifndef PUNTAJE_H
#define PUNTAJE_H
#include <QGraphicsItem>

class Puntaje: public QGraphicsTextItem
{
public:
    Puntaje(QGraphicsItem *parent = nullptr);
    void incrementar();
    int obtenerPuntos();
    void reiniciarpuntos();
private:
    int puntos;
};

#endif // PUNTAJE_H
