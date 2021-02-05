#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <QList>
#include <vector>
#include <QString>
#include <QMessageBox> // para imprimir los mensajes en recuadro
#include <QDebug> // para imprimir mensajes
#include <QtGui>
#include <QImage>
#include <stdlib.h>
#include <QLabel>
#include <QPixmap>
#include <QtWidgets>
#include <QtGui>
#include <sstream>
#include <fstream>
#include <iostream>
#include <string.h>
#include <QGraphicsScene>
#include <QGraphicsItem>
//multimedia librerias necesarias para usar los sonidos
#include <QMediaPlayer>
#include <QSound>
using namespace std;
MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    //Botones que se muestran en el GraphicView cuando se abre el juego
    ui->bottonJugar->show();
    ui->bottonInstrucciones->show();
    //Botones que se esconden en el GraphicView cuando se abre el juego
    ui->label->hide();
    ui->label_2->hide();
    ui->lineEdit->hide();
    ui->bottonMultijugador->hide();
    ui->bottonUsurario->hide();
    ui->bottonReiniciar->hide();
    ui->eliminarPartida->hide();
    ui->cargarPartida->hide();
    ui->pushButton->hide();
    ui->pushButton_2->hide();
    //Botones que ofrecen la opcion de escoger uno u otro al usuario
    ui->radioButton->hide();
    ui->radioButton_2->hide();
    Puntos = new Puntaje();//Se crea un puntero de la clase puntaje
    music = new QMediaPlayer();//variable para la cancion de inicio
    disparo = new QMediaPlayer();//variable para el sonido del disparo
    music->setMedia(QUrl("qrc:/Imagenes/songinicio.mpeg"));//direccion de la cancion de inicio
    disparo->setMedia(QUrl("qrc:/Imagenes/bala.mp3"));//direccion del sonido de la bala


    music->play();//reproducir la musica de inicio


}
MainWindow::~MainWindow()
{
    delete ui;
}
//Funcion que remueve de la listaFrutaBurbuja la fruta que elimino por el personaje
QList<frutaBurbuja *> MainWindow::modificarFrutaBurbuja(QList<frutaBurbuja *> listaFrutaBurbuja, int posicion)
{
    listaFrutaBurbuja.removeAt(posicion);
    return listaFrutaBurbuja;//Retorna la lista actualizada
}
//Funcion que remueve de la listaVida la vida que el personaje Perdio
QList<Vida *> MainWindow::modificarVida(QList<Vida *> listaVida, int posicion)
{
    listaVida.removeAt(posicion);
    return listaVida;//Retorna la lista actualizada

}
//Funcion para eliminar las moscas en los limites de la pantalla
void MainWindow::bordedelete(spritemoscas *b)
{
    if(b->getPX()<b->getR() ){//verificar si la pos de las moscas esta en el extremo derecho
        scene->removeItem(b);//remover la mosca de la scena
        for (int i = 0; i<moscas.size();i++){//recorrer la lista de la moscas
            spritemoscas *enemigo = moscas.at(i);//asignar la mosca
            if(enemigo == b){//si el items removido es igual a la mosca
                moscas.removeOne(enemigo);//eliminar la mosca
            }
        }
        //qDebug() << "delete1";
    }
    if(b->getPX()>1000-b->getR()){//si esta en el extremo izquierdo
        scene->removeItem(b);//remover la mosca de la scena
        for (int i = 0; i<moscas.size();i++){//recorrer la lista de las moscas
            spritemoscas *enemigo = moscas.at(i);//asignar la mosca
            if(enemigo == b){//verificar que la mosca removida sea la de la lista
                moscas.removeOne(enemigo);//eliminar la mosca
            }
        }
        //qDebug() << "delete2";
    }
    if(b->getPY()<b->getR() ){//extremo superior
        scene->removeItem(b);//remover la mosca de la scena
        for (int i = 0; i<moscas.size();i++){//recorrer la lista de las moscas
            spritemoscas *enemigo = moscas.at(i);//asignar la mosca
            if(enemigo == b){//verificar que la mosca removida sea la de la lista
                moscas.removeOne(enemigo);//eliminar la mosca
            }
        }
        //qDebug() << "delete3";
    }
    if(b->getPY()>500-b->getR()){//extremo inferior
        scene->removeItem(b);//remover la mosca de la scena
        for (int i = 0; i<moscas.size();i++){//recorrer la lista de las moscas
            spritemoscas *enemigo = moscas.at(i);//asignar la mosca
            if(enemigo == b){//verificar que la mosca removida sea la de la lista
                moscas.removeOne(enemigo);//eliminar la mosca
            }
        }
        //qDebug() << "delete4";
    }

}

