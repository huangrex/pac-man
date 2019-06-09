#include "wobbuffetghost.h"
#include <ctime>
#include <QTime>
#include <QDebug>
wobbuffetghost::wobbuffetghost()
{
    wobbuffetpix.load(":/new/prefix1/Wobbuffet.png");
    this->setPixmap(wobbuffetpix.scaled(25, 25, Qt::KeepAspectRatio));
    this->setPos(12*25,17*25);
    x = 12*25;
    y = 17*25;
    QTime t;
    t = QTime::currentTime();
    qsrand((unsigned int)t.msec());
    speed = 5;
}

void wobbuffetghost::movebegin(int boardtmp[31][28]){
     memcpy(board, boardtmp, sizeof(board));
}
void wobbuffetghost::rebirth(){
    x = 12*25;
    y = 17*25;
    setPos(12*25, 17*25);
}
void wobbuffetghost::move(){

    if(x % 25 == 0 && y % 25 == 0){

        if(board[y / 25 ][x / 25 + 1 ] > 0 && derection == "RIGHT"){
                x += speed;
                setPos(x, y);
                derection = "RIGHT";
        }
        else if(board[y / 25  ][x / 25 -1] > 0 && derection == "LEFT"){
            x -= speed;
            setPos(x, y);
            derection = "LEFT";
        }
        else if( board[y / 25 +1][x / 25] > 0 && derection == "DOWN"){
            y += speed;
            setPos(x, y);
            derection = "DOWN";
        }
        else if(board[y / 25 -1][x / 25] > 0 && derection == "UP"){
            y -= speed;
            setPos(x, y);
            derection = "UP";
        }//board[y / 25 ][x / 25 + 1 ] == 0 || board[y / 25  ][x / 25 -1] == 0 ||  board[y / 25 +1][x / 25] == 0 || board[y / 25 -1][x / 25] == 0)
        else {
            int tmp = qrand() % 4;
            if(tmp == 0)derection = "UP";
            else if (tmp == 2)derection = "DOWN";
            else if(tmp == 3)derection = "RIGHT";
            else derection = "LEFT";
        }
    }
    else {
        if(derection == "RIGHT"){
            x += speed;
            setPos(x, y);
        }
        else if( derection == "LEFT"){
            x -= speed;
            setPos(x, y);
        }
        else if(derection == "DOWN"){
            y += speed;
            setPos(x, y);
        }
        else if( derection == "UP"){
            y -= speed;
            setPos(x, y);
        }
    }
}
