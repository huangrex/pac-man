#ifndef MEWOTH_H
#define MEWOTH_H
#include <QGraphicsPixmapItem>
#include "ghost.h"

class mewothghost : public QGraphicsPixmapItem
{
public:
    mewothghost();
    void move(int ,int , QString);
    void move();
    void movebegin(int [][28]);
    void rebirth();
    void setposition(int x, int y);
    int x, y;
    int speed;
private:
    QPixmap mewothpix;
    int board[31][28];

    QString derection;
    QString lastderecction;

};

#endif // MEWOTH_H
