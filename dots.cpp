#include "dots.h"

dots::dots()
{
   dot.load(":/new/prefix1/dot1.png");
   setPixmap(dot);
   number++;
}
void dots::setposition(int x,  int y){
    pos_x = x;
    pos_y = y;
    this->setPos(x, y);
}
void dots::setsize(int x, int y){
    /*QTransform trans;
    trans.translate( 600, 300);

    //correctwall = blackwall;
    //this->setTransform(trans);
    //setPixmap(blackwall);

    QPainter *painter = new QPainter();
    //QRectF h = QRectF(pos_x, pos_y, x, y);
    //QBrush brush(Qt::blue);
    //painter.drawPixmap(pos_x, pos_y, x, y,blackwall);
    painter->drawPixmap(200, 200, blackwall);
    //painter->drawRect(h);*/
    width = x;
    height = y;
    //correctwall = blackwall.scaledToWidth(50,Qt::SmoothTransformation);
    //correctwall = correctwall.scaledToHeight(10,Qt::SmoothTransformation);
    correctdot=dot.scaled(x, y);
    setPixmap(correctdot);

}
void dots::settransparent(){
    transparent.load(":/../src/output-onlinepngtools (1).png");
    setPixmap(transparent);
}
