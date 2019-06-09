#ifndef POWERPELLETS_H
#define POWERPELLETS_H
#include <QGraphicsPixmapItem>

class powerpellets : public QGraphicsPixmapItem
{
public:
    powerpellets();
    static int number;
    void setposition(int x,  int y);
    void setsize(int x, int y);

    int pos_x, pos_y, width,  height;
    void settransparent();
    void transformer();
private:
    QPixmap correctpoerpellet;
    QPixmap powerpellet;
    QPixmap transparent;
};

#endif // POWERPELLETS_H
