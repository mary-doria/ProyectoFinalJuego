#ifndef VIDA_H
#define VIDA_H


#include <QGraphicsTextItem>
class Vida: public QGraphicsTextItem/* al hacer esta herencia no se ahorra memoria
       debido aque se cargar las funciones de QGrapTExTitem pero permite la simplicidad*/
{
public:
    Vida(QGraphicsItem *parent = 0);
    void decrease();
    int getVida();
private:
    int vida;

};
#endif // VIDA_H
