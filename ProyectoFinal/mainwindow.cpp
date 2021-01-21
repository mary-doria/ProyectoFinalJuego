#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <QList>
#include <vector>
#include <QString>
#include <QMessageBox>
#include <QDebug>
#include <QtGui>
#include <QImage>
#include <stdlib.h>
#include <QLabel>
#include <QPixmap>
#include <QtWidgets>
#include <QtGui>
#include <string.h>
#include <QGraphicsScene>
#include "cuerpopersonajejugador.h"
#include <QGraphicsItem>
#include "spritegusano.h" // libreria para los Enemigos Gusanos.
#include "nave.h"
#include "frutaburbuja.h"
#include "bala.h"
#include "vida.h"

//#include "portal.h"
using namespace std;
MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);



}


















MainWindow::~MainWindow()
{
    delete ui;
}

QList<frutaBurbuja *> MainWindow::modificarFrutaBurbuja(QList<frutaBurbuja *> listaFrutaBurbuja, int posicion)
{
    listaFrutaBurbuja.removeAt(posicion);
    return listaFrutaBurbuja;
}

QList<Vida *> MainWindow::modificarVida(QList<Vida *> listaVida, int posicion)
{
    listaVida.removeAt(posicion);
    return listaVida;

}


void MainWindow::keyPressEvent(QKeyEvent *evento)
{

    if (evento->key()==Qt::Key_A){
        bandera=false;
        PersonajePrincipal->izquierda();
        PersonajePrincipal->actualizar_sprite_izquierda();
        /*for (int i = 0; i<enemigos.count(); i++){
           if (PersonajePrincipal->collidesWithItem(enemigos.at(i))){
               PersonajePrincipal->derecha();}}*/
           }
    if (evento->key()==Qt::Key_D){
        bandera =true;
        PersonajePrincipal->derecha();
        PersonajePrincipal->actualizar_sprite_derecha();

    }

    if (evento->key()==Qt::Key_W){
        if(PersonajePrincipal->getEnTierra()==true){
            activaSalto();
                    }}

    // tecla para disparar
    else if (evento->key()==Qt::Key_Space){
        //crear bala
        bala * balaa = new bala(bandera, enemigos);
        balaa->setPos(PersonajePrincipal->x(),PersonajePrincipal->y());//posicion del retangulo
        scene->addItem(balaa);
        //qDebug()<<"bala creada";
    }
    if(Multijugador==true){
        if (evento->key()==Qt::Key_J){
            bandera=false;
            PersonajePrincipal2->izquierda();
            PersonajePrincipal2->actualizar_sprite_izquierda();
            /*for (int i = 0; i<enemigos.count(); i++){
               if (PersonajePrincipal->collidesWithItem(enemigos.at(i))){
                   PersonajePrincipal->derecha();}}*/
               }
        if (evento->key()==Qt::Key_L){
            bandera =true;
            PersonajePrincipal2->derecha();
            PersonajePrincipal2->actualizar_sprite_derecha();

        }

        if (evento->key()==Qt::Key_I){
            if(PersonajePrincipal2->getEnTierra()==true){
                activaSalto();
                        }}

        // tecla para disparar
        else if (evento->key()==Qt::Key_K){
            //crear bala
            bala * balaa = new bala(bandera, enemigos);
            balaa->setPos(PersonajePrincipal2->x(),PersonajePrincipal2->y());//posicion del retangulo
            scene->addItem(balaa);
            //qDebug()<<"bala creada";
        }

    }

    for (int i = 0; i<listaFrutaBurbuja.size(); i++) {
        if (PersonajePrincipal->collidesWithItem(listaFrutaBurbuja.at(i))){
            scene->removeItem(listaFrutaBurbuja.at(i));
            listaFrutaBurbuja=modificarFrutaBurbuja(listaFrutaBurbuja,i);
            Puntos->incrementar();
            if( Puntos->obtenerPuntos()>=2500 && PersonajePrincipal->collidesWithItem(plataforma8)){
            //FUNCION PARA PASAR AL SEGUNDO NIVEL
             QApplication::quit();}


            }
    }//Implementacion del for para eliminar objeto cuando un enemigo colisiona


}



