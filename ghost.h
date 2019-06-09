#ifndef GHOST_H
#define GHOST_H
#include <QGraphicsPixmapItem>
#include <QDebug>
#include <QObject>
#include <QQueue>

class ghost :  public QGraphicsPixmapItem
{

public:
    ghost();
    void virtual move() = 0;
    //void paint(QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget *widget);
    void virtual movebegin(int [][28], int , int) = 0;
    void virtual rebirth() = 0;


    int speed;
    struct point;
    QPixmap  jamespix;
    QString derection;
    int x, y;
    int board[31][28];
    int targetx, targety;
    //QQueue <point> queue;
    int route[31][28];
    int dr[4], dc[4];
    int t;


















    void virtual lastmove() = 0;

    //QString derection;
    QString cannotmove;
    QString cannotmove1;
    QString cannotmove2;
    QString cannotmove3;
    QString cannotmove4;
    QString correctmove;
    int det;
    //int x, y;
    //int speed;
    void virtual changederection() = 0;

    int status;

    QPixmap pika[10];
    //QGraphicsPixmapItem pic[10];

};

#endif // GHOST_H
