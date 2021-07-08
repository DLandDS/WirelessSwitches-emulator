#include "nodemcu.h"

NodeMCU::NodeMCU(QObject *parent) : QObject(parent)
{

}

void NodeMCU::onButtonPressed(){
    if(this->state == 0){
        this->state = 1;
    } else if(this->state == 1){
        this->state = 0;
    }
    emit setState(this->state);
}

void NodeMCU::onGetState(){
    emit setState(this->state);
    emit sendState(this->state);
}

void NodeMCU::onSetState(int state){
    this->state = state;
    emit setState(this->state);
}
