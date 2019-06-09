#ifndef WALL_H
#define WALL_H
#include <QGraphicsPixmapItem>
#include <QPen>
class wall : public QGraphicsPixmapItem
{
public:
    wall();
    void setposition(int , int);
    void setsize(int , int);
    //void paint(QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget *widget);
    //QRectF boundingRect() const;
    static int number;
private:
    QPen wallpen;
    QPixmap blackwall;
    QPixmap correctwall;
    int pos_x, pos_y, width,  height;
};

#endif // WALL_H
