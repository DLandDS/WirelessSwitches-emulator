#ifndef NODEMCU_H
#define NODEMCU_H

#include <QObject>

class NodeMCU : public QObject
{
    Q_OBJECT
public:
    explicit NodeMCU(QObject *parent = nullptr);

signals:
    void setState(int state);
    void sendState(int state);
public slots:
    void onButtonPressed();
    void onGetState();
    void onSetState(int state);
private:
    int state = 0;
};

#endif // NODEMCU_H
