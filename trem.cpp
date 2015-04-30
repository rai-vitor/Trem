#include "trem.h"
#include <QtCore>


Trem::Trem(int ID, int x, int y, int vel){
    this->ID = ID;
    this->x = x;
    this->y = y;
    stop = false;
    velocidade = vel;
    this->deslocX = 0;
    this->deslocY = 0;
}

void Trem::run(){
    while(true){
        switch(ID){
        case 1:
            break;
        case 2:
            //emit updateGUI(ID, x,y);
            break;
        default:
            break;
        }
        mover();
        msleep(velocidade);
    }
}

void Trem::mover(){
    emit updateGUI(ID, x, y);
    if (deslocX < 27 && deslocY == 0){
        deslocX++;
        x+=10;
    }

    else if (deslocX == 27 && deslocY < 12){
        deslocY++;
        y+=10;
    }
    else if(deslocX > 0 && deslocY == 12){
        deslocX--;
        x-=10;
    }
    else if(deslocX == 0 && deslocY > 0){
        deslocY--;
        y-=10;
    }
}

void Trem::finalizar(){
    stop = true;
}