//Funcion que nos permite mover al personaje y colisionar con objetos puestos en escena
void MainWindow::keyPressEvent(QKeyEvent *evento)
{
    if (nivelActual!=0){//verificar que este en algun nivel diferente al menu principal
        if (evento->key()==Qt::Key_A){
        bandera=false;//bandera para el mov de la bala
        PersonajePrincipal->izquierda();
        PersonajePrincipal->actualizar_sprite_izquierda();
        /*for (int i = 0; i<enemigos.count(); i++){
           if (PersonajePrincipal->collidesWithItem(enemigos.at(i))){
               PersonajePrincipal->derecha();}}*/
           }
    if (evento->key()==Qt::Key_D){//Movimiento con la letra D hacia la derecha
        bandera =true;//banera para el mov de la bala
        PersonajePrincipal->derecha();
        PersonajePrincipal->actualizar_sprite_derecha();

    }

    if (evento->key()==Qt::Key_W){//Movimiento con la letra W para saltar
        if(PersonajePrincipal->getEnTierra()==true){
            activaSalto();
                    }}


    if (evento->key()==Qt::Key_Space){//Tecla para disparar con Space
        //sonido de bala
       if(disparo->state()==QMediaPlayer::PlayingState){//reproducir disparo
       disparo->setPosition(50);//posicion de reproducion
       }
       else if (disparo->state()==QMediaPlayer::StoppedState)//parar la reproducion del disparo
       {
        disparo->play();//iniciar la reproducion del disparo
       }
        //crear bala
        bala * balaa = new bala(bandera, enemigos, moscas);//puntero de la clase bala
        balaa->setPos(PersonajePrincipal->x(),PersonajePrincipal->y());//posicion del personaje
        scene->addItem(balaa);//agregar el item a la scena


        //qDebug()<<"bala creada";
    }


    for (int i = 0; i<listaFrutaBurbuja.size(); i++) {
        if (PersonajePrincipal->collidesWithItem(listaFrutaBurbuja.at(i))){
            scene->removeItem(listaFrutaBurbuja.at(i));
            listaFrutaBurbuja=modificarFrutaBurbuja(listaFrutaBurbuja,i);
            Puntos->incrementar();



            }
    }
//Condicion para que el personaje pase de nivel
    if(nivelActual == 1){
    if (PersonajePrincipal->collidesWithItem(naverickmorty)){
    scene->addItem(portalRickMorty);//Condicion 1 para que el personaje pase del nivel 1 a 2
    }
    if (PersonajePrincipal->collidesWithItem(portalRickMorty)){
        if(Puntos->obtenerPuntos()>=2000){//Condicion 2 para que el personaje pase del nivel 1 a 2
    //Se guarda automaticamente el puntaje luego de que se supero los 2000 puntos esto para cargar partida
            if(puedoguardar==0)
            {   //cout<<nivelActual<<"Aqui";
                //cout<<Puntos->obtenerPuntos();
                //Se escribe en el archivo guardar el cual es el fichero con permisos de escritura
                ofstream Fichero;
                Fichero.open("guardar.txt",ios::out| ios::app);//Se abre el archivo
                Fichero<<nombre.toStdString()<<" "<<to_string(nivelActual)<<" "<<to_string(Puntos->obtenerPuntos())<<endl;
                Fichero.close();//Se cierra el archivo
                puedoguardar=0;
            }
            puedoguardar=0;

            nivelActual +=1;//Se suma 1 y se asciende al segundo nivel
            scene->removeItem(portalRickMorty);//Se remueve el portal de escena
            timerEnemigos->stop();//Se para el timer de enemigos

            segundoNivel();//El personaje esta en el segundo nivel
        }


    }
    }
    if(nivelActual == 2){
    if (PersonajePrincipal->collidesWithItem(portalRickMorty)){
        if(Puntos->obtenerPuntos()>=5000){//Condicion para que pueda ganar el jugador
         timerMoscas->stop();//Se para la creacion de moscas
         timer2Moscas->stop();//Se para el tiempo de aparicion
            nivelCasa();//Gano el usuario
        }
    }
    }
    }
    }


//Esta Funcion activa la Gravedad del personaje
void MainWindow::activaG(){
    bool colisiono=false;//Booleano que dice si colisiono el personaje con la plataforma
        bool sube = true;//Si esta saltando o no

        for (int i = 0; i<listaPlataformas.size(); i++) {//Se itera en la lista de plataformas
            if (PersonajePrincipal->collidesWithItem(listaPlataformas.at(i))){//Se revisa si esta colisionando o no
                if (PersonajePrincipal->getEnTierra()==false){//Si el personaje esta en tierra o no
                    PersonajePrincipal->choque();//Si no esta esta en tierra choca
                    for(int i = 0; i < listaPlataformas.size(); i++){//Se itera en la lista de plataformas
                        if(PersonajePrincipal->collidesWithItem(listaPlataformas.at(i))){//Se revisa si esta colisionando o no
                            if(PersonajePrincipal->y()-65 <= listaPlataformas.at(i)->y()//Si choca por debajo
                                 && PersonajePrincipal->y()-65 > listaPlataformas.at(i)->y()-20){
                                PersonajePrincipal->setPosy(PersonajePrincipal->getPosy()+10);//Se pone el personaje 10 pixeles por debajo de la plataforma
                                PersonajePrincipal->setPos(PersonajePrincipal->getPosx(),PersonajePrincipal->getPosy());
                                sube=false;//No sube
                            } else {
                                PersonajePrincipal->setPosy(listaPlataformas.at(i)->posy()-listaPlataformas.at(i)->getAlto()-10);
                                PersonajePrincipal->setPos(PersonajePrincipal->getPosx(),PersonajePrincipal->getPosy());

                            }

                        }
                    }
                }
                colisiono=true;
           }}
        //Actualizacion del personaje en todo instante de tiempo
        if (colisiono==false){PersonajePrincipal->setEnTierra(false);}//Si no colisiono el personaje esta en el aire
        if (sube==false){PersonajePrincipal->setEnTierra(false);}//Si el personaje no esta subiendo hace que baje
        if(PersonajePrincipal->getEnTierra()==false){//si el personje no esta en tierra se activa la caida libre
            PersonajePrincipal->caidaLibre();
        }
}
//Funcion que permite al personaje Saltar
void MainWindow::activaSalto()
{//Esto se realizo para que no salte dos o mas veces
    for (int i = 0; i<listaPlataformas.size(); i++) {
        //Si esta colisionado con las plataforma significa que aun no ha saltado
        if (PersonajePrincipal->collidesWithItem(listaPlataformas.at(i))){
            PersonajePrincipal->setSaltando(false);
            PersonajePrincipal->setTiempo(0);//indica el tiempo=0 que esta quieto
       }
    }
    PersonajePrincipal->saltar();//se activa la funcion salto
}

