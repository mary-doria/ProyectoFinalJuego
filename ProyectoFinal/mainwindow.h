#ifndef MAINWINDOW_H
#define MAINWINDOW_H
#include <QMainWindow>
#include <cuerpopersonajejugador.h>



QT_BEGIN_NAMESPACE
namespace Ui { class MainWindow; }
QT_END_NAMESPACE

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();
private:
    Ui::MainWindow *ui;
    CuerpoPersonajeJugador *PersonajePrincipal;
    QGraphicsScene *scene;
    QTimer *timer;
    void keyPressEvent(QKeyEvent *evento);
};
#endif // MAINWINDOW_H
