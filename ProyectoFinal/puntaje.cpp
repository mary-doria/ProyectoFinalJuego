#include "puntaje.h"
#include <QFont>

Puntaje::Puntaje(QGraphicsItem * padre): QGraphicsTextItem(padre)
{
    puntos=0;
    setPlainText(QString("Puntaje: ")+ QString::number(puntos));
    setDefaultTextColor(Qt::white);
    setFont(QFont("times new roman",18));
}

void Puntaje::incrementar()
{
    puntos+=100;
    setPlainText(QString("Puntaje: ")+ QString::number(puntos));
}

int Puntaje::obtenerPuntos()
{
    return puntos;
}

void Puntaje::reiniciarpuntos()
{
    puntos=0;

}

void Puntaje::asignarPuntos(int puntos)
{
    this->puntos=puntos;

}