//Funcion que actualiza el sprite de la FrutaBurbuja
void MainWindow::actualizar_frutaburbuja()
{
    for(int i=0; i<listaFrutaBurbuja.count();i++){
        listaFrutaBurbuja[i]->sprite_burbuja();
    }

}
//Funcion que actualiza la cantidad de vidas que hay en escena
void MainWindow::actualizar_vida()
{
    // si el personaje esta en el nivel 1 y colisiona con un enemigo sin antes matarlo ,pierde vida
    if (nivelActual==1){
    for (int i = 0; i<enemigos.count(); i++){
       if (PersonajePrincipal->collidesWithItem(enemigos.at(i))){
           scene->removeItem(listaVida.at(0));//Se remueve la vida de escena
               listaVida=modificarVida(listaVida,0);
       if(listaVida.count()==0){
          muerte();//Si la lista esta vacia se invoca la funcion muerte
       }
       }
    }
    }
    // si el personaje esta en el nivel 1 y colisiona con un enemigo sin antes matarlo ,pierde vida
    else if(nivelActual==2){
        for (int i = 0; i<moscas.count(); i++){
           if (PersonajePrincipal->collidesWithItem(moscas.at(i))){
               scene->removeItem(listaVida.at(0));//Se remueve la vida de escena
                listaVida=modificarVida(listaVida,0);
           if(listaVida.count()==0){
               muerte();//Si la lista esta vacia se invoca la funcion muerte


           }

           }}

        for (int i = 0; i<enemigos.count(); i++){
           if (PersonajePrincipal->collidesWithItem(enemigos.at(i))){
               scene->removeItem(listaVida.at(0));
                   listaVida=modificarVida(listaVida,0);
           if(listaVida.count()==0){
              muerte();

           }

           }}
    }

}
//Funcion que actualiza la posicion del portal
void MainWindow::actualizar_portal()
{

  portalRickMorty->ActualizarPosicionPortal();

}
//Funcion que actualiza el movimiento de las moscas
void MainWindow::actualizarMoscas()
{
    if(moscas.size()!=0){//verificar que la lista de moscas sea difeferente de 0

        for (int i=0;i<moscas.size();i++) {//recorrer la lista de moscas
        moscas.at(i)->actual(v_limit);//a la x moscas se recalcula su posicion
        bordedelete(moscas.at(i));//verificar si la mosca x esta tocando el borde para eliminarla
    }

    }



    if(moscas.size()==0 && Multijugador==true){//si la lista de la mos es 0 y estamos en el multijugador

        banderaMulti=true;//se activa la bandera del multijugador
        if(banderaMulti==true){//si la bandera es verdadera
            contadorMulti++;//sumamos 1 al contador

            if(contadorMulti==1){//verificar si el contador es 1

                puntosJ1=Puntos->obtenerPuntos();//asignamos los puntos realizados a la variable de puntos de jugador 1
                //qDebug() << puntosJ1;
                listaPlataformas.clear();//limpiamos la lista de las plataformas
                listaFrutaBurbuja.clear();//limpiamos la lista de las frutas
                timercaida->stop();//paramos el timer de caida
                timerfrutaburbuja->stop();//paramos el timer de las frutas
                timerMoscas->stop();//paramos el timer de las moscas
                timer2Moscas->stop();//paramos el timer de las moscas
                Puntos->reiniciarpuntos();//reiniciamos los puntos del contador
                val=0;//variable igual a 0 para que salgan las moscas para el proximo jugador
                Mensaje.setText("TURNO DEL JUGADOR 2");//mensaje de aviso para el jugador 2
                Mensaje.setInformativeText("");// espacion en el mensaje
                Mensaje.exec();//recuerdo
                on_bottonMultijugador_clicked();//reiniciamos el multijugador
             }

            else if(contadorMulti==2){//verificamos si el contador es 2

                puntosJ2=Puntos->obtenerPuntos();//asignamos los puntos realizados a la variable de puntos de jugador 2
                //qDebug() << puntosJ2;
                listaPlataformas.clear();//limpiamos la lista de las plataformas
                listaFrutaBurbuja.clear();//limpiamos la lista de las frutas
                timercaida->stop();//paramos el timer de caida
                timerfrutaburbuja->stop();//paramos el timer de las frutas
                timerMoscas->stop();//paramos el timer de las moscas
                timer2Moscas->stop();//paramos el timer de las moscas
                Puntos->reiniciarpuntos();//reiniciamos los puntos del contador
                if(puntosJ1<puntosJ2){//si el jugador 2 tiene mas puntos que el 1
                    Mensaje.setText("EL GANADOR ES EL JUGADOR 2");//mensaje de ganar
                    Mensaje.setInformativeText("");
                    Mensaje.exec();}
                if(puntosJ1>puntosJ2){//si el jugador 1 tiene mas puntos que el 2
                    Mensaje.setText("EL GANADOR ES EL JUGADOR 1");//mensaje de ganar
                    Mensaje.setInformativeText("");
                    Mensaje.exec();}
                if(puntosJ1==puntosJ2){// si hicieron la misma cantidad de puntos
                    Mensaje.setText("EMPATADOS");//mensaje de empatados
                    Mensaje.setInformativeText("");
                    Mensaje.exec();}
                nivelCasa();// se llama la funcion luego de terminar el juego


            }
        }
    }


}
//Funcion que crea las moscas
void MainWindow::crearMoscas()
{
    //empezamos acrear moscas
    if( val<50){//no se crean mas de 50 moscas
        val++;//aumentar la variable del condicionla
    banderaMosca=!banderaMosca;//bandera para cambiar el sentido de las moscas
    moscas.push_back(new spritemoscas(banderaMosca));//agregamos la mosca creadad a la lista de moscas
    scene->addItem(moscas.back());//agregar la ultima mosca a la scena
 }
}

