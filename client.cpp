#include "client.h"

Client::Client(QObject *parent) : QObject(parent)
{

}

void Client::setSocket(int Descriptor){
    socket = new QTcpSocket(this);
    connect(socket, SIGNAL(connected()), this, SLOT(connected()));
    connect(socket, SIGNAL(disconnected()), this, SLOT(disconnected()));
    connect(socket, SIGNAL(readyRead()), this, SLOT(readyRead()));
    socket->setSocketDescriptor(Descriptor);
    qInfo() << "client connected";

}

void Client::connected(){
    qInfo() << "client connected event";
}

void Client::disconnected(){
    qInfo() << "client disconnected";
}

void Client::readyRead(){
    //qInfo() << socket->readAll();
    QByteArray bufferReader = socket->readAll();
    std::string stringBuffer(bufferReader.constData(), 3);
    //qInfo() << QString::fromStdString(stringBuffer);
    int bufferchar = stringBuffer.at(2);
    if(bufferchar == 's'){
        //qInfo()<< "Requested";
        emit getState();
    } else if(bufferchar == '0'){
        //qInfo()<< "MATI";
        emit setState(0);
    } else if(bufferchar == '1'){
        //qInfo()<< "HIDUP";
        emit setState(1);
    } else {

    }
}

void Client::sendState(int state){
    switch(state){
    case 0:
        socket->write("0\n");
        break;
    case 1:
        socket->write("1\n");
        break;
    }
}