void MainWindow::activaG(){
    bool colisiono=false;
    for (int i = 0; i<listaPlataformas.size(); i++) {
        if (PersonajePrincipal->collidesWithItem(listaPlataformas.at(i))){
            if (PersonajePrincipal->getEnTierra()==false){
                PersonajePrincipal->choque();
            }
            colisiono=true;
       }}
    //Actualizacion del personaje en todo instante de tiempo
    if (colisiono==false){PersonajePrincipal->setEnTierra(false);}
    if(PersonajePrincipal->getEnTierra()==false){
        PersonajePrincipal->caidaLibre();
    }
}

void MainWindow::activaSalto()
{
    for (int i = 0; i<listaPlataformas.size(); i++) {
        if (PersonajePrincipal->collidesWithItem(listaPlataformas.at(i))){
            PersonajePrincipal->setSaltando(false);
            PersonajePrincipal->setTiempo(0);
       }
    }
    PersonajePrincipal->saltar();
}


void MainWindow::actualizar_frutaburbuja()
{
    for(int i=0; i<listaFrutaBurbuja.count();i++){
        listaFrutaBurbuja[i]->sprite_burbuja();
    }

}

void MainWindow::actualizar_vida()
{   /*int vidas=4;
    int vidas_=vidas;*/
    for (int i = 0; i<enemigos.count(); i++){
       if (PersonajePrincipal->collidesWithItem(enemigos.at(i))){
           scene->removeItem(listaVida.at(0));
               listaVida=modificarVida(listaVida,0);
           /*SE CRASHEA PORQUE LISTA VIDA QUEDA VACIO,OSEA ME MORI :V*/
       if(listaVida.count()==0){
           //AQUI IRA LA FUNCION MORI PARA DEVOLVER AL MENU PRINCIPAL Y COLOCAR SONIDO DE BURRO

       }

       }}

}

void MainWindow::actualizar_portal()
{

  portalRickMorty->ActualizarPosicionPortal();

}


void MainWindow::cargarPosgusano()	{
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
     archivo.close();
}


void MainWindow::moveEnemy()
{
    QList<QGraphicsItem*> itemList = scene->items();


    for (int j = 0; j<enemigos.size(); j++){

        spritegusano *enemigo = enemigos.at(j);/* creo un enemigo de la clase gusado y le asigno su valor segun
                                                  la posicion j que recorre la Qlist de enemigo */

        if (enemigo->bande==true){
            if(enemigo->x()>V_posgusanos[j*2]){
            //qDebug()<<"V_posgusanos[j]*2"<<V_posgusanos[j*2];//imprimir posx1 del gusano n
                enemigo->left(3); }
            else
            enemigo->bande=false;}//if
        else{
            if(enemigo->x()<V_posgusanos[j*2+1]){
                //qDebug()<<"V_posgusanos[j]*2+1"<<V_posgusanos[j*2+1];//imprimir posx2 del gusano n
                enemigo->right(3); }
            else
            enemigo->bande=true;}

}

    for (int i = 0; i<enemigos.size();i++){
        spritegusano *enemigo = enemigos.at(i);
        if(!itemList.contains((QGraphicsItem*)enemigo)){
            enemigos.removeOne(enemigo);
            V_posgusanos.removeAt((i*2)+1);
            qDebug()<<V_posgusanos;
            V_posgusanos.removeAt(i*2);
            qDebug()<<V_posgusanos;
            Puntos->incrementar();
            break;
        }
    }

    }



