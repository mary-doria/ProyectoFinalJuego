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
    scene->setSceneRect(0,0,5000,5000);// 0 , 0 esquina superior
    PersonajePrincipal = new CuerpoPersonajeJugador(127,166);
    scene->addItem(PersonajePrincipal);

}

void MainWindow::keyPressEvent(QKeyEvent *evento)
{

    if (evento->key()==Qt::Key_A){
        PersonajePrincipal->izquierda();}
    if (evento->key()==Qt::Key_D){
        PersonajePrincipal->derecha();}

}
