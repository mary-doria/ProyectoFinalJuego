#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <QList>
#include <vector>
#include <QGraphicsScene>
#include "cuerpopersonajejugador.h"
#include <QGraphicsItem>
#include "spritegusano.h" // libreria para los Enemigos Gusanos.
#include "nave.h"
#include "bala.h"

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    scene = new QGraphicsScene;
    ui->graphicsView->setScene(scene);
    PersonajePrincipal = new CuerpoPersonajeJugador(60,50);
    scene->addItem(PersonajePrincipal);
    PersonajePrincipal->setScale(0.4);
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

    /*Timer que indica la cada cuanto bajara el personaje
    dado que depende de la gravedad ira mas rapido mientras caiga*/

    timercaida = new QTimer();
    connect(timercaida,SIGNAL(timeout()),this,SLOT(activaG()));
    timercaida->start(30);
    //cargaArchivos();


    plataformaInicialPosicion = new Plataforma(70,100);//arriba
        plataforma2=new Plataforma(210,130);//arriba
        plataforma3 =new Plataforma(800,400);
        plataforma4 = new Plataforma(360,150);//arriba
        plataforma5= new Plataforma(525,380);
        plataforma6= new Plataforma(635,280);
        plataforma7 = new Plataforma(740,220);
        plataforma8 = new Plataforma(850,170);//PLATAFORMA NAVE
        plataforma9 = new Plataforma(385,300);//ESCALA

        plataforma10 = new Plataforma(70,410);//piso
        plataforma11= new Plataforma(250,360);//piso
        plataforma12= new Plataforma(650,450);//piso
        plataforma13= new Plataforma(70,410);//piso


    naverickmorty= new nave(850,100);
    naverickmorty->setScale(0.5);
    listaPlataformas.push_back(plataformaInicialPosicion);
    listaPlataformas.push_back(plataforma2);
    listaPlataformas.push_back(plataforma3);
    listaPlataformas.push_back(plataforma4);
    listaPlataformas.push_back(plataforma5);
    listaPlataformas.push_back(plataforma6);
    listaPlataformas.push_back(plataforma7);
    listaPlataformas.push_back(plataforma8);
    listaPlataformas.push_back(plataforma9);
    listaPlataformas.push_back(plataforma10);
    listaPlataformas.push_back(plataforma11);
    listaPlataformas.push_back(plataforma12);
    listaPlataformas.push_back(plataforma13);


    scene->addItem(plataformaInicialPosicion);
    scene->addItem(plataforma2);
    scene->addItem(plataforma3);
    scene->addItem(plataforma4);
    scene->addItem(plataforma5);
    scene->addItem(plataforma6);
    scene->addItem(plataforma7);
    //scene->addItem(plataforma8);
    scene->addItem(plataforma8);
    scene->addItem(naverickmorty);
    scene->addItem(plataforma9);
    scene->addItem(plataforma10);
    scene->addItem(plataforma11);
    scene->addItem(plataforma12);
    scene->addItem(plataforma13);
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
    //ddif (PersonajePrincipal->collidesWithItem(plataformaInicialPosicion)){PersonajePrincipal->izquierda();}
    //if (evento->key()==Qt::Key_S){
      //  PersonajePrincipal->caidaLibre();//Para este movimiento se necesitan las plataformas

    /*if (PersonajePrincipal->collidesWithItem(plataformaInicialPosicion)){PersonajePrincipal->choque();}*/
//}
    if (evento->key()==Qt::Key_W){
        if(PersonajePrincipal->getEnTierra()==true){
            activaSalto();
                    }}

    // tecla para disparar
    else if (evento->key()==Qt::Key_Space){
        //crear bala
        bala * balaa = new bala();
        balaa->setPos(PersonajePrincipal->x(),PersonajePrincipal->y());//posicion del retangulo
        scene->addItem(balaa);
        //qDebug()<<"bala creada";
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
