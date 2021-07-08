#include <QApplication>
#include "server.h"

int main(int argc, char *argv[]){
    QApplication a(argc, argv);
    //system("title Wireless Switches Server");
    Server server;

    server.startServer();


    return a.exec();
}
