#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <QGraphicsScene>
#include <QGraphicsPixmapItem>
#include <QGraphicsItem>
#include <QPen>
#include <QtDebug>
#include "elf.h"
#include "wall.h"
#include <QThread>//sleep
#include <QList>



int wall::number = 0;
int dots::number = 0;
int powerpellets::number = 0;
MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);


    ui->graphicsView->setGeometry(0,0, 700, 775);
    ui->graphicsView->setFixedSize(700,775);
    scene = new QGraphicsScene(5,5,695,770);
    scene->setBackgroundBrush(QBrush(QColor(210,105,30)));
    //this->scene->setSceneRect(0,0,415,460);
    ui->graphicsView->setScene(scene);
    //scene->addPixmap(QPixmap(":/new/prefix1/2"));
    /*QGraphicsPixmapItem a;
    QImage b;
    b.load(":/new/prefix1/blackpoint.png");
    b.scaledToWidth(10000);
    //a.setPixmap(b);
    scene->addPixmap(QPixmap::fromImage(b));*/

    /*
    //wallpen = new wall();
    //draw the outline
    wallpen.setColor(Qt::blue);
    wallpen.setWidth(8);
    scene->addLine(10, 10, 563, 10, wallpen);
    scene->addLine(10, 10, 10, 630, wallpen);
    scene->addLine(10, 630, 563, 630, wallpen);
    scene->addLine(563,10, 563, 630, wallpen);
    */

    //path.addRect(a);
    //QPainter painter;
    //painter.setBrush(Qt::black);
    //painter.fillRect(a, Qt::black);
    //painter.drawPath(path);
    //path.addEllipse(50, 50, 50,50);
    //scene->addPath(path);


    int map[31][28] = {
        0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,
        0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,
        0,2,1,1,1,1,1,0,0,1,1,1,1,1,1,1,1,1,1,0,0,1,1,1,1,1,2,0,
        0,1,0,0,0,0,1,0,0,1,0,0,0,0,0,0,0,0,1,0,0,1,0,0,0,0,1,0,
        0,1,0,0,0,0,1,0,0,1,0,0,0,0,0,0,0,0,1,0,0,1,0,0,0,0,1,0,
        0,1,0,0,0,0,1,0,0,1,0,0,0,0,0,0,0,0,1,0,0,1,0,0,0,0,1,0,
        0,1,1,1,1,1,1,0,0,1,1,1,1,1,1,1,1,1,1,0,0,1,1,1,1,1,1,0,
        0,0,0,1,0,0,0,0,0,1,0,0,0,0,0,0,0,0,1,0,0,0,0,0,1,0,0,0,
        0,0,0,1,0,0,0,0,0,1,0,0,0,0,0,0,0,0,1,0,0,0,0,0,1,0,0,0,
        0,0,0,1,1,1,1,1,1,1,1,1,1,0,0,1,1,1,1,1,1,1,1,1,1,0,0,0,
        0,0,0,1,0,0,1,0,0,0,0,0,1,0,0,1,0,0,0,0,0,1,0,0,1,0,0,0,
        0,0,0,1,0,0,1,0,0,0,0,0,1,0,0,1,0,0,0,0,0,1,0,0,1,0,0,0,
        0,0,0,1,0,0,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,0,0,1,0,0,0,
        0,0,0,1,0,0,0,0,0,1,0,0,0,0,0,0,0,0,1,0,0,0,0,0,1,0,0,0,
        0,0,0,1,0,0,0,0,0,1,0,0,0,0,0,0,0,0,1,0,0,0,0,0,1,0,0,0,

        1,1,1,1,1,1,1,1,1,1,0,0,0,0,0,0,0,0,1,1,1,1,1,1,1,1,1,1,

        0,0,0,1,0,0,0,0,0,1,0,0,0,0,0,0,0,0,1,0,0,0,0,0,1,0,0,0,
        0,0,0,1,0,0,0,0,0,1,0,0,0,0,0,0,0,0,1,0,0,0,0,0,1,0,0,0,
        0,0,0,1,0,0,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,0,0,1,0,0,0,
        0,0,0,1,0,0,1,0,0,0,0,0,1,0,0,1,0,0,0,0,0,1,0,0,1,0,0,0,
        0,0,0,1,0,0,1,0,0,0,0,0,1,0,0,1,0,0,0,0,0,1,0,0,1,0,0,0,
        0,0,0,1,1,1,1,1,1,1,1,1,1,0,0,1,1,1,1,1,1,1,1,1,1,0,0,0,
        0,0,0,1,0,0,0,0,0,1,0,0,0,0,0,0,0,0,1,0,0,0,0,0,1,0,0,0,
        0,0,0,1,0,0,0,0,0,1,0,0,0,0,0,0,0,0,1,0,0,0,0,0,1,0,0,0,
        0,1,1,1,1,1,1,0,0,1,1,1,1,1,1,1,1,1,1,0,0,1,1,1,1,1,1,0,
        0,1,0,0,0,0,1,0,0,1,0,0,0,0,0,0,0,0,1,0,0,1,0,0,0,0,1,0,
        0,1,0,0,0,0,1,0,0,1,0,0,0,0,0,0,0,0,1,0,0,1,0,0,0,0,1,0,
        0,1,0,0,0,0,1,0,0,1,0,0,0,0,0,0,0,0,1,0,0,1,0,0,0,0,1,0,
        0,2,1,1,1,1,1,0,0,1,1,1,1,1,1,1,1,1,1,0,0,1,1,1,1,1,2,0,
        0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0


    };
    point = 0;
    result = 2;//1 is normal 2 is reslut
    ui->lcdNumber->setGeometry(800, 500, 100, 100);
    memcpy(board, map, sizeof(map));

    for(int i = 0; i < 31; i ++){
        for(int j = 0; j < 28; j++){
            int tmp1 = wall::number;
            int tmp2 = dots::number;
            int tmp3 = powerpellets::number;
            if(map[i][j] == 0){
                bwall[tmp1] = new wall();
                bwall[tmp1]->setposition(j*25, i*25);
                bwall[tmp1]->setsize(25,25);
                scene->addItem(bwall[tmp1]);
            }
            if(map[i][j] == 1){
                dot[tmp2] = new dots();
                dot[tmp2]->setposition(j*25, i*25);
                dot[tmp2]->setsize(25, 25);
                scene->addItem(dot[tmp2]);
            }
            if(map[i][j] == 2){
                powerpellet[tmp3] = new powerpellets();
                powerpellet[tmp3]->setposition(j*25, i*25);
                powerpellet[tmp3]->setsize(25, 25);
                scene->addItem(powerpellet[tmp3]);
            }
        }
    }




    pac = new elf();
    scene->addItem(pac);

    jessie = new jessieghost();
    scene->addItem(jessie);
    jessie->movebegin(board);

    //wobbuffet ghost generate
    wobbuffet = new wobbuffetghost();
    scene->addItem(wobbuffet);
    wobbuffet->movebegin(board);

    mewoth = new mewothghost();
    scene->addItem(mewoth);
    mewoth->movebegin(board);

    james = new jamesghost();
    scene->addItem(james);
    james->movebegin(board, pac->x, pac->y);


    /*ghost *jesssie = new jessieghost;
    scene->addItem(jesssie);
    jesssie->move();
    */
    pacmanpix = new QTimer(this);
    pacmanpix->start(50);
    connect(pacmanpix, SIGNAL(timeout()), this, SLOT(setpix()));

    //can use advance (phase)
    pacmantime = new QTimer(this);
    pacmantime->start(50);
    connect(pacmantime, SIGNAL(timeout()),this, SLOT(updater()));




    //jessie begin
    detjessie = 0;
    reverse = 0;
    stopjessie = 0;
    time[0] = new QTimer();
    //jessiebegintime->setSingleShot(true);
    time[0]->start(10025);
    connect(time[0], SIGNAL(timeout()), this, SLOT(jessiebeginmove()));

    //set powerpellet time
    time[2] = new QTimer();
    connect(time[2], SIGNAL(timeout()), this, SLOT(powerpelletstime()));

    //mewothmoveout
    time[3] = new QTimer();
    time[3]->start(15000-20);
    connect(time[3], SIGNAL(timeout()), this , SLOT(mewothbeginmove()));

    jessietime[1] = new QTimer();
    jessietime[1]->start(50);
    connect(jessietime[1], SIGNAL(timeout()), this, SLOT(jessiemove()));


    connect(ui->difficult, SIGNAL(clicked()), this , SLOT(setdifficult()) );

}
void MainWindow::setdifficult(){

    int number = ui->textEdit->toPlainText().toInt();
    james->speed = number;
    jessie->speed = number;
    wobbuffet->speed = number;
    mewoth->speed = number;
    qDebug() << number;

}
void MainWindow::mewothbeginmove(){
    detmewoth = 1;
}
void MainWindow::powerpelletstime(){
    if(pac->status == 0)pac->status = 1;
}
void MainWindow::jessiebeginmove(){
    detjessie = 1;
}

