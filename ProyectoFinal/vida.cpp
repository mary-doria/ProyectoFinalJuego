#include "vida.h"
#include <QFont>


Vida::Vida(QGraphicsItem *parent): QGraphicsTextItem(parent)
{
    vida =0;
    setPlainText(QString("Vida: ")+ QString::number(vida));
    setDefaultTextColor(Qt::blue);
    setFont(QFont("times",16));
}

void Vida::increase()
{
    vida++;
    setPlainText(QString("Vida: ")+ QString::number(vida));
}

int Vida::getVida()
{
    return vida;
}
