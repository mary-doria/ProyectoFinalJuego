#ifndef SCORE_H
#define SCORE_H


#include <QGraphicsTextItem>
class Score: public QGraphicsTextItem/* al hacer esta herencia no se ahorra memoria
       debido aque se cargar las funciones de QGrapTExTitem pero permite la simplicidad*/
{
public:
    Score(QGraphicsItem *parent = 0);
    void increase();
    int getScore();
private:
    int score;

};

#endif // SCORE_H