//Funcion que cargar el vector de gusanos ,con el rango el cual se van a mover
void MainWindow::cargarPosgusano(int nivel)	{
    std::fstream archivo;//para usar las funciones de strem
    if (nivel==1){//si estamos en el nivel 1
        archivo.open("posGusanos.txt",std::ios::in);}//leer el archivo
     else if(nivel==2){//si estamos en el nivel 2
     archivo.open("posGusanos2.txt",std::ios::in);}//leer el archivo
     //iteremos sobre el archivo
     short int posx1, posx2;//variables cortas para usar en el archivo

     while(!archivo.eof()){//recorrer el archivo hasta que sea la ultima linea
         archivo >> posx1 >> posx2;//asignar las posciones del archivo a las variables
         // guardar las posiciones en el Qvector
         V_posgusanos.push_back(posx1);
         V_posgusanos.push_back(posx2);
      //qDebug()<<V_posgusanos;


     }
     archivo.close();//cerramos el archivo
}
//Funcion que contiene el segundo Nivel

void MainWindow::segundoNivel()
{
    ui->graphicsView->setFocus();
    bandera=true;
    //Se esconden los botones
    ui->bottonReiniciar->hide();
    ui->label->hide();
    ui->label_2->hide();
    ui->pushButton->hide();
    ui->bottonUsurario->hide();
    ui->pushButton_2->hide();
    ui->lineEdit->hide();
    ui->eliminarPartida->hide();
    ui->cargarPartida->hide();
    ui->radioButton->hide();
    ui->radioButton_2->hide();
    ui->pushButton_3->hide();
    //Se vuelve a crear la escena con otra fondo
    scene = new QGraphicsScene;
    scene->setSceneRect(0,0,960,519);
    scene->setBackgroundBrush(QImage(":/Imagenes/Escenario2.png"));
    ui->graphicsView->setScene(scene);
    //Se realiza limpieza de listas
    listaPlataformas.clear();
    listaFrutaBurbuja.clear();
    enemigos.clear();
    //Se limpia el vector
    V_posgusanos.clear();
    //Se vuelven a poner los objetos en nuevas posiciones
    PersonajePrincipal = new CuerpoPersonajeJugador(90,50,escogerPersonaje);
    scene->addItem(PersonajePrincipal);
    PersonajePrincipal->setScale(0.4);
    for (int i = 0; i<listaVida.count(); i++){
        scene->addItem(listaVida.at(i));}
    //Plataformas
    plataformaInicialPosicion = new Plataforma(70,130);listaPlataformas.push_back(plataformaInicialPosicion);scene->addItem(plataformaInicialPosicion);
    plataforma2=new Plataforma(210,180);listaPlataformas.push_back(plataforma2);scene->addItem(plataforma2);
    plataforma3 =new Plataforma(350,230);listaPlataformas.push_back(plataforma3);scene->addItem(plataforma3);
    plataforma4 =new Plataforma(490,280);listaPlataformas.push_back(plataforma4);scene->addItem(plataforma4);
    plataforma5 =new Plataforma(630,330);listaPlataformas.push_back(plataforma5);scene->addItem(plataforma5);
    plataforma6 =new Plataforma(770,400);listaPlataformas.push_back(plataforma6);scene->addItem(plataforma6);
    //FrutasBurbujas
    fruta1= new frutaBurbuja(); scene->addItem(fruta1);fruta1->setPos(210,140);listaFrutaBurbuja.push_back(fruta1);
    fruta2= new frutaBurbuja(); scene->addItem(fruta2);fruta2->setPos(350,190);listaFrutaBurbuja.push_back(fruta2);
    fruta3= new frutaBurbuja(); scene->addItem(fruta3);fruta3->setPos(490,240);listaFrutaBurbuja.push_back(fruta3);
    fruta4= new frutaBurbuja(); scene->addItem(fruta4);fruta4->setPos(630,290);listaFrutaBurbuja.push_back(fruta4);
    fruta5= new frutaBurbuja(); scene->addItem(fruta5);fruta5->setPos(770,360);listaFrutaBurbuja.push_back(fruta5);
    //EnemigosGusanos
    enemigo1= new spritegusano(true, 0,460);scene->addItem(enemigo1);enemigo1->setScale(0.4);enemigos.push_back(enemigo1);
    enemigo2= new spritegusano(true, 500,460);scene->addItem(enemigo2);enemigo2->setScale(0.4);enemigos.push_back(enemigo2);
    enemigo3= new spritegusano(true, 250,460);scene->addItem(enemigo3);enemigo3->setScale(0.4);enemigos.push_back(enemigo3);
    enemigo4= new spritegusano(false, 800,460);scene->addItem(enemigo4);enemigo4->setScale(0.4);enemigos.push_back(enemigo4);
    enemigo5= new spritegusano(false, 650,460);scene->addItem(enemigo5);enemigo5->setScale(0.4);enemigos.push_back(enemigo5);
    enemigo6= new spritegusano(false, 150,460);scene->addItem(enemigo6);enemigo6->setScale(0.4);enemigos.push_back(enemigo6);

    cargarPosgusano(nivelActual);//Funcion para cargas las posiciones de los gusanos
    portalRickMorty=new  Portal(70,430,20,1);
    scene->addItem(portalRickMorty);
    timerEnemigos = new QTimer();
    connect(timerEnemigos,SIGNAL(timeout()),this,SLOT(moveEnemy()));
    timerEnemigos->start(100);
    if(listaVida.size()==0){
    timerVida = new QTimer();
    connect(timerVida,SIGNAL(timeout()),this,SLOT(actualizar_vida()));
    timerVida->start(800);
    vida1=new Vida(420,30);listaVida.push_back(vida1);scene->addItem(vida1);
    vida2=new Vida(450,30);listaVida.push_back(vida2);scene->addItem(vida2);
    vida3=new Vida(480,30);listaVida.push_back(vida3);scene->addItem(vida3);
    vida4=new Vida(510,30);listaVida.push_back(vida4);scene->addItem(vida4);
    vida5=new Vida(540,30);listaVida.push_back(vida5);scene->addItem(vida5);
    }
    //Se limita la pantalla para saber cuando se eliminan las moscas
    h_limit=960;//limite de la pantalla horizontal
    v_limit=519;//limite vertical
    //Timers de aparicion de moscas y movimiento de las moscas
    timerMoscas=new QTimer();
    timer2Moscas=new QTimer();
    //Se centra la pantalla
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
    scene->addItem(Puntos);


}
//Funcion que contiene el nivel Casa
void MainWindow::nivelCasa()
{
    nivelActual+=1;
    ui->label->show();
    ui->bottonJugar->hide();
    ui->pushButton->hide();
    ui->label_2->hide();
    ui->pushButton_3->hide();
    ui->bottonInstrucciones->hide();
    ui->bottonMultijugador->hide();
    ui->bottonReiniciar->hide();
    ui->radioButton->hide();
    ui->radioButton_2->hide();
    //Se limpian las listas
    listaVida.clear();
    listaPlataformas.clear();
    listaFrutaBurbuja.clear();
    enemigos.clear();
    timerMoscas->stop();
    timer2Moscas->stop();
    //Se crea una nueva escena con otro fondo
    scene = new QGraphicsScene;
    scene->setSceneRect(0,0,960,519);
    scene->setBackgroundBrush(QImage(":/Imagenes/Tierra.png"));
    //Se agrega una imagen en movimiento en un QLabel y la clase Movie
    ui->graphicsView->setScene(scene);
    QMovie *movie=new QMovie(":/Imagenes/LlegamosCasa.gif");
    ui->label->setMovie(movie);
    movie->start();//Se reproduce la Imagen

}
//Funcion que contiene el primer nivel
void MainWindow::primerNivel()
{
    nivelActual = 1;

    Multijugador=false;
        bandera=true;
        scene = new QGraphicsScene;
        ui->label_2->hide();

        ui->graphicsView->setScene(scene);
        ui->graphicsView->setFocus();//Se agregan los botones salir y reiniciar a escena
        //Se ocultan todos los botones ,labels y linedit
        ui->pushButton->hide();
        ui->bottonJugar->hide();
        ui->label->hide();
        ui->bottonInstrucciones->hide();
        ui->bottonMultijugador->hide();
        ui->pushButton_2->hide();
        ui->bottonUsurario->hide();
        ui->lineEdit->hide();
        ui->eliminarPartida->hide();
        ui->cargarPartida->hide();
        ui->radioButton->hide();
        ui->radioButton_2->hide();
        ui->bottonReiniciar->show();
        ui->pushButton_3->hide();
        ui->radioButton->hide();
        ui->radioButton_2->hide();
        //Se agrega el personaje a la escena
        PersonajePrincipal = new CuerpoPersonajeJugador(90,50,escogerPersonaje);
        scene->addItem(PersonajePrincipal);
        PersonajePrincipal->setScale(0.4);
        //Dimensiones de la escena y el fondo de la escena
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
        timercaida = new QTimer();
        connect(timercaida,SIGNAL(timeout()),this,SLOT(activaG()));
        timercaida->start(30);
        //Timer vida,el cual se pierde una vida luego de un tiempo de estar colisionando con un enemigo
        timerVida = new QTimer();
        connect(timerVida,SIGNAL(timeout()),this,SLOT(actualizar_vida()));
        timerVida->start(800);
        vida1=new Vida(420,30);listaVida.push_back(vida1);scene->addItem(vida1);
        vida2=new Vida(450,30);listaVida.push_back(vida2);scene->addItem(vida2);
        vida3=new Vida(480,30);listaVida.push_back(vida3);scene->addItem(vida3);
        vida4=new Vida(510,30);listaVida.push_back(vida4);scene->addItem(vida4);
        vida5=new Vida(540,30);listaVida.push_back(vida5);scene->addItem(vida5);

        //NAVE Y PORTAL PRIMER NIVEL
        naverickmorty= new nave(600,110);scene->addItem(naverickmorty);
        portalRickMorty=new  Portal(70,430,20,1);
        timerportalRickMorty = new QTimer();
        connect(timerportalRickMorty,SIGNAL(timeout()),this,SLOT(actualizar_portal()));
        timerportalRickMorty->start(200);
        naverickmorty->setScale(0.5);
        //PLATAFORMAS PRIMER NIVEL
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

        timerfrutaburbuja = new QTimer();
        connect(timerfrutaburbuja,SIGNAL(timeout()),this,SLOT(actualizar_frutaburbuja()));
        timerfrutaburbuja->start(150);
        scene->addItem(Puntos);//Se agregan los puntos a escena
}
//Funcion muerte
void MainWindow::muerte()
{
    QMessageBox mensaje;
    mensaje.setIconPixmap(QPixmap(":/Imagenes/mortyllorando.gif"));
    mensaje.show();
    mensaje.exec();
    QApplication::quit();
}

