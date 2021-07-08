#ifndef CLIENT_H
#define CLIENT_H

#include <QObject>
#include <QTcpSocket>
#include <QString>
#include <iostream>

class Client : public QObject
{
    Q_OBJECT
public:
    explicit Client(QObject *parent = nullptr);
    void setSocket(int Descriptor);

private:
    QTcpSocket *socket;
signals:
    void getState();
    void setState(int state);
public slots:
    void connected();
    void disconnected();
    void readyRead();
    void sendState(int state);
};

#endif // CLIENT_H