void MainWindow::on_bottonJugar_clicked()
{   Multijugador=false;
    bandera=true;
    ui->setupUi(this);
    scene = new QGraphicsScene;
    ui->graphicsView->setScene(scene);
    ui->bottonJugar->hide();
    ui->bottonInstrucciones->hide();
    ui->bottonMultijugador->hide();
    ui->bottonUsuario->hide();
    ui->radioButton->hide();
    ui->radioButton_2->hide();
    PersonajePrincipal = new CuerpoPersonajeJugador(90,50,2);

    scene->addItem(PersonajePrincipal);
    PersonajePrincipal->setScale(0.4);
    scene->setSceneRect(0,0,960,519);
    scene->setBackgroundBrush(QPixmap(":/Imagenes/Escenario1.png"));
    cargarPosgusano();// funcion para cargas las posiciones de los gusanos
    //Inicializacion de enemigos
    enemigo1= new spritegusano(true, 800,360);scene->addItem(enemigo1);enemigo1->setScale(0.4);enemigos.push_back(enemigo1);
    enemigo2= new spritegusano(true, 360,110);scene->addItem(enemigo2);enemigo2->setScale(0.4);enemigos.push_back(enemigo2);
    enemigo3= new spritegusano(true, 635,240);scene->addItem(enemigo3);enemigo3->setScale(0.4);enemigos.push_back(enemigo3);
    enemigo4= new spritegusano(true, 385,260);scene->addItem(enemigo4);enemigo4->setScale(0.4);enemigos.push_back(enemigo4);
    enemigo5= new spritegusano(false, 420,260);scene->addItem(enemigo5);enemigo5->setScale(0.4);enemigos.push_back(enemigo5);
    enemigo6= new spritegusano(true, 250,320);scene->addItem(enemigo6);enemigo6->setScale(0.4);enemigos.push_back(enemigo6);
    enemigo7= new spritegusano(false, 650,410);scene->addItem(enemigo7);enemigo7->setScale(0.4);enemigos.push_back(enemigo7);
    enemigo8= new spritegusano(false, 70,370);scene->addItem(enemigo8);enemigo8->setScale(0.4);enemigos.push_back(enemigo8);
    enemigo9= new spritegusano(false, 960,460);scene->addItem(enemigo9);enemigo9->setScale(0.4);enemigos.push_back(enemigo9);
    enemigo10= new spritegusano(true, 0,460);scene->addItem(enemigo10);enemigo10->setScale(0.4);enemigos.push_back(enemigo10);
    QTimer *timerEnemigos = new QTimer();
    connect(timerEnemigos,SIGNAL(timeout()),this,SLOT(moveEnemy()));
    timerEnemigos->start(100);
    /*Timer que indica la cada cuanto bajara el personaje
    dado que depende de la gravedad ira mas rapido mientras caiga*/
    QTimer *timerVida = new QTimer();
    connect(timerVida,SIGNAL(timeout()),this,SLOT(actualizar_vida()));
    timerVida->start(800);
    timercaida = new QTimer();
    connect(timercaida,SIGNAL(timeout()),this,SLOT(activaG()));
    timercaida->start(30);
    vida1=new Vida(420,30);listaVida.push_back(vida1);scene->addItem(vida1);
    vida2=new Vida(450,30);listaVida.push_back(vida2);scene->addItem(vida2);
    vida3=new Vida(480,30);listaVida.push_back(vida3);scene->addItem(vida3);
    vida4=new Vida(510,30);listaVida.push_back(vida4);scene->addItem(vida4);
    vida5=new Vida(540,30);listaVida.push_back(vida5);scene->addItem(vida5);

    //PLATAFORMAS PRIMER NIVEL
        naverickmorty= new nave(600,110);scene->addItem(naverickmorty);
        portalRickMorty=new  Portal(960,130,20,1);scene->addItem(portalRickMorty);
        timerportalRickMorty = new QTimer();
        connect(timerportalRickMorty,SIGNAL(timeout()),this,SLOT(actualizar_portal()));
        timerportalRickMorty->start(200);
        naverickmorty->setScale(0.5);
        plataformaInicialPosicion = new Plataforma(70,100);listaPlataformas.push_back(plataformaInicialPosicion);scene->addItem(plataformaInicialPosicion);
        plataforma2=new Plataforma(210,130);listaPlataformas.push_back(plataforma2);scene->addItem(plataforma2);
        plataforma3 =new Plataforma(800,400);listaPlataformas.push_back(plataforma3);scene->addItem(plataforma3);
        plataforma4 = new Plataforma(360,150);listaPlataformas.push_back(plataforma4);scene->addItem(plataforma4);
        plataforma5= new Plataforma(525,380);listaPlataformas.push_back(plataforma5);scene->addItem(plataforma5);
        plataforma6= new Plataforma(635,280);listaPlataformas.push_back(plataforma6);scene->addItem(plataforma6);
        plataforma7 = new Plataforma(740,220);listaPlataformas.push_back(plataforma7);scene->addItem(plataforma7);
        plataforma8 = new Plataforma(600,170);listaPlataformas.push_back(plataforma8);scene->addItem(plataforma8);//PLATAFORMA NAVE
        plataforma9 = new Plataforma(385,300);listaPlataformas.push_back(plataforma9);scene->addItem(plataforma9);
        plataforma10 = new Plataforma(70,410);listaPlataformas.push_back(plataforma10);scene->addItem(plataforma10);
        plataforma11= new Plataforma(250,360);listaPlataformas.push_back(plataforma11);scene->addItem(plataforma11);
        plataforma12= new Plataforma(650,450);listaPlataformas.push_back(plataforma12);scene->addItem(plataforma12);
        plataforma13= new Plataforma(70,410);listaPlataformas.push_back(plataforma13);scene->addItem(plataforma13);
        fruta1= new frutaBurbuja(); scene->addItem(fruta1);fruta1->setPos(210,70);listaFrutaBurbuja.push_back(fruta1);
        fruta2= new frutaBurbuja(); scene->addItem(fruta2);fruta2->setPos(360,90);listaFrutaBurbuja.push_back(fruta2);
        fruta3= new frutaBurbuja(); scene->addItem(fruta3);fruta3->setPos(75,380);listaFrutaBurbuja.push_back(fruta3);
        fruta4= new frutaBurbuja(); scene->addItem(fruta4);fruta4->setPos(250,305);listaFrutaBurbuja.push_back(fruta4);
        fruta5= new frutaBurbuja(); scene->addItem(fruta5);fruta5->setPos(385,230);listaFrutaBurbuja.push_back(fruta5);
        fruta6= new frutaBurbuja(); scene->addItem(fruta6);fruta6->setPos(650,395);listaFrutaBurbuja.push_back(fruta6);
        fruta7= new frutaBurbuja(); scene->addItem(fruta7);fruta7->setPos(740,170);listaFrutaBurbuja.push_back(fruta7);
        fruta8= new frutaBurbuja(); scene->addItem(fruta8);fruta8->setPos(800,340);listaFrutaBurbuja.push_back(fruta8);
        fruta9= new frutaBurbuja(); scene->addItem(fruta9);fruta9->setPos(530,320);listaFrutaBurbuja.push_back(fruta9);
        fruta10= new frutaBurbuja(); scene->addItem(fruta10);fruta10->setPos(740,120);listaFrutaBurbuja.push_back(fruta10);
        //fruta11= new frutaBurbuja(); scene->addItem(fruta11);fruta11->setPos(75,260);listaFrutaBurbuja.push_back(fruta11);
        fruta12= new frutaBurbuja(); scene->addItem(fruta12);fruta12->setPos(75,300);listaFrutaBurbuja.push_back(fruta12);
        fruta13= new frutaBurbuja(); scene->addItem(fruta13);fruta13->setPos(75,340);listaFrutaBurbuja.push_back(fruta13);
        fruta14= new frutaBurbuja(); scene->addItem(fruta14);fruta14->setPos(760,340);listaFrutaBurbuja.push_back(fruta14);
        fruta15= new frutaBurbuja(); scene->addItem(fruta15);fruta15->setPos(840,340);listaFrutaBurbuja.push_back(fruta15);
        fruta16= new frutaBurbuja(); scene->addItem(fruta16);fruta16->setPos(630,220);listaFrutaBurbuja.push_back(fruta16);


        QTimer *timerfrutaburbuja = new QTimer();
        connect(timerfrutaburbuja,SIGNAL(timeout()),this,SLOT(actualizar_frutaburbuja()));
        timerfrutaburbuja->start(150);


        Puntos = new Puntaje();
        scene->addItem(Puntos);


}

void MainWindow::on_bottonInstrucciones_clicked()
{

}

void MainWindow::on_bottonUsuario_clicked()
{

}

void MainWindow::on_bottonMultijugador_clicked()
{
    Multijugador=true;

}

void MainWindow::on_radioButton_2_clicked()
{

}

void MainWindow::on_radioButton_clicked()
{

}
