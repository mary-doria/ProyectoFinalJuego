#ifndef VIDA_H
#define VIDA_H
#include <QObject>
#include <QGraphicsItem>
#include <QTimer>
#include <QPixmap>
#include <QPainter>
#include <QGraphicsScene>
#include <QMainWindow>
#include <QObject>
#include <QWidget>

class Vida: public QObject, public QGraphicsItem//se hace este cambio porque la vida sera un icono ,no un texto
{

public:
    Vida(QObject *parent = nullptr);
    void decremento();
    int getVida();
    QPixmap *pixmapVidaCerveza;
    QRectF boundingRect() const;// para dibujar el cuerpo
    void paint(QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget *widget = nullptr);
private:
    int vida;

};
#endif // VIDA_H
