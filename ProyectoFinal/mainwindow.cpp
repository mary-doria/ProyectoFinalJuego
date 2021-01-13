#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <QList>
#include <vector>
#include <QGraphicsScene>
#include "cuerpopersonajejugador.h"
#include <QGraphicsItem>
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
    scene->setSceneRect(0,0,960,519);
    scene->setBackgroundBrush(QPixmap(":/Imagenes/Escenario2.png"));
    /*Timer que indica la cada cuanto bajara el personaje
    dado que depende de la gravedad ira mas rapido mientras caiga*/
    timercaida = new QTimer();
    connect(timercaida,SIGNAL(timeout()),this,SLOT(activaG()));
    timercaida->start(100);
    enemigo1= new spritegusano(true, 700,400);// se crea un enemigo gusano utilizando memoria dinamica
    scene->addItem(enemigo1);// se agrega a la escena
    enemigo1->setScale(0.4);// se le realiza la escala
    enemigos.push_back(enemigo1);// se agrega el enemigo a una Qlista
    QTimer *timer1 = new QTimer();// se usa un timer para poder utilizar el slot de la funcion move enemy
    connect(timer1,SIGNAL(timeout()),this,SLOT(moveEnemy()));// se conecta el timer con la funcion en esta clase
    timer1->start(25);// inicializacion del reloj
    //cargaArchivos();

    //plataformaPiso = new Plataforma(0,-400);
    plataformaPiso = new Plataforma(100,400);/*
    plataforma3 =new Plataforma(-900,-3,40,148);
    plataforma4 = new Plataforma(-3,-500,148,40);
    plataforma5= new Plataforma(405,40,148,40);
    plataforma6 = new Plataforma(2,-2,148,40);
    plataforma7 = new Plataforma(-110,-110,148,40);

    scene->addItem(plataforma1);
    scene->addItem(plataforma2);
    scene->addItem(plataforma3);
    scene->addItem(plataforma4);
    scene->addItem(plataforma5);
    scene->addItem(plataforma6);
    scene->addItem(plataformaPiso);*/

    scene->addItem(plataformaPiso);

    }

MainWindow::~MainWindow()
{
    delete ui;
}
/*ORGANIZAR FUNCION CON 2 PARAMETROS DE ENTRADA
void MainWindow::cargaArchivos()
{
    std::fstream archivo;
    archivo.open("C:\\Users\\57316\\Documents\\GITHUB\\ProyectoFinalJuego\\build-ProyectoFinal-Desktop_Qt_5_15_0_MinGW_64_bit-Debug\\plataformasPosiciones.txt",std::fstream::in);//recibe dos constructores
    //(x,y) las posiciones de las plataformas y un ancho y un alto
    float Posx,Posy,anchoP,altoP;
    //while(!archivo.eof()){
        // se extraera los cuatro parametros de las plataformas
        archivo >> Posx >> Posy >> anchoP >> altoP ;
        std::cout<< archivo;

        Plataforma * plataformaNueva = new Plataforma (Posx,Posy,anchoP,altoP);
        std::cout<< Posx << " " << Posy <<" "<< anchoP <<" " <<altoP<< std::endl;
        vectorPlataformas.push_back(plataformaNueva);
        scene->addItem(plataformaNueva);
    //}
}*/

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
    if(PersonajePrincipal->collidesWithItem(plataformaPiso)){PersonajePrincipal->choque();}
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
