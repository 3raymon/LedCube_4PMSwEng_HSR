#include "mainwindow.h"
#include "ui_mainwindow.h"
#include<QSerialPortInfo>
#include<iostream>

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent), ui(new Ui::MainWindow)
{
    ui->setupUi(this);

    //Setup
    ui->portsReloadButton->click();
    ui->baudSelect->setCurrentText("9600");
    serialPortName = ui->portSelect->currentText();
    baudRate = ui->baudSelect->currentText().toInt();

    connect(&serialPort, &QSerialPort::readyRead, this, &MainWindow::onReadyRead);

}

MainWindow::~MainWindow()
{
    delete ui;
}


void MainWindow::on_programm1Button_clicked()
{
    if(serialPort.open(QIODevice::ReadWrite)){
        serialPortOpenFlag = true;
    }else{
        ui->statusLabel->setText("Could not open Port");
    }

    //Clean Buffer before writeing
    for(int i = 0; i < 64; ++i) buffer[i] = 0;

    //Write
    serialPort.write(ProgrammUartRequests[1]) ? ui->statusLabel->setText("written successfully") : ui->statusLabel->setText("could not write to device");
    serialPort.waitForBytesWritten();

    //Read
    //serialPort.waitForReadyRead(10000) ? ui->statusLabel->setText("ready to read") : ui->statusLabel->setText("timeout");


}

void MainWindow::on_portsReloadButton_clicked()
{
    const auto portsInfos = QSerialPortInfo::availablePorts();
    ui->portSelect->clear();

    for (const QSerialPortInfo &portsInfos : portsInfos) {
        QString s = portsInfos.portName();
        ui->portSelect->addItem(s);
    }

}

void MainWindow::on_portSelect_currentTextChanged(const QString &arg1)
{
    serialPort.setPortName(arg1);
}

void MainWindow::on_baudSelect_currentTextChanged(const QString &arg1)
{
    serialPort.setBaudRate(arg1.toInt());
}

void MainWindow::onReadyRead()
{
    serialPort.read(buffer, 64) ? ui->statusLabel->setText("read success") : ui->statusLabel->setText("read fail");
    serialResponse = buffer;
    std::cout << "Buffer:" << buffer << std::endl;

    for(int i = 0; i < ProgrammUartResponse.size(); ++i){
        serialResponse == ProgrammUartResponse[i] ? actualProgramm = i : actualProgramm = 0;
    }

    if(actualProgramm){
        updateStatusLabel();
        updateButtons();
        if(serialPortOpenFlag)serialPort.close();
    }
}

void MainWindow::updateStatusLabel()
{
    switch(actualProgramm){
    case 0:
        ui->statusLabel->setText("No active Programm");
        break;
    default:
        ui->statusLabel->setText("Running");
        break;
    }
}


void MainWindow::updateButtons()
{
    this->setStyleSheet(colInactive);
    switch(actualProgramm){
    case 1:
        ui->programm1Button->setStyleSheet(colActive);
        break;
    case 2:
        ui->programm2Button->setStyleSheet(colActive);
        break;
    case 3:
        ui->programm3Button->setStyleSheet(colActive);
        break;
    case 4:
        ui->programm4Button->setStyleSheet(colActive);
        break;
    case 5:
        ui->programm5Button->setStyleSheet(colActive);
        break;
    case 6:
        ui->programm6Button->setStyleSheet(colActive);
        break;
    case 7:
        ui->programm7Button->setStyleSheet(colActive);
        break;
    case 8:
        ui->programm8Button->setStyleSheet(colActive);
        break;
    default:
        break;
    }
}


