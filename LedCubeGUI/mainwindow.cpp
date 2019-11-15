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


    //If Arduino is attached, serialPortName is set on protsReloadButton. Else it is set here
    if(serialPortName == nullptr)serialPortName = ui->portSelect->currentText();
    baudRate = ui->baudSelect->currentText().toInt();

    //TEST
    if(serialPort.open(QIODevice::ReadWrite)){
        serialPortOpenFlag = true;
    }else{
        ui->statusLabel->setText("Could not open Port");
    }

    connect(fuseTimer, &QTimer::timeout, this, &MainWindow::onReadyRead);
    connect(&serialPort, &QSerialPort::readyRead, this, &MainWindow::onReadyRead);

}

MainWindow::~MainWindow()
{
    delete ui;
}


void MainWindow::on_programm1Button_clicked()
{

    //Clean Buffer before writeing
    for(int i = 0; i < 64; ++i) buffer[i] = 0;

    //Write
    serialPort.write(ProgrammUartRequests[1]) ? ui->statusLabel->setText("written successfully") : ui->statusLabel->setText("could not write to device");
    serialPort.waitForBytesWritten(100);


    //Read
    if(fuseTimerActive)fuseTimer->start(1000);
    //if(serialPort.waitForReadyRead(10000))onReadyRead();

}

void MainWindow::on_portsReloadButton_clicked()
{
    const auto portsInfos = QSerialPortInfo::availablePorts();
    ui->portSelect->clear();

    for (const QSerialPortInfo &portsInfos : portsInfos) {
        QString s = portsInfos.portName();
        ui->portSelect->addItem(s);

        //Select Arduino if avaliable
        if(portsInfos.productIdentifier() == uint16_t(66) ){
            serialPortName = portsInfos.portName();
            ui->portSelect->setCurrentText(serialPortName);
        }
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
    std::cout << "Buffer:" << buffer << std::endl;

    serialResponse = buffer;

    for(int i = 0; i < ProgrammUartResponse.size(); ++i){
        serialResponse == ProgrammUartResponse[i] ? activeProgramm = i : activeProgramm = 0;
    }

    std::cout << "activeProgramm:" << activeProgramm << std::endl;

    if(activeProgramm){
        updateStatusLabel();
        updateButtons();
        if(serialPortOpenFlag)serialPort.close();
    }else if(fuseTimerActive){
        fuseTimer->start(1000);
        ++fuseTimerIterator;
    }

    if(fuseTimerActive && (fuseTimerIterator > 10)){
        ui->statusLabel->setText("read timeout");
        fuseTimer->stop();
    }
}

void MainWindow::bufferCheck()
{
    onReadyRead();
}

void MainWindow::updateStatusLabel()
{
    switch(activeProgramm){
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
    switch(activeProgramm){
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


