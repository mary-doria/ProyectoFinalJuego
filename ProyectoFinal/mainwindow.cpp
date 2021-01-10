#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <QList>
#include <vector>


MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    scene = new QGraphicsScene;
    ui->graphicsView->setScene(scene);
    PersonajePrincipal = new CuerpoPersonajeJugador(127,166);
    scene->addItem(PersonajePrincipal);
    PersonajePrincipal->setScale(1);
    scene->setSceneRect(0,0,960,519);
    scene->setBackgroundBrush(QPixmap(":/Imagenes/Escenario2.png"));

}
MainWindow::~MainWindow()
{
delete ui;
}

void MainWindow::keyPressEvent(QKeyEvent *evento)
{

    if (evento->key()==Qt::Key_A){
        PersonajePrincipal->izquierda();
        PersonajePrincipal->actualizar_sprite_izquierda();}
    if (evento->key()==Qt::Key_D){
        PersonajePrincipal->derecha();
        PersonajePrincipal->actualizar_sprite_derecha();}

}

