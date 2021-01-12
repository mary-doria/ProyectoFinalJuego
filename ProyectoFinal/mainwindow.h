#ifndef MAINWINDOW_H
#define MAINWINDOW_H
#include <QMainWindow>
#include <cuerpopersonajejugador.h>
#include <QList>
#include "spritegusano.h"




QT_BEGIN_NAMESPACE
namespace Ui { class MainWindow; }
QT_END_NAMESPACE

class MainWindow : public QMainWindow
{
    Q_OBJECT


public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();

private:
    Ui::MainWindow *ui;
    CuerpoPersonajeJugador *PersonajePrincipal;
    QGraphicsScene *scene;
    QTimer *timercaida;

    void keyPressEvent(QKeyEvent *evento);

    QList<spritegusano*> enemigos;// lista de enemigos gusanos
    spritegusano *enemigo1; // crear el puntero para la clase gusano


public slots:
    void moveEnemy();
    void activaG();//Actualizacion caida libre personaje esta hara el slot
};
#endif // MAINWINDOW_H
