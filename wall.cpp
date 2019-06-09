#include "wall.h"
#include <QPen>
#include <QGraphicsScene>

#include "elf.h"
wall::wall()
{
    number++;
    blackwall.load(":/new/prefix1/blackpoint.png");
    pos_x = 0;
    pos_y = 0;
    width = 0;
    height = 0;
    setPixmap(blackwall.scaled(25 , 25, Qt::KeepAspectRatio));
    //this->setPos(100, 100);
}
void wall::setposition(int x,  int y){
    pos_x = x;
    pos_y = y;
    this->setPos(x, y);
}
void wall::setsize(int x, int y){

    width = x;
    height = y;
    //correctwall = blackwall.scaledToWidth(50,Qt::SmoothTransformation);
    //correctwall = correctwall.scaledToHeight(10,Qt::SmoothTransformation);
    correctwall=blackwall.scaled(x, y);
    setPixmap(correctwall);

}
/*void wall::paint(QPainter *painter, const QStyleOptionGraphicsItem *option,
           QWidget *widget)
{
    QRectF h = boundingRect();
    ///painter->drawPixmap(pos_x, pos_y, width, height, );
    painter->setBrush(Qt::black);
    painter->drawLine(0, 0 , 630, 560);
    //this->setPos(pos_x, pos_y);

}
QRectF wall::boundingRect() const
{
    //return QRectF(pos_x, pos_y , width, height);
    return QRectF(0, 0 , 630, 560);
}*/
