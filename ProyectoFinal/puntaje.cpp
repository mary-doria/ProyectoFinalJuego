#include "puntaje.h"
#include <QFont>


Puntaje::Puntaje(QGraphicsItem * padre): QGraphicsTextItem(padre)
{   //Se crea el puntaje en pantalla como un texto
    puntos=0;
    setPlainText(QString("Puntaje: ")+ QString::number(puntos));//Puntaje en pantalla como texto y conversion del los numeros en string
    setDefaultTextColor(Qt::white);//Color de puntaje que aparecen en la escena
    setFont(QFont("times new roman",18));//Tipo de letra que tiene puntaje en escena
}

void Puntaje::incrementar()
{
    puntos+=100;//Puntaje incrementa 100 puntos a medida que colisiona con frutaburbujas y mata gusanos
    setPlainText(QString("Puntaje: ")+ QString::number(puntos));
}
//Funcion que obtiene los puntos que lleva el personaje
int Puntaje::obtenerPuntos()
{
    return puntos;
}
//Funcion que sirve para cambiar el sistema de puntaje a 0
void Puntaje::reiniciarpuntos()
{
    puntos=0;

}
//Se guardan los puntos
void Puntaje::asignarPuntos(int puntos)
{
    this->puntos=puntos;

}