//Funcion que le proporciona el movimiento lineal a los gusanos
void MainWindow::moveEnemy()
{
    QList<QGraphicsItem*> itemList = scene->items();//Qlist de los items de la scena


    for (int j = 0; j<enemigos.size(); j++){//recorrer la lista de enemigos

        spritegusano *enemigo = enemigos.at(j);/* creo un enemigo de la clase gusado y le asigno su valor segun
                                                  la posicion j que recorre la Qlist de enemigo */

        if (enemigo->bande==true){//si la vandera de enemigo es verdadero
            if(enemigo->x()>V_posgusanos[j*2]){//verificar la posicion de enemigos es mayor a la pos de gusano
            //qDebug()<<"V_posgusanos[j]*2"<<V_posgusanos[j*2];//imprimir posx1 del gusano n
                enemigo->left(3);//mover enemigo
            }
            else
            enemigo->bande=false;}//cambiar la bandera de mov de enemigo
        else{
            if(enemigo->x()<V_posgusanos[j*2+1]){//verificar la posicion de enemigos es menor a la pos de gusano
                //qDebug()<<"V_posgusanos[j]*2+1"<<V_posgusanos[j*2+1];//imprimir posx2 del gusano n
                enemigo->right(3);//mover enemigo
            }
            else
            enemigo->bande=true;//cambiar la bandera de mov de enemigo
        }

}

    for (int i = 0; i<enemigos.size();i++){//recorrer la lista de gusanos
        spritegusano *enemigo = enemigos.at(i);//asignar el gusano
        if(!itemList.contains((QGraphicsItem*)enemigo)){//FFF
            enemigos.removeOne(enemigo);//remover el enemigo
            V_posgusanos.removeAt((i*2)+1);//remover la poscion del gusano en el Qvector
            //qDebug()<<V_posgusanos;
            V_posgusanos.removeAt(i*2);//remover la poscion del gusano en el Qvector
            //qDebug()<<V_posgusanos;

            Puntos->incrementar();//aumentar los puntos
            break;//cerrar el ciclo
        }
    }

    for (int i = 0; i<moscas.size();i++){//recorrer la lista de las moscas
        spritemoscas *enemigoMosca = moscas.at(i);//asignar la mosca
        if(!itemList.contains((QGraphicsItem*)enemigoMosca)){//FF
            moscas.removeOne(enemigoMosca);//remover las moscas

            Puntos->incrementar();//incrementar puntos
            break;//cerrar el ciclo
        }
    }

    }


