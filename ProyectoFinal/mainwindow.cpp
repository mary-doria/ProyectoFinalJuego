#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <QList>
#include <vector>
#include "cuerpopersonajejugador.h"


MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    scene = new QGraphicsScene;
    ui->graphicsView->setScene(scene);
    PersonajePrincipal = new CuerpoPersonajeJugador(127,200);
    scene->addItem(PersonajePrincipal);
    PersonajePrincipal->setScale(0.5);
    scene->setSceneRect(0,0,1366,768);
    scene->setBackgroundBrush(QPixmap(":/Imagenes/Escenario2.png"));
/*Timer que indica la cada cuanto bajara el personaje
dado que depende de la gravedad ira mas rapido mientras caiga*/
    timercaida = new QTimer();
    connect(timercaida,SIGNAL(timeout()),this,SLOT(activaG()));
    timercaida->start(100);
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
    if (evento->key()==Qt::Key_W){
        PersonajePrincipal->caidaLibre();//Para este movimiento se necesitan las plataformas


       }


}

void MainWindow::activaG(){
    PersonajePrincipal->caidaLibre();//Actualizacion del personaje en todo instante de tiempo

}
