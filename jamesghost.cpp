#include "jamesghost.h"
#include <QDebug>

jamesghost::jamesghost()
{
    jamespix.load(":/new/prefix1/james.png");
    this->setPixmap(jamespix.scaled(25, 25, Qt::KeepAspectRatio));
    this->setPos(15*25, 13*25);

    x = 15*25;
    y = 13*25;
    speed = 5;
    dr[0] = 0;
    dr[1] = 0;
    dr[2] = -1;
    dr[3] = 1;

    dc[0] = -1;
    dc[1] = 1;
    dc[2] = 0;
    dc[2] = 0;
    t = 0;

}

void jamesghost::movebegin(int boardtmp[31][28],int  x, int y){
    memcpy(board, boardtmp, sizeof(board));
    targetx = x;
    targety = y;

}

struct jamesghost::point{
    int x;
    int y;
    int t;
};

void jamesghost::rebirth(){
    x = 15*25;
    y = 13*25;
    setPos(15*25, 13*25);
}
void  jamesghost::lastmove(){

}
void  jamesghost::changederection(){

}

void jamesghost::move(){
    /*
    if(y % 25 == 0 && x % 25 == 0){
        qDebug() << x << y;
        jamesghost::point j = {x, y, 0};
        queue.push_back(j);
        board[y/25][x/25] = -1;
        route[y/25][x/25] = -1;
        int tmpx, tmpy;
        while (!queue.empty()) {
           point k = queue.front();
           queue.pop_front();
           if(k.x == targetx && y == targety){
               qDebug() << targetx << targety;
               break;
           }

           for(int i = 0; i < 4; i++){
               if(k.y+dc[i] < 0 || k.y+dc[i] > 30 || k.x+dr[i] < 0 || k.x+dr[i] > 27)continue;
               if(board[k.y /25+dc[i]][k.x /25+dr[i]] == 0)continue;
               if(board[k.y/25+dc[i] ][k.x/25+dr[i] ] == 1){
                   queue.push_back({k.x+dr[i], k.y+dc[i], k.t+1});
                   route[k.y/25 + dc[i] ][k.x/25 + dr[i] ] = k.y*30 + k.x;
                   board[k.y /25 + dc[i]][k.x/25 + dr[i]] = 1000;
                   qDebug() << k.x << k.y;
               }

           }
           qDebug() << k.t;
           /*
            int u = queue.front();
            if(u == targetx + targety*25){
                break;
            }
            queue.pop_front();

            tmpx = u / 25;
            tmpy = u % 25;


            if((tmpy-1)*25 + tmpx > 0 && board[(tmpy-1)*25][tmpx] == 1 && (tmpy-1)*25 + tmpx < 775){
                board[(tmpy-1)*25][tmpx] = -1;
                queue.push_back( (tmpy-1)*25 + tmpx);
                route[(tmpy-1)*25 + tmpx] = u;
            }

            u = queue.front();
            if(u == targetx + targety*25){
                break;
            }
            queue.pop_front();

            tmpx = u / 25;
            tmpy = u % 25;

            if((tmpy+1)*25 + tmpx > 0 && board[(tmpy+1)*25][tmpx] == 1 && (tmpy+1)*25 + tmpx < 775){
                board[(tmpy+1)*25][tmpx] = -1;
                queue.push_back( (tmpy+1) *25 + tmpx);
                route[(tmpy+1) *25 + tmpx] = u;
            }



            u =  queue.front();
            if(u == targetx + targety*25){
                break;
            }
            queue.pop_front();

            tmpx = u / 25;
            tmpy = u % 25;


            if(tmpy * 25 + tmpx-1 > 0 && board[tmpy * 25][tmpx-1] == 1 && tmpy * 25 + tmpx-1 <775){
               board[tmpy * 25][tmpx-1] = -1;
                queue.push_back(tmpy * 25 + tmpx-1);
                route[tmpy * 25 + tmpx-1 ] = u;
            }



            u =  queue.front();
            if(u == targetx + targety*25){
                break;
            }
            queue.pop_front();

            tmpx = u / 25;
            tmpy = u % 25;

            if((tmpy*25 + tmpx -1) > 0 && board[(tmpy-1)*25][tmpx] == 1 && tmpy*25 + tmpx -1 <775){
                board[tmpy*25][tmpx -1] = -1;
               queue.push_back(tmpy*25 + tmpx -1);
               route[tmpy*25+x-1] = u;
            }
            */
        //}
        /*
        if(route[y*25+x] == y*25+x+1){
            derection = "RIGHT";
        }
        else if(route[y*25+x] == y*25+x-1){
            derection = "LEFT";
        }
        else if(route[y*25+x] == (y-1)*25 + x){
            derection = "UP";
        }
        else if(route[y*25+x] == (y+1)*25 + x){
            derection = "DOWN";
        }

        */
/*
        while(route[targety][targetx] != -1){
            tmpy = route[targety][targetx] /30 ;
            tmpx = route[targety][targetx] %30 ;
            qDebug() << tmpy << tmpx;
            route[targety][targetx] = route[tmpy][tmpx];
            if(tmpy > y)derection = "DOWN";
            else if(tmpy < y)derection = "UP";
            else if(tmpx > x)derection = "RIGHT";
            else if(tmpx < x)derection = "LEFT";
        }


        if(derection == "RIGHT" && board[y / 25 ][x / 25 + 1 ] > 0){
                x += speed;
                setPos(x, y);
                derection = "RIGHT";
        }
        else if(derection == "LEFT" && board[y / 25  ][x / 25 -1] > 0){
            x -= speed;
            setPos(x, y);

        }
        else if(derection == "DOWN" && board[y / 25 +1][x / 25] > 0){
            y += speed;
            setPos(x, y);

        }
        else if(derection == "UP" && board[y / 25 -1][x / 25] > 0){
            y -= speed;
            setPos(x, y);

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
    }*/
















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