//Funcion slot Jugar
void MainWindow::on_bottonJugar_clicked()
{
    //Se esconden todos los botones excepto LineEdit y Usuario
    ui->bottonJugar->hide();
    ui->bottonInstrucciones->hide();
    ui->bottonMultijugador->hide();
    ui->radioButton->hide();
    ui->label->hide();
    ui->label_2->hide();
    ui->radioButton_2->hide();
    ui->lineEdit->show();
    ui->bottonUsurario->show();

}
//Funcion Instruciones
void MainWindow::on_bottonInstrucciones_clicked()
{
    //Se esconden todos los botones y se muestra un label con una imagen en el
        ui->pushButton_3->hide();
        ui->pushButton->show();
        ui->bottonJugar->hide();
        ui->bottonInstrucciones->hide();
        ui->bottonMultijugador->hide();
        ui->radioButton->hide();
        ui->radioButton_2->hide();
        ui->label_2->show();
        ui->bottonMultijugador->hide();
}

//Funcion multijugador ,el cual es por turnos
void MainWindow::on_bottonMultijugador_clicked()
{
    //para el keypress
        nivelActual=3;//para el keyevent
        banderaMulti=false;//Bandera del multijugador
        bandera=true;//bandera para el keypress
        if (contadorMulti==0){//contador del multijugador para avisar turno del jugador 1
            Mensaje.setText("TURNO DEL JUGADOR 1");//mensaje en recuadro para el mensaje 1
            Mensaje.setInformativeText("");
            Mensaje.exec();
        }
        Multijugador=true;//bandera del multijugador
        //Se esconden botones
        ui->label->hide();
        ui->label_2->hide();
        ui->lineEdit->hide();
        ui->bottonJugar->hide();
        ui->bottonMultijugador->hide();
        ui->bottonUsurario->hide();
        ui->bottonInstrucciones->hide();
        ui->cargarPartida->hide();
        ui->eliminarPartida->hide();
        ui->pushButton_2->hide();
        ui->bottonReiniciar->hide();
        ui->radioButton->hide();
        ui->radioButton_2->hide();

        //Se crea la escena con un nuevo fondo
        scene = new QGraphicsScene;//nueva scena para el mapa
        scene->setSceneRect(0,0,960,519);//dimenciones del mapa
        scene->setBackgroundBrush(QImage(":/Imagenes/Escenario2.png"));//imagen de la scena
        ui->graphicsView->setScene(scene);
        ui->graphicsView->setFocus();
        //Se limpian las listas
        listaPlataformas.clear();
        listaFrutaBurbuja.clear();
        enemigos.clear();
        //Se agregan los personajes
        PersonajePrincipal = new CuerpoPersonajeJugador(500,150,escogerPersonaje2);//crear personaje
        scene->addItem(PersonajePrincipal);//agregar personaje a la scena
        PersonajePrincipal->setScale(0.4);//scalar personajes
        escogerPersonaje2+=1;//escoger personaja
        //Plataformas MULTIJUGADOR
        plataformaInicialPosicion = new Plataforma(300,420);listaPlataformas.push_back(plataformaInicialPosicion);scene->addItem(plataformaInicialPosicion);// crear plataforma, agregar plataforma a la lista, agregar a la scena
        plataforma2=new Plataforma(500,200);listaPlataformas.push_back(plataforma2);scene->addItem(plataforma2);// crear plataforma, agregar plataforma a la lista, agregar a la scena
        plataforma3 =new Plataforma(700,420);listaPlataformas.push_back(plataforma3);scene->addItem(plataforma3);// crear plataforma, agregar plataforma a la lista, agregar a la scena
        //FrutasBurbujas MULTIJUGADOR
        fruta1= new frutaBurbuja(); scene->addItem(fruta1);fruta1->setPos(50,450);listaFrutaBurbuja.push_back(fruta1);// crear fruta, agregar fruta a la lista, agregar a la scena
        fruta2= new frutaBurbuja(); scene->addItem(fruta2);fruta2->setPos(150,450);listaFrutaBurbuja.push_back(fruta2);// crear fruta, agregar fruta a la lista, agregar a la scena
        fruta3= new frutaBurbuja(); scene->addItem(fruta3);fruta3->setPos(250,450);listaFrutaBurbuja.push_back(fruta3);// crear fruta, agregar fruta a la lista, agregar a la scena
        fruta4= new frutaBurbuja(); scene->addItem(fruta4);fruta4->setPos(350,450);listaFrutaBurbuja.push_back(fruta4);// crear fruta, agregar fruta a la lista, agregar a la scena
        fruta5= new frutaBurbuja(); scene->addItem(fruta5);fruta5->setPos(450,450);listaFrutaBurbuja.push_back(fruta5);// crear fruta, agregar fruta a la lista, agregar a la scena
        fruta6= new frutaBurbuja(); scene->addItem(fruta6);fruta6->setPos(550,450);listaFrutaBurbuja.push_back(fruta6);// crear fruta, agregar fruta a la lista, agregar a la scena
        fruta7= new frutaBurbuja(); scene->addItem(fruta7);fruta7->setPos(650,450);listaFrutaBurbuja.push_back(fruta7);// crear fruta, agregar fruta a la lista, agregar a la scena
        fruta8= new frutaBurbuja(); scene->addItem(fruta8);fruta8->setPos(750,450);listaFrutaBurbuja.push_back(fruta8);// crear fruta, agregar fruta a la lista, agregar a la scena
        fruta9= new frutaBurbuja(); scene->addItem(fruta9);fruta9->setPos(850,450);listaFrutaBurbuja.push_back(fruta9);// crear fruta, agregar fruta a la lista, agregar a la scena
        fruta10= new frutaBurbuja(); scene->addItem(fruta10);fruta10->setPos(920,450);listaFrutaBurbuja.push_back(fruta10);// crear fruta, agregar fruta a la lista, agregar a la scena

        timerfrutaburbuja = new QTimer();
        connect(timerfrutaburbuja,SIGNAL(timeout()),this,SLOT(actualizar_frutaburbuja()));//actualizar sprite de las frutas
        timerfrutaburbuja->start(150);

        //Caida Libre
        timercaida = new QTimer();
        connect(timercaida,SIGNAL(timeout()),this,SLOT(activaG()));
        timercaida->start(30);

        // limites de la pantalla
        h_limit=960;//limite de la pantalla horizontal
        v_limit=519;//limite vertical
        //scene->setSceneRect(0,0,h_limit,v_limit);
        ui->centralwidget->adjustSize();
        scene->addRect(scene->sceneRect());
        ui->graphicsView->resize(scene->width(),scene->height());
        this->resize(ui->graphicsView->width()+100,ui->graphicsView->height()+100);

        //timer de los enemigos  y enemigos (Moscas)
        moscas.push_back(mosca1 = new spritemoscas(banderaMosca)); scene->addItem(moscas.back());//crear moscas y agregar a la scena
        moscas.push_back(mosca2 = new spritemoscas(!banderaMosca)); scene->addItem(moscas.back());//crear moscas y agregar a la scena

        timerMoscas=new QTimer();//crear timer
        timer2Moscas=new QTimer();//crear timer
        timerMoscas->start(1000);//timer de aparicion de las moscas
        timer2Moscas->start(25);//mov de las moscas
        connect(timerMoscas,SIGNAL(timeout()),this,SLOT(crearMoscas()));//crear moscas
        connect(timer2Moscas,SIGNAL(timeout()),this,SLOT(actualizarMoscas()));//actualizar mov de las mocas
        mosca=new spritemoscas(true);// crear la primera moscas para la lista asi se puede activar la de actualizar
        moscas.push_back(mosca);//agrego mosca en la lista

        //aqui esta el incremento de puntos para las moscas
        timerEnemigos = new QTimer();
        timerEnemigos->start(100);
        connect(timerEnemigos,SIGNAL(timeout()),this,SLOT(moveEnemy()));

        //puntos
        scene->addItem(Puntos);


}
//Funcion donde se escoge a Rick en modo Jugador1
void MainWindow::on_radioButton_2_clicked()
{
    escogerPersonaje=1;//Rick

}
//Funcion donde se escoge a Morty en modo Jugador1
void MainWindow::on_radioButton_clicked()
{
    escogerPersonaje=2;//Morty

}


