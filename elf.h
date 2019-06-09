#ifndef ELF_H
#define ELF_H
#include <QGraphicsPixmapItem>
#include <QGraphicsItem>
#include <QKeyEvent>
#include <QtWidgets>
#include "ghost.h"

class elf : public ghost
{



public:
    elf();
    //QRectF boundingRect() const;
    //void paint(QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget *widget);

    void movebegin(int [][28], int , int);
    void rebirth();
    void move();


    void  lastmove();
    void  changederection();


};

#endif // ELF_H
