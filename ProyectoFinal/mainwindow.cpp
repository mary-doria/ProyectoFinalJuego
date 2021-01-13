#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <QList>
#include <vector>
#include "spritegusano.h" // libreria para los Enemigos Gusanos.



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
    cargarPosgusano();// funcion para cargas las posiciones de los gusanos
    //inicializo enemigo 1
    enemigo1= new spritegusano(true, 700,400);
    scene->addItem(enemigo1);
    enemigo1->setScale(0.4);
    enemigos.push_back(enemigo1);
    QTimer *timer1 = new QTimer();
    connect(timer1,SIGNAL(timeout()),this,SLOT(moveEnemy()));
    timer1->start(25);
    //inicializo enemigo 2
    enemigo2= new spritegusano(true, 790,200);
    scene->addItem(enemigo2);
    enemigo2->setScale(0.4);
    enemigos.push_back(enemigo2);
    QTimer *timer2 = new QTimer();
    connect(timer2,SIGNAL(timeout()),this,SLOT(moveEnemy()));
    timer2->start(25);





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

void MainWindow::cargarPosgusano()
{
    std::fstream archivo;
     archivo.open("posGusanos.txt",std::ios::in);//leer el archivo
     //iteremos sobre el archivo
     short int posx1, posx2;
     while(!archivo.eof()){
         archivo >> posx1 >> posx2;
         // guardar las posiciones en el Qvector
         V_posgusanos.push_back(posx1);
         V_posgusanos.push_back(posx2);
      qDebug()<<V_posgusanos;

     }

}

void MainWindow::moveEnemy()
{
    for (int j = 0; j<enemigos.size(); j++){
        spritegusano *enemigo = enemigos.at(j);/* creo un enemigo de la clase gusado y le asigno su valor segun
                                                  la posicion j que recorre la Qlist de enemigo */

        if (enemigo->bande==true){
            if(enemigo->x()>V_posgusanos[j*2]){
            //qDebug()<<"V_posgusanos[j]*2"<<V_posgusanos[j*2];//imprimir posx1 del gusano n
                enemigo->left(7); }
            else
            enemigo->bande=false;}//if
        else{
            if(enemigo->x()<V_posgusanos[j*2+1]){
                //qDebug()<<"V_posgusanos[j]*2+1"<<V_posgusanos[j*2+1];//imprimir posx2 del gusano n
                enemigo->right(7); }
            else
            enemigo->bande=true;}

}//for
 }