void MainWindow::on_pushButton_clicked()
{   ui->bottonMultijugador->hide();
    ui->bottonJugar->show();
    ui->bottonInstrucciones->show();
    ui->bottonUsurario->hide();
    ui->pushButton_3->show();
    ui->lineEdit->hide();
    ui->label_2->hide();
    ui->pushButton->hide();
    music->play();


}
//Funcion donde se registra el usuario
void MainWindow::on_bottonUsurario_clicked()
{   nombre=ui->lineEdit->text();
    //Variables del archivo
    string nombrePos;
    string nivelPos;
    string puntosPos;
    ifstream archivo;
    archivo.open("guardar.txt",ios::out| ios::app);//Se crea el archivo si no se ha creado
    archivo.close();//Se cierra el archivo
    archivo.open("guardar.txt");//Se abre el archivo para verificar si se creo en el caso de que no este
    //Se leera el archivo
    while(!archivo.eof())
    {
        //Se guardan estos parametros en el archivo
        archivo>>nombrePos;//Nombre del usuario
        archivo>>nivelPos;//Nivel del usuario
        archivo>>puntosPos;//Puntos mayores de 2000 del usuario
        //Condicion para saber si el usuario fue creado
        if(nombrePos==nombre.toStdString())
        {
            puedoguardar++;
            qDebug()<<puedoguardar;
            if(puedoguardar==1)
            {
                msgBox.setText(nombre);
                msgBox.setInformativeText("YA EL USUARIO FUE CREADO, SI QUIERES GUARDAR PARTIDA ELIMINA EL PROCESO Y CREA NUEVAMENTE EL USUARIO ");
                msgBox.exec();
            }
        }
    }
    archivo.close();//Se cierra el archivo
    //Se esconden botones
    ui->label->hide();
    ui->label_2->hide();
    ui->lineEdit->hide();
    ui->bottonUsurario->hide();
    ui->bottonReiniciar->hide();
    ui->pushButton->hide();
    ui->bottonJugar->hide();
    ui->bottonInstrucciones->hide();
    //Se muestran los botones
    ui->eliminarPartida->show();
    ui->cargarPartida->show();
    ui->bottonMultijugador->show();
    ui->pushButton_2->show();
    ui->radioButton->show();
    ui->radioButton_2->show();

}


