#include "powerpellets.h"

powerpellets::powerpellets()
{
    powerpellet.load(":/new/prefix1/yellowdot.png");
    setPixmap(powerpellet);
    number++;
}
void powerpellets::setposition(int x,  int y){
    pos_x = x;
    pos_y = y;
    this->setPos(x, y);
}
void powerpellets::setsize(int x, int y){

    width = x;
    height = y;
    correctpoerpellet =powerpellet.scaled(x, y);
    setPixmap(correctpoerpellet);

}
void powerpellets::settransparent(){
    transparent.load(":/new/prefix1/output-onlinepngtools (1).png");
    setPixmap(transparent);
}
void powerpellets::transformer(){

}
