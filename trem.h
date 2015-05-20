#ifndef TREM_H
#define TREM_H

#include <QThread>
#include "semaforo.h"
#include <QVector>
class Trem: public QThread{
 Q_OBJECT
public:
    Trem(int, int, int, int, QVector<Semaforo*>);
    void run();
    void finalizar();
    void mover();
    void Velocidade(int);


signals:
    void updateGUI(int,int,int);

private:
   int x;
   int y;
   int ID;
   int velocidade;
   int deslocX;
   int deslocY;
   bool stop;
   QVector<Semaforo*> vetorSemaforos;
};

#endif // TREM_H
