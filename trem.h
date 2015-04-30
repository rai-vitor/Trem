#ifndef TREM_H
#define TREM_H

#include <QThread>

class Trem: public QThread{
 Q_OBJECT
public:
    Trem(int, int, int, int);
    void run();
    void finalizar();
    void mover();

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
};

#endif // TREM_H
