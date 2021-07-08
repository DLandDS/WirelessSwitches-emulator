#include "mainwindow.h"
#include "ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent) : QMainWindow(parent), ui(new Ui::MainWindow){
    ui->setupUi(this);
}

MainWindow::~MainWindow(){
    delete ui;
}


void MainWindow::on_toggle_clicked()
{
    emit buttonPressed();
}

void MainWindow::onSetState(int state){
    switch(state){
    case 0:
        ui->LEDState->setText("OFF");
        break;
    case 1:
        ui->LEDState->setText("ON");
        break;
    }
}

