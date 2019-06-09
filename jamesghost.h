#ifndef JAMESGHOST_H
#define JAMESGHOST_H
#include <QGraphicsPixmapItem>
#include <QQueue>
#include"ghost.h"
class jamesghost : public ghost
{
public:
    jamesghost();
    void movebegin(int [][28], int , int);
    void move();
    void rebirth();

    void  lastmove();
    void  changederection();

};

#endif // JAMES_H
