#include "server.h"

Server::Server(){
    //Main Window Connection
    connect(&w, SIGNAL(buttonPressed()), &nodeMCU, SLOT(onButtonPressed()));
    connect(&nodeMCU, SIGNAL(setState(int)), &w, SLOT(onSetState(int)));
}

void Server::startServer(){
    if(listen(QHostAddress::Any, 8888)){
        qInfo() << "Server Started";
        w.show();
    } else {
        qCritical() << "Server Failed to Start";
    }
}

void Server::incomingConnection(qintptr handle){
    Client *client = new Client(this);
    client->setSocket(handle);
    //Request Connection
    connect(&nodeMCU, SIGNAL(sendState(int)), client, SLOT(sendState(int)));
    connect(client, SIGNAL(getState()), &nodeMCU, SLOT(onGetState()));

    //Get Data form Client Connection
    connect(client, SIGNAL(setState(int)), &nodeMCU, SLOT(onSetState(int)));
}