void MainWindow::on_bottonReiniciar_clicked()
{
    ui->bottonMultijugador->hide();
    //Se limpian listas
    listaVida.clear();
    listaPlataformas.clear();
    listaFrutaBurbuja.clear();
    V_posgusanos.clear();
    enemigos.clear();
    //Se paran timers
    timerVida->stop();
    timercaida->stop();
    timerEnemigos->stop();
    timerportalRickMorty->stop();
    timerfrutaburbuja->stop();
    //Se reinicia el sistema de puntos
    Puntos->reiniciarpuntos();
    //Se carga nuevamente el primer nivel
    primerNivel();

}
//Funcion 1 Jugador
void MainWindow::on_pushButton_2_clicked()
{   if(escogerPersonaje==1 || escogerPersonaje==2){//Condicion para jugar en este modo
    ui->label_2->hide();//Se oculta el boton
    ui->bottonJugar->hide();//Se oculta el boton
    primerNivel();//Se carga el primer nivel

    }

    else{
        //Mensaje informativo
        Mensaje.setText("DEBES ESCOGER UN PERSONAJE PARA JUGAR");
        Mensaje.setInformativeText("");
        Mensaje.exec();

    }

}

void MainWindow::on_cargarPartida_clicked()
{
    bool existePartida = false;
    cout<<"1Cargarr";
    if(escogerPersonaje==1 || escogerPersonaje==2){//Condicion para Jugar en CargarPartida
        //Variables de lectura
        string nombrePos;
        string nivelPos;
        string puntosPos;
        ifstream archivo;
        archivo.open("guardar.txt");//Se abre el archivo
        cout<<"2";
        while(!archivo.eof())
        {
            archivo>>nombrePos;
            archivo>>nivelPos;
            archivo>>puntosPos;
            cout<<"3";
            if(nombrePos==nombre.toStdString())
            {
                nivelActual = stoi(nivelPos)+1;//Se pone al personaje en nivel 2
                Puntos->asignarPuntos(stoi(puntosPos));//Se convierten los puntos en int
                existePartida=true;//Se verifica que exista la partida
                //Se ponen a correr los timers
                ui->bottonMultijugador->hide();
                timercaida = new QTimer();
                connect(timercaida,SIGNAL(timeout()),this,SLOT(activaG()));
                timercaida->start(30);
                timerfrutaburbuja = new QTimer();
                connect(timerfrutaburbuja,SIGNAL(timeout()),this,SLOT(actualizar_frutaburbuja()));
                timerfrutaburbuja->start(150);
                timerportalRickMorty = new QTimer();
                connect(timerportalRickMorty,SIGNAL(timeout()),this,SLOT(actualizar_portal()));
                timerportalRickMorty->start(200);
                //Se carga desde el segundo nivel
                segundoNivel();
            }
        }
        archivo.close();//Se cierra el archivo
        cout<<"4";
        if(existePartida==false){//Condicion en caso tal que el usuario no haya jugado

            Mensaje.setText("DEBES HABER JUGADO EN MODO: 1 JUGADOR");
            Mensaje.setInformativeText("");
            Mensaje.exec();

        }
    } else{
        Mensaje.setText("DEBES ESCOGER UN PERSONAJE PARA JUGAR");
        Mensaje.setInformativeText("");
        Mensaje.exec();

    }

}

void MainWindow::on_eliminarPartida_clicked()
{

        string line;
        //Nombre del archivo en lectura y escritura
        ifstream fin;
        ofstream temp;
        //Varibles de lectura
        string nombrePos;
        string nivelPos;
        string puntosPos;
        ifstream archivo;
        archivo.open("guardar.txt");//Se abre el archivo
        int contLinea=0;//Se inicializa el contador de filas
        bool encontrado=false;//Booleano que verifica si se encontro o no la fila
        while(!archivo.eof())//Se lee el archi hasta la ultima linea
        {
            archivo>>nombrePos;
            archivo>>nivelPos;
            archivo>>puntosPos;
            if(nombrePos==nombre.toStdString())//Si el nombre se encontro el booleano es true y se puede eliminar la partida
            {
                encontrado=true;

            }

            if(encontrado==false){//Si el booleano no se encontro el contador suma 1 y verifica en las demas filas
                contLinea+=1;
            }
        }
        archivo.close();//Se cierra el archivo
        fin.open("guardar.txt");//Se abre el archivo luego de verificar si esta o no
        temp.open("temp.txt",ios::out| ios::app);//Se abre otro archivo temporal el cual guardara la misma informacion de guardar
        int deleteline=0;//contador de lineas
        while (getline(fin,line))
        {
            if (contLinea != deleteline){//Condicion para que se pueda eliminar la linea
                temp << line << endl;}
                deleteline+=1; }
        temp.close();//se cierra el archivo temporal
        fin.close();//Se cierra el archivo guardar
        remove("guardar.txt");//Se remueve guardar
        rename("temp.txt", "guardar.txt");//Se cambia el nombre de temporal por guardar
}
//Funcion Salir
void MainWindow::on_salir_clicked()
{   //Mensaje informativo
    Mensaje.setText("HAS DECIDO SALIRTE DEL JUEGO,NOS VEMOS LA PROXIMA VIAJERO");
    Mensaje.setInformativeText("");
    Mensaje.exec();
    QApplication::quit();//Se quita la aplicacion
}
//Funcion Silenciar
void MainWindow::on_pushButton_3_clicked()
{
    if(nivelActual==0){music->stop();}

}
//Funciones que no se usaron pero eran necesarias para que aparecieran los Labels y el LineEdit
void MainWindow::on_label_windowTitleChanged(const QString &title)
{

}

void MainWindow::on_label_2_windowTitleChanged(const QString &title)
{

}
void MainWindow::on_lineEdit_windowTitleChanged(const QString &title)
{

}
