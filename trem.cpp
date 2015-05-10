#include "trem.h"
#include <QtCore>


Trem::Trem(int ID, int x, int y, int vel, QVector<Semaforo*> vetor){
    this->ID = ID;
    this->x = x;
    this->y = y;
    stop = false;
    velocidade = vel;
    this->deslocX = 0;
    this->deslocY = 0;
    vetorSemaforos = vetor;
}

void Trem::run(){
    while(true){
        while(!stop){/*
            switch(ID){
            case 1:
                if(x == 60 && y == 30){
                  //  vetorSemaforos.at(0)->V();
                }
                if(x == 310 && y == 30){
                    vetorSemaforos.at(0)->P();
                }
                if(x == 310 && y == 150){
                    vetorSemaforos.at(0)->V();
                }
                break;
            case 2:
                if(x == 350 && y == 150){
                    vetorSemaforos.at(0)->P();
                }
                if(x == 330 && y == 40){
                    vetorSemaforos.at(0)->V();
                }
                if(x == 350 && y == 30){
                    //vetorSemaforos.at(0)->P();
                }
                break;
            default:
                break;
            }*/
            mover();
            msleep(velocidade);
        }
    msleep(velocidade);
    }
}

void Trem::mover(){
    emit updateGUI(ID, x, y);
    if (deslocX < 24 && deslocY == 0){
        deslocX++;
        x+=10;
    }

    else if (deslocX == 24 && deslocY < 12){
        deslocY++;
        y+=10;
    }
    else if(deslocX > -3 && deslocY == 12){
        deslocX--;
        x-=10;
    }
    else if(deslocX == -3 && deslocY > 0){
        deslocY--;
        y-=10;
    }
}

void Trem::finalizar(){
    if(stop == true)
        stop = false;
    else if(stop == false)
        stop = true;
}

void Trem::continuar(){
    stop = false;
}
