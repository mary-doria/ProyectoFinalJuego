#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <QList>
#include <vector>
#include "cuerpopersonajejugador.h"
#include "spritegusano.h" // libreria para los Enemigos Gusanos.


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
    enemigo1= new spritegusano(true, 700,400);// se crea un enemigo gusano utilizando memoria dinamica
    scene->addItem(enemigo1);// se agrega a la escena
    enemigo1->setScale(0.5);// se le realiza la escala
    enemigos.push_back(enemigo1);// se agrega el enemigo a una Qlista
    QTimer *timer1 = new QTimer();// se usa un timer para poder utilizar el slot de la funcion move enemy
    connect(timer1,SIGNAL(timeout()),this,SLOT(moveEnemy()));// se conecta el timer con la funcion en esta clase
    timer1->start(25);// inicializacion del reloj
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

void MainWindow::moveEnemy()
{


    if (enemigo1->bande==true){
    if(enemigo1->x()>600){
        enemigo1->left(7); }
    else
        enemigo1->bande=false;
    }
    else{
        if(enemigo1->x()<800){ enemigo1->right(7); }
        else
            enemigo1->bande=true;

 }

}
