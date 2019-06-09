#ifndef DOTS_H
#define DOTS_H
#include <QGraphicsPixmapItem>

class dots : public QGraphicsPixmapItem
{
public:
    dots();

    static int number;
    void setposition(int x,  int y);
    void setsize(int x, int y);

    int pos_x, pos_y, width,  height;
    void settransparent();
private:
    QPixmap correctdot;
    QPixmap dot;
    QPixmap transparent;
};

#endif // DOTS_H
