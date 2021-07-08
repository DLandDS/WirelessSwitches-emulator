#ifndef SERVER_H
#define SERVER_H

#include <QTcpServer>
#include <QTcpSocket>
#include <QAbstractSocket>
#include "client.h"
#include "mainwindow.h"
#include "nodemcu.h"

class Server : public QTcpServer {
    Q_OBJECT
public:
    Server();
    void startServer();

protected:
    void incomingConnection(qintptr handle);
private:
    MainWindow w;
    NodeMCU nodeMCU;
};

#endif // SERVER_H
