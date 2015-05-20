#include "server.h"
#include <QtCore>
#include <stdio.h>
#include <stdlib.h>
#include <errno.h>
#include <string.h> //bzero
//Bibliotecas socket
#include <sys/types.h>  //AF_INET
#include <sys/socket.h> //socket
#include <netinet/in.h> //htons
#include <arpa/inet.h>  //inet_ntoa
#include <unistd.h>  //close
#include <iostream>

Server::Server(){

}

void Server::run(){

    //Identificador do socket
    int socketId;

    //Struct de endereco
    struct sockaddr_in endereco;

    //Criando o socket (internet, TCP, IP)
    socketId = socket(AF_INET, SOCK_STREAM, 0);

    //Verificar erros
    if (socketId == -1)
    {
        perror("Error socket()\n");
        exit(1);
    }
    //tipo do protocolo
    endereco.sin_family = AF_INET;
    //porta
    endereco.sin_port = htons(4324); //htons() function converts values between host and network byte orders
    //o endereco será qualquer interface de rede do computador
    endereco.sin_addr.s_addr = INADDR_ANY;
    //inserir zeros
    bzero( &( endereco.sin_zero ), 8);

    //Ligando o socket a uma porta do servidor
    if ( bind (socketId, (struct sockaddr *)&endereco, sizeof(struct sockaddr)) == -1 )
    {
        perror("Error bind()\n");
        exit(1);
    }

    //Habilitando o servidor a receber conexoes do cliente
    if ( listen( socketId, 4 ) == -1)
    {
        perror("Error listen()\n");
        exit(1);
    }

    while (true)
    {
        //Variaveis auxiliares para obter informações das conexões

        //Identificador de uma conexao cliente
        int conexaoClienteId;

        char caracter[20]; //Caracter lido do cliente

        QString dados, pot, trem, send; // recebe o char do cliente
        int Pot, Trem, Send;
        QStringList list; //lista os dados
        bool loop = 1;


        //Bytes lidos do cliente
        int bytesLidos;

        //Endereço de uma conexão cliente
        struct sockaddr_in enderecoCliente;

        //Tamanho do endereço do cliente
        socklen_t enderecoClienteTam;

        printf("Servidor: esperando conexões clientes\n");
        //Fica bloqueado esperando uma conexão do cliente
        conexaoClienteId = accept( socketId,
                                   (struct sockaddr *) &enderecoCliente,
                                   &enderecoClienteTam );
        printf("Servidor: recebeu conexão de %s\n", inet_ntoa( enderecoCliente.sin_addr ));

        //Verificando erros
        if ( conexaoClienteId == -1)
        {
            perror("Error accept");
            exit(1);
        }

        //Recebendo um caracter do cliente

        while(loop) {
            if ( bytesLidos = recv (conexaoClienteId, caracter, 20, 0) == -1 )
            {
                perror ("Error recv\n");
                exit(1);
            }
            //printf("Servidor: dado recebido do cliente - %c\n", sms);
            //std::cout << "Servidor: dado recebido do cliente " << caracter << std::endl;
            dados = caracter;
            //std::cout<<dados.toStdString()<<std::endl;

            list = dados.split("-");
            pot = list[0];
            trem = list[1];
            send = list[2];

            list = pot.split(":");
            pot = list[1];

            list = trem.split(":");
            trem = list[1];

            list = send.split(":");
            send = list[1];

            Pot = pot.toInt();
            Trem = trem.toInt();
            Send = send.toInt();
            std::cout<<"Pot: "<<Pot<<" Trem: "<<Trem<<" Send: "<<Send<<std::endl;
            emit atualizar(Pot, Trem);
        }

        //Fechar a conexão cliente criada em accept
        close(conexaoClienteId);
    }
}

