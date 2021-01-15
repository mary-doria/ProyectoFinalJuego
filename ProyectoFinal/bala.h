#ifndef BALA_H
#define BALA_H

#include <QObject>

class bala : public QObject
{
    Q_OBJECT
public:
    explicit bala(QObject *parent = nullptr);

signals:

};

#endif // BALA_H
