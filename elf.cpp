#include "elf.h"
#include <QtDebug>
#include <QTimer>

elf::elf()
{
    pika[0].load(":/new/prefix1/Pikachu.png");
    pika[1].load(":/new/prefix1/Pikachu-down.png");
    pika[2].load(":/new/prefix1/pikachu-right.png");
    pika[3].load(":/new/prefix1/Pikachu-up.png");
    pika[4].load(":/new/prefix1/deadpoolpickachu.png");
    setPixmap(pika[0].scaled(25, 25, Qt::KeepAspectRatio));
    x = 25;
    y = 100;
    this->setX(x);
    this->setY(y);
    derection = "";
    status = 1;
    speed = 5;

}
void elf::movebegin(int [][28], int , int){

}
void elf::rebirth(){

}

/*QRectF elf::boundingRect() const
{
    return QRect(0, -25, 25, 25);
}
void elf::paint(QPainter *painter, const QStyleOptionGraphicsItem *option,
           QWidget *widget)
{
    //painter->drawRoundedRect(-10, -10, 20, 20, 5, 5);
    QRectF h = boundingRect();
    QBrush brush(Qt::blue);
    //painter->drawPixmap(0,-25,25,25,pika[0]);

    //painter->drawRect(h);
}*/
void elf::move(){

    if(correctmove == "UP"  ){
            det = 0;
            this->setX(x);
            this->setY(y-speed);
            y = y - speed;

    }
    if(correctmove  == "DOWN" ){
            det = 0;
            this->setX(x);
            this->setY(y+speed);
            y = y + speed;

    }
    if(correctmove  == "RIGHT" ){
            det = 0;
            this->setX(x+speed);
            this->setY(y);
            x = x + speed;

    }
    if(correctmove  == "LEFT" ){
            det = 0;
            this->setX(x-speed);
            this->setY(y);
            x = x - speed;

    }
    if(x == 0 && y == 375 && correctmove == "LEFT"){
        this->setX(675);
        this->setY(375);
        x = 675;
        y = 375;

    }
    if(x == 675 && y == 375 && correctmove == "RIGHT"){
        this->setX(0);
        this->setY(375);
        x = 0;
        y = 375;

    }

}
void elf::lastmove(){
    if(derection == "UP"){
            det = 0;
            this->setX(x);
            this->setY(y+speed);
            y = y + speed;

    }
    if(derection == "DOWN" ){
            det = 0;
            this->setX(x);
            this->setY(y-speed);
            y = y - speed;

    }
    if(derection == "RIGHT" ){
            det = 0;
            this->setX(x-speed);
            this->setY(y);
            x = x - speed;

    }
    if(derection == "LEFT" ){
            det = 0;
            this->setX(x+speed);
            this->setY(y);
            x = x + speed;
    }
}
void elf::changederection(){
    if(correctmove == "LEFT" && status == 1){
        setPixmap(pika[0].scaled(25, 25, Qt::KeepAspectRatio));
    }
    if(correctmove == "RIGHT" && status == 1){
        setPixmap(pika[2].scaled(25, 25, Qt::KeepAspectRatio));
    }
    if(correctmove == "DOWN" && status == 1){
        setPixmap(pika[1].scaled(25, 25, Qt::KeepAspectRatio));
    }
    if(correctmove == "UP" && status == 1){
        setPixmap(pika[3].scaled(25, 25, Qt::KeepAspectRatio));
    }
    if(status == 0){
        setPixmap(pika[4].scaled(25, 25, Qt::KeepAspectRatio));
    }

}


