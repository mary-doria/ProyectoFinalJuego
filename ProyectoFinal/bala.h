#ifndef BALA_H
#define BALA_H

#include <QObject>
#include <QGraphicsPixmapItem>
#include <QTimer>
#include <QPixmap>

class bala : public QObject, public QGraphicsPixmapItem
{
    Q_OBJECT
public:
    bala();
    QTimer *timer;
    QPixmap *pixmap;

signals:
public slots:
    void move();

};

#endif // BALA_H
