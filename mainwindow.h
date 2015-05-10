#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include "trem.h"
#include "semaforo.h"
namespace Ui {
class MainWindow;
}

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit MainWindow(QWidget *parent = 0);
    ~MainWindow();


public slots:
    void updateInterface(int,int,int);

private slots:
    void on_botao_iniciar_clicked();
    void on_botao_pausar_clicked();

private:
    int flag; //Flag para saber se os trens estão parados ou em movimento. 1 = movimento, 0 = parado
    Ui::MainWindow *ui;
    Trem *trem1;
    Trem *trem2;
    Trem *trem3;
    Trem *trem4;
    Trem *trem5;
    Trem *trem6;
    QVector<Semaforo*> vetor;
    Semaforo *sem1, *sem2, *sem3, *sem4, *sem5, *sem6, *sem7, *sem8, *sem9;
};

#endif // MAINWINDOW_H
