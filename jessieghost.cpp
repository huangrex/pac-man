#include "jessieghost.h"

jessieghost::jessieghost()
{
    jessiepix.load(":/new/prefix1/Jessie.png");
    this->setPixmap(jessiepix.scaled(25, 25, Qt::KeepAspectRatio));
    this->setPos(11*25,14*25-25);
    //this->setX(11*25);
    //this->setY(14*25);
    speed = 5;
}
void jessieghost::movebegin(int boardtmp[31][28]){
    memcpy(board, boardtmp, sizeof(board));
    x = 11*25;
    y = 13*25;
}
void jessieghost::rebirth(){
    x = 11*25;
    y = 13*25;
    setPos(11*25, 13*25);
}
void jessieghost::move(){

}
void jessieghost::move(int targetx, int targety){
    //qDebug() << x << y;
    if(x % 25 == 0 && y % 25 == 0){
        if(targetx > x && board[y / 25 ][x / 25 + 1 ] > 0){
                x += speed;
                setPos(x, y);
                derection = "RIGHT";
        }
        else if(targetx < x && board[y / 25  ][x / 25 -1] > 0){
            x -= speed;
            setPos(x, y);
            derection = "LEFT";
        }
        else if(targety > y && board[y / 25 +1][x / 25] > 0){
            y += speed;
            setPos(x, y);
            derection = "DOWN";
        }
        else if(targety < y && board[y / 25 -1][x / 25] > 0){
            y -= speed;
            setPos(x, y);
            derection = "UP";
        }
        else if(board[y / 25 +1][x / 25] > 0){
            derection = "DOWN";
            y += speed;
            setPos(x, y);
        }
        else if(board[y / 25 ][x / 25 + 1 ] > 0){
            derection = "RIGHT";
            x += speed;
            setPos(x, y);
        }
        else if(board[y / 25  ][x / 25 -1] > 0){
            derection = "LEFT";
            x -= speed;
            setPos(x, y);
        }
        else if(board[y / 25 -1][x / 25] > 0){
            derection = "UP";
            y -= speed;
            setPos(x, y);
        }
    }
    else{
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
    //qDebug() << derection;
}

void jessieghost::setposition(int x,  int y){
    this->setPos(x, y);
}