void MainWindow::jessiemove(){
    targetx = pac->x;
    targety = pac->y;
    if(detjessie == 0){
        if(jessie->y == 17*25)reverse = 1;
        else if(jessie->y == 13*25)reverse = 0;
        if(reverse == 0){
            jessie->y += 5;
            jessie->setposition(jessie->x, jessie->y);
        }
        if(reverse == 1){
            jessie->y -= 5;
            jessie->setposition(jessie->x, jessie->y);
        }
    }
    if(detjessie == 1){
        while(jessie->y != 12*25 && stopjessie == 0){
            jessie->y -= 5;
            jessie->setposition(jessie->x, jessie->y);
        }
        stopjessie = 1;
        jessie->move(targetx, targety);

    }

    if(detmewoth == 0){
        if(mewoth->y == 425)reversem = 1; //reverse mewoth
        else if(mewoth->y == 325)reversem = 0;
        if(reversem == 0){
            mewoth->y += 5;
            mewoth->setposition(mewoth->x, mewoth->y);
        }
        if(reversem == 1){
            mewoth->y -= 5;
            mewoth->setposition(mewoth->x, mewoth->y);
        }
    }
    if(detmewoth == 1){
        while(mewoth->y != 12*25 && stopmewoth == 0){
            mewoth->y -= 5;
            mewoth->setposition(mewoth->x, mewoth->y);
        }
        stopmewoth = 1;
        mewoth->move(pac->x, pac->y, pac->derection);

    }






    //wobbuffetmove



    wobbuffet->move();
    //mewoth move


    james->move();
}
void MainWindow::setpix(){
    pac->changederection();
}

