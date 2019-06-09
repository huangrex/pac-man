#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QGraphicsScene>
#include <QGraphicsPixmapItem>
#include <QMessageBox>
#include "elf.h"
#include "wall.h"
#include "dots.h"
#include "powerpellets.h"
#include "jessieghost.h"
#include "ghost.h"
#include "wobbuffetghost.h"
#include "mewothghost.h"
#include "jamesghost.h"
namespace Ui {
class MainWindow;
}

class MainWindow : public QMainWindow
{
    Q_OBJECT
private slots:
    void updater();
    void setpix();
    void jessiebeginmove();
    void jessiemove();
    void powerpelletstime();
    void mewothbeginmove();
    void setdifficult();



public:
    explicit MainWindow(QWidget *parent = nullptr);
    ~MainWindow();
    void keyPressEvent(QKeyEvent *event);
    int targetx , targety;
private:
    Ui::MainWindow *ui;
    QGraphicsScene *scene;

    QPen wallpen;
    wall *bwall[900];
    QTimer *pacmantime;
    QTimer *pacmanpix;
    QTimer *jessietime[3];
    QTimer *ghostmove;
    QTimer *time[10];
    int detjessie;
    int stopjessie;
    int stopmewoth;
    int detmewoth;
    int reverse;
    int reversem;

    QPainterPath path;
    int board[31][28];
    dots *dot[500];
    int point; //eat dot point
    int value; //eat ghost point
    powerpellets *powerpellet[50];

    jessieghost *jessie;
    wobbuffetghost *wobbuffet;
    mewothghost *mewoth;
    ghost *james;
    ghost *pac;

    int result;//to determine whether win or lose

};

#endif // MAINWINDOW_H
