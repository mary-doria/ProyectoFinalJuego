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

void MainWindow::bordedelete(spritemoscas *b)
{
    if(b->getPX()<b->getR()){
        scene->removeItem(b);
        for (int i = 0; i<moscas.size();i++){
            spritemoscas *enemigo = moscas.at(i);
            if(enemigo == b){
                moscas.removeOne(enemigo);
            }
        }
        //qDebug() << "delete1";
    }
    if(b->getPX()>1000-b->getR()){
        scene->removeItem(b);
        for (int i = 0; i<moscas.size();i++){
            spritemoscas *enemigo = moscas.at(i);
            if(enemigo == b){
                moscas.removeOne(enemigo);
            }
        }
        //qDebug() << "delete2";
    }
    if(b->getPY()<b->getR()){
        scene->removeItem(b);
        for (int i = 0; i<moscas.size();i++){
            spritemoscas *enemigo = moscas.at(i);
            if(enemigo == b){
                moscas.removeOne(enemigo);
            }
        }
        //qDebug() << "delete3";
    }
    if(b->getPY()>500-b->getR()){
        scene->removeItem(b);
        for (int i = 0; i<moscas.size();i++){
            spritemoscas *enemigo = moscas.at(i);
            if(enemigo == b){
                moscas.removeOne(enemigo);
            }
        }
        //qDebug() << "delete4";
    }

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
    if (evento->key()==Qt::Key_Space){
        //crear bala
        bala * balaa = new bala(bandera, enemigos, moscas);
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
        if (evento->key()==Qt::Key_K){
            //crear bala
            bala * balaa = new bala(bandera, enemigos,moscas);
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



            }
    }//Implementacion del for para eliminar objeto cuando un enemigo colisiona

    if(nivelActual == 1){
    if (PersonajePrincipal->collidesWithItem(naverickmorty)){
    scene->addItem(portalRickMorty);
    }
    if (PersonajePrincipal->collidesWithItem(portalRickMorty)){
        if(Puntos->obtenerPuntos()>=500){
            nivelActual +=1;
            segundoNivel();
        }

    }
    }
    if(nivelActual == 2){
    if (PersonajePrincipal->collidesWithItem(naverickmorty)){
    scene->addItem(portalRickMorty);
    }
    if (PersonajePrincipal->collidesWithItem(portalRickMorty)){
        if(Puntos->obtenerPuntos()>=500){
            nivelCasa();
        }

    }
    }


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

void MainWindow::actualizarMoscas()
{
    if(moscas.size()!=0){
    //qDebug()<<"antes del for :' v";
        for (int i=0;i<moscas.size();i++) {
        moscas.at(i)->actual(v_limit);
        bordedelete(moscas.at(i));
    }

    }

}

void MainWindow::crearMoscas()
{
    cout<<"Se crea";
    if( val<50){//no se crean mas de 20 moscas
        val++;
    banderaMosca=!banderaMosca;//bandera para cambiar el sentido de las moscas
    moscas.push_back(new spritemoscas(banderaMosca));
    scene->addItem(moscas.back());
 }
}


void MainWindow::cargarPosgusano(int nivel)	{
    std::fstream archivo;
    if (nivel==1){
        archivo.open("posGusanos.txt",std::ios::in);}//leer el archivo
     else if(nivel==2){
     archivo.open("posGusanos2.txt",std::ios::in);}//leer el archivo
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

void MainWindow::segundoNivel()
{
    //timercaida->stop();
    //timersalto->stop();
    //timerfrutaburbuja->stop();
    //timerVida->stop();
    //timerEnemigos->stop();
    //timerportalRickMorty->stop();
    scene = new QGraphicsScene;
    scene->setSceneRect(0,0,960,519);
    scene->setBackgroundBrush(QImage(":/Imagenes/Escenario2.png"));
    ui->graphicsView->setScene(scene);
    listaPlataformas.clear();
    listaFrutaBurbuja.clear();
    enemigos.clear();
    PersonajePrincipal = new CuerpoPersonajeJugador(90,50,2);
    scene->addItem(PersonajePrincipal);
    PersonajePrincipal->setScale(0.4);

    plataformaInicialPosicion = new Plataforma(70,130);listaPlataformas.push_back(plataformaInicialPosicion);scene->addItem(plataformaInicialPosicion);
    plataforma2=new Plataforma(210,180);listaPlataformas.push_back(plataforma2);scene->addItem(plataforma2);
    plataforma3 =new Plataforma(350,230);listaPlataformas.push_back(plataforma3);scene->addItem(plataforma3);
    plataforma4 =new Plataforma(490,280);listaPlataformas.push_back(plataforma4);scene->addItem(plataforma4);
    plataforma5 =new Plataforma(630,330);listaPlataformas.push_back(plataforma5);scene->addItem(plataforma5);
    plataforma6 =new Plataforma(770,400);listaPlataformas.push_back(plataforma6);scene->addItem(plataforma6);
    //plataforma7 = new Plataforma(880,330);listaPlataformas.push_back(plataforma7);scene->addItem(plataforma7);
    fruta1= new frutaBurbuja(); scene->addItem(fruta1);fruta1->setPos(210,140);listaFrutaBurbuja.push_back(fruta1);
    fruta2= new frutaBurbuja(); scene->addItem(fruta2);fruta2->setPos(350,190);listaFrutaBurbuja.push_back(fruta2);
    fruta3= new frutaBurbuja(); scene->addItem(fruta3);fruta3->setPos(490,240);listaFrutaBurbuja.push_back(fruta3);
    fruta4= new frutaBurbuja(); scene->addItem(fruta4);fruta4->setPos(630,290);listaFrutaBurbuja.push_back(fruta4);
    fruta5= new frutaBurbuja(); scene->addItem(fruta5);fruta5->setPos(770,360);listaFrutaBurbuja.push_back(fruta5);
    enemigo1= new spritegusano(true, 0,460);scene->addItem(enemigo1);enemigo1->setScale(0.4);enemigos.push_back(enemigo1);
    enemigo2= new spritegusano(true, 500,460);scene->addItem(enemigo2);enemigo2->setScale(0.4);enemigos.push_back(enemigo2);
    enemigo3= new spritegusano(true, 250,460);scene->addItem(enemigo3);enemigo3->setScale(0.4);enemigos.push_back(enemigo3);
    enemigo4= new spritegusano(false, 800,460);scene->addItem(enemigo4);enemigo4->setScale(0.4);enemigos.push_back(enemigo4);
    enemigo5= new spritegusano(false, 650,460);scene->addItem(enemigo5);enemigo5->setScale(0.4);enemigos.push_back(enemigo5);
    enemigo6= new spritegusano(false, 150,460);scene->addItem(enemigo6);enemigo6->setScale(0.4);enemigos.push_back(enemigo6);
    naverickmorty= new nave(70,430);scene->addItem(naverickmorty);naverickmorty->setScale(0.5);
    portalRickMorty=new  Portal(900,430,20,1);

    h_limit=960;//limite de la pantalla horizontal
    v_limit=519;//limite vertical
    timerMoscas=new QTimer();
    timer2Moscas=new QTimer();
    //scene->setSceneRect(0,0,h_limit,v_limit);
    ui->centralwidget->adjustSize();
    scene->addRect(scene->sceneRect());
    ui->graphicsView->resize(scene->width(),scene->height());
    this->resize(ui->graphicsView->width()+100,ui->graphicsView->height()+100);
    timerMoscas->start(1000);//timer de aparicion de las moscas
    timer2Moscas->start(25);//mov de las moscas
    connect(timerMoscas,SIGNAL(timeout()),this,SLOT(crearMoscas()));
    connect(timer2Moscas,SIGNAL(timeout()),this,SLOT(actualizarMoscas()));
    mosca=new spritemoscas(true);// crear la primera moscas para la lista asi se puede activar la de actualizar
    moscas.push_back(mosca);//agrego mosca en la lista




}

void MainWindow::nivelCasa()
{
    scene = new QGraphicsScene;
    scene->setSceneRect(0,0,960,519);
    scene->setBackgroundBrush(QImage(":/Imagenes/LlegamosCasa.gif"));
    ui->graphicsView->setScene(scene);

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

    for (int i = 0; i<moscas.size();i++){
        spritemoscas *enemigoMosca = moscas.at(i);
        if(!itemList.contains((QGraphicsItem*)enemigoMosca)){
            moscas.removeOne(enemigoMosca);

            Puntos->incrementar();
            break;
        }
    }

    }



void MainWindow::on_bottonJugar_clicked()
{
    nivelActual = 1;

    Multijugador=false;
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
        scene->setBackgroundBrush(QImage(":/Imagenes/Escenario1.png"));
        cargarPosgusano(nivelActual);// funcion para cargas las posiciones de los gusanos
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
        timerEnemigos = new QTimer();
        connect(timerEnemigos,SIGNAL(timeout()),this,SLOT(moveEnemy()));
        timerEnemigos->start(100);
        /*Timer que indica la cada cuanto bajara el personaje
        dado que depende de la gravedad ira mas rapido mientras caiga*/
        timerVida = new QTimer();
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
            portalRickMorty=new  Portal(70,430,20,1);
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
    scene = new QGraphicsScene;
    scene->setSceneRect(0,0,960,519);
    scene->setBackgroundBrush(QImage(":/Imagenes/LlegamosCasa.gif"));
    //QImage image=QImage(":/Imagenes/LlegamosCasa.gif");


    ui->graphicsView->setScene(scene);

    QLabel *gif_anim=new QLabel();
    QMovie *movie=new QMovie(":/Imagenes/LlegamosCasa.gif");
    gif_anim->setMovie(movie);
    movie->start();
    //scene->addItem(gif_anim);
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