void MainWindow::keyPressEvent(QKeyEvent *event){
    if(Qt::Key_W == event->key()){
        pac->derection = "UP";
        //pac->canmove = 0;

    }
    if(Qt::Key_S == event->key()){
        pac->derection = "DOWN";
        //pac->canmove = 0;

    }
    if(Qt::Key_A == event->key()){
        pac->derection = "LEFT";
        //pac->canmove = 0;

    }
    if(Qt::Key_D == event->key()){
        pac->derection = "RIGHT";
        //pac->canmove = 0;
    }
}
void MainWindow::updater(){
    if(result == 1){
        QMessageBox::information(this,"reslut:","You lose！",QMessageBox::Ok);
        result = 0;
    }
    //qDebug() << pac->x << pac->y << pac->correctmove;
    //pac->x / 25 pac->y / 25
    int mapx = pac->x % 25?pac->x/25:pac->x/25;
    int mapy = pac->y % 25?pac->y/25:pac->y/25;

    if(pac->x % 25 == 0 && pac->y % 25 == 0){
         if(board[mapy][mapx + 1] > 0 && pac->derection == "RIGHT"){
            pac->correctmove = pac->derection;
            pac->move();
        }
        else if(board[mapy][mapx -1] > 0 && pac->derection == "LEFT"){
            pac->correctmove = pac->derection;
             pac->move();
        }
        else if(board[mapy -1][mapx ] > 0 && pac->derection == "UP" ){
            pac->correctmove = pac->derection;
            pac->move();
        }
        else if(board[mapy+1][mapx ] > 0 && pac->derection == "DOWN"){
            pac->correctmove = pac->derection;
            pac->move();
        }
         else {
             if(board[mapy ][mapx + 1] > 0 && pac->correctmove == "RIGHT"){
                pac->move();
            }
            else if(board[mapy][mapx -1] > 0 && pac->correctmove == "LEFT"){
                 pac->move();
            }
            else if(board[mapy -1][mapx ] > 0 && pac->correctmove == "UP" ){
                pac->move();
            }
            else if(board[mapy+1][mapx ] > 0 && pac->correctmove == "DOWN"){
                pac->move();
            }
         }
    }
    else {
        if(pac->derection == "UP" && pac->correctmove == "DOWN"){
            pac->correctmove = pac->derection;
        }
        if(pac->derection == "DOWN" && pac->correctmove == "UP"){
            pac->correctmove = pac->derection;
        }
        if(pac->derection == "RIGHT" && pac->correctmove == "LEFT"){
            pac->correctmove = pac->derection;
        }
        if(pac->derection == "LEFT" && pac->correctmove == "RIGHT"){
            pac->correctmove = pac->derection;
        }
        pac->move();

    }

    for(int i = 0; i < dots::number; i++){
        if(pac->collidesWithItem(dot[i] ,Qt::IntersectsItemBoundingRect)){
            dot[i]->settransparent();
            point+=10;
        }
    }
    for(int i = 0; i < powerpellets::number; i++){
        if(pac->collidesWithItem(powerpellet[i] ,Qt::IntersectsItemBoundingRect)){
            powerpellet[i]->settransparent();
            point+=50;
            pac->status = 0;
            time[2]->start(5000);
        }
    }


    if(pac->collidesWithItem(jessie ,Qt::IntersectsItemBoundingRect)  ){
        if(pac->status == 0){
            value += 100;
            point += 100;
            jessie->rebirth();
            detjessie = 0;
            stopjessie = 0;
            time[0]->start(10025);
        }
        else {
            if(result == 2)result = 1;
        }
    }


    if( pac->collidesWithItem(wobbuffet ,Qt::IntersectsItemBoundingRect) ){
        if(pac->status == 0){
            value += 100;
            point += 100;
            wobbuffet->rebirth();
        }
        else {
            if(result == 2)result = 1;
        }
    }


    if( pac->collidesWithItem(mewoth ,Qt::IntersectsItemBoundingRect) ){
        if(pac->status == 0){
            value += 100;
            point += 100;
            mewoth->rebirth();
        }
        else {
            if(result == 2)result = 1;
        }
    }

    if( pac->collidesWithItem(james ,Qt::IntersectsItemBoundingRect) ){
        if(pac->status == 0){
            value += 100;
            point += 100;
            james->rebirth();
        }
        else {
            if(result == 2)result = 1;
        }
    }





    ui->lcdNumber->display(point);
    //qDebug() << pac->derection;
    if(point == 2920 + value){
        QMessageBox::information(this,"reslut:","You win！",QMessageBox::Ok);
    }
}

MainWindow::~MainWindow()
{
    delete ui;
}
