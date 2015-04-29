#include "trem.h"
#include <QtCore>


Trem::Trem(int ID, int x, int y){
    this->ID = ID;
    this->x = x;
    this->y = y;
    stop = false;
    velocidade = 500;
}

void Trem::run(){
    while(true){
        switch(ID){
        case 1:
            emit updateGUI(ID, x,y);
            if (x >= 60 && x < 330)
                x+=10;
            else if (x == 330 && y < 150)
                y+=10;
            break;
        case 2:
            //emit updateGUI(ID, x,y);
            break;
        default:
            break;
        }
        msleep(velocidade);
    }
}

void Trem::finalizar(){
    stop = true;
}


