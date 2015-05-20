#ifndef SERVER_H
#define SERVER_H
#include <QThread>
#include <fstream>
#include <string>

class Server: public QThread{
Q_OBJECT
public:
    Server();
    void run();

signals:
    void atualizar(int, int);
};

#endif // SERVER_H
