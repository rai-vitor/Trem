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
    if(ID == 4){
        vetorSemaforos.at(3)->P();
        vetorSemaforos.at(4)->P();
    }
    if(ID == 5){
        vetorSemaforos.at(6)->P();
        vetorSemaforos.at(5)->P();
    }
    if(ID == 6){
        vetorSemaforos.at(0)->P();
        vetorSemaforos.at(8)->P();
    }

}

void Trem::run(){
    while(true){
        while(!stop){
            switch(ID){
            case 1:
                if(x == 310 && y == 30){
                    vetorSemaforos.at(3)->P();
                    vetorSemaforos.at(1)->P();
                }
                if(x == 310 && y == 150){
                    vetorSemaforos.at(1)->V();
                }
                if(x == 170 && y == 150){
                    vetorSemaforos.at(3)->V();
                }
                break;
            case 2:
                if(x == 580 && y == 30){
                    vetorSemaforos.at(1)->P();
                    vetorSemaforos.at(4)->P();
                    vetorSemaforos.at(5)->P();
                    vetorSemaforos.at(2)->P();
                }
                if(x == 580 && y == 150){
                    vetorSemaforos.at(2)->V();
                }
                if(x == 440 && y == 150){
                    vetorSemaforos.at(5)->V();
                }
                if(x == 330 && y == 130){
                    vetorSemaforos.at(4)->V();
                }
                if(x == 350 && y == 30){
                    vetorSemaforos.at(1)->V();
                }
                break;
            case 3:
                if(x == 750 && y == 150){
                    vetorSemaforos.at(2)->P();
                    vetorSemaforos.at(6)->P();
                }
                if(x == 600 && y == 130){
                    vetorSemaforos.at(6)->V();
                }
                if(x == 620 && y == 30){
                    vetorSemaforos.at(2)->V();
                }
                break;
            case 4:
                if(x == 350 && y == 150){
                    vetorSemaforos.at(3)->V();
                }
                if(x == 190 && y == 170){
                    vetorSemaforos.at(4)->P();
                    vetorSemaforos.at(3)->P();
                }
                if(x == 460 && y == 170){
                    vetorSemaforos.at(4)->V();
                }
                if(x == 440 && y == 150){
                    vetorSemaforos.at(7)->P();
                    vetorSemaforos.at(8)->P();
                }
                if(x == 440 && y == 270){
                    vetorSemaforos.at(7)->V();
                }
                if(x == 300 && y == 270){
                    vetorSemaforos.at(8)->V();
                }
                break;
            case 5:
                if(x == 460 && y == 170){
                    vetorSemaforos.at(6)->P();
                    vetorSemaforos.at(5)->P();
                }
                if(x == 620 && y == 150){
                    vetorSemaforos.at(5)->V();
                }
                if(x == 730 && y == 170){
                    vetorSemaforos.at(6)->V();
                }
                if(x == 610 && y == 270){
                    vetorSemaforos.at(7)->P();
                    vetorSemaforos.at(0)->P();
                }
                if(x == 460 && y == 250){
                    vetorSemaforos.at(0)->V();
                }
                if(x == 480 && y == 150){
                    vetorSemaforos.at(7)->V();
                }
            break;
            case 6:
                if(x == 320 && y == 290){
                    vetorSemaforos.at(0)->P();
                    vetorSemaforos.at(8)->P();
                }
                if(x == 480 && y == 270){
                    vetorSemaforos.at(8)->V();
                }
                if(x == 590 && y == 290){
                    vetorSemaforos.at(0)->V();
                }
            break;
            }
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

void Trem::Velocidade(int vel){
    vel = (10 - (vel+3)) * 100;
    this->velocidade = vel;
}
