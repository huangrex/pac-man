#include "mewothghost.h"

mewothghost::mewothghost()
{
    mewothpix.load(":/new/prefix1/Mewoth.png");
    setPixmap(mewothpix.scaled(25, 25, Qt::KeepAspectRatio));
    setPos(14*25, 350);
    x = 325;
    y = 350;
    speed = 5;
}

void mewothghost::movebegin(int boardtmp[31][28]){
    memcpy(board, boardtmp, sizeof(board));
}
void mewothghost::rebirth(){
    x = 14*25;
    y = 12*25;
    setPos(14*25, 12*25);
}
void mewothghost::setposition(int x, int y){
    this->setPos(x, y);
}
void mewothghost::move(){

}

void mewothghost::move(int targetx, int targety, QString pacmanderection){

    if(pacmanderection == "RIGHT")targetx += 100;
    if(pacmanderection == "DOWN")targety += 100;
    if(pacmanderection == "LEFT")targetx -= 100;
    if(pacmanderection == "UP")targety -= 100;
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
        else if(board[y / 25 +1][x / 25] > 0 && "UP" != derection){
            derection = "DOWN";
            y += speed;
            setPos(x, y);
            lastderecction = derection;
        }
        else if(board[y / 25 ][x / 25 + 1 ] > 0 && "LEFT" != derection){
            derection = "RIGHT";
            x += speed;
            setPos(x, y);
            lastderecction = derection;
        }
        else if(board[y / 25  ][x / 25 -1] > 0 && "RIGHT" != derection ){
            derection = "LEFT";
            x -= speed;
            setPos(x, y);
            lastderecction = derection;
        }
        else if(board[y / 25 -1][x / 25] > 0 && "DOWN" != derection){
            derection = "UP";
            y -= speed;
            setPos(x, y);
            lastderecction = derection;
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

}
