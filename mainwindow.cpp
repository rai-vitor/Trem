#include "mainwindow.h"
#include "ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    flag = 1;
    ui->setupUi(this);

    sem1 = new Semaforo (1, 1 , IPC_CREAT | 0600);
    sem2 = new Semaforo (12, 1 , IPC_CREAT | 0600);
    sem3 = new Semaforo (123, 1 , IPC_CREAT | 0600);
    sem4 = new Semaforo (1234, 1 , IPC_CREAT | 0600);
    sem5 = new Semaforo (12345, 1 , IPC_CREAT | 0600);
    sem6 = new Semaforo (123456, 1 , IPC_CREAT | 0600);

    vetor.push_back(sem1);
    vetor.push_back(sem2);
    vetor.push_back(sem3);
    vetor.push_back(sem4);
    vetor.push_back(sem5);
    vetor.push_back(sem6);

    trem1 = new Trem(1, 60, 30, 200, vetor);
    connect(trem1,SIGNAL(updateGUI(int,int,int)),SLOT(updateInterface(int,int,int)));

    trem2 = new Trem(2, 330, 30, 100, vetor);
    connect(trem2,SIGNAL(updateGUI(int,int,int)),SLOT(updateInterface(int,int,int)));

    trem3 = new Trem(3, 600, 30, 400, vetor);
    connect(trem3,SIGNAL(updateGUI(int,int,int)),SLOT(updateInterface(int,int,int)));

    trem4 = new Trem(4, 190, 150, 500, vetor);
    connect(trem4,SIGNAL(updateGUI(int,int,int)),SLOT(updateInterface(int,int,int)));

    trem5 = new Trem(5, 460, 150, 600, vetor);
    connect(trem5,SIGNAL(updateGUI(int,int,int)),SLOT(updateInterface(int,int,int)));

    trem6 = new Trem(6, 320, 270, 700, vetor);
    connect(trem6,SIGNAL(updateGUI(int,int,int)),SLOT(updateInterface(int,int,int)));



}

void MainWindow::updateInterface(int id, int x, int y){
    switch(id){
    case 1:
        ui->label_trem1->setGeometry(x, y, 21, 17);
        break;
    case 2:
        ui->label_trem2->setGeometry(x, y, 21, 17);
        break;
    case 3:
        ui->label_trem3->setGeometry(x, y, 21, 17);
        break;
    case 4:
        ui->label_trem4->setGeometry(x, y, 21, 17);
        break;
    case 5:
        ui->label_trem5->setGeometry(x, y, 21, 17);
        break;
    case 6:
        ui->label_trem6->setGeometry(x, y, 21, 17);
        break;
    default:
        break;
    }
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::on_botao_iniciar_clicked()
{
    trem1->start();
    trem2->start();
    trem3->start();
    trem4->start();
    trem5->start();
    trem6->start();
}

void MainWindow::on_botao_pausar_clicked()
{
    if(flag == 1){
        ui->pushButton_2->setText("Retomar");
        flag = 0;
    }

    else if(flag == 0){
        ui->pushButton_2->setText("Pausar");
        flag = 1;
    }

    trem1->finalizar();
    trem2->finalizar();
    trem3->finalizar();
    trem4->finalizar();
    trem5->finalizar();
    trem6->finalizar();
}
