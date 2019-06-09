#ifndef JESSIEGHOST_H
#define JESSIEGHOST_H
#include "ghost.h"
#include <QGraphicsPixmapItem>


class jessieghost : public QGraphicsPixmapItem

{

public:
    jessieghost();
    void movebegin(int [][28]);
    void move(int , int);
    void move();
    int x, y;
    void setposition(int x,  int y);
    void rebirth();
    int speed;
private:
    QPixmap jessiepix;
    int board[31][28];
    QString derection;


};

#endif // JESSIEGHOST_H
