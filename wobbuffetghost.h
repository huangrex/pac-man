#ifndef WOBBUFFETGHOST_H
#define WOBBUFFETGHOST_H
#include <QGraphicsPixmapItem>
#include "ghost.h"
class wobbuffetghost : public QGraphicsPixmapItem

{
public:
    wobbuffetghost();
    void movebegin(int [][28]);
    void move();
    void rebirth();
    int speed;
private:
    QPixmap wobbuffetpix;
    int board[31][28];
    QString derection;
    int x, y;

};

#endif // WOBBUFFETGHOST_H
