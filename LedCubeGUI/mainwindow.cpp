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

    //Try to open serial port on startup
    if(serialPort.open(QIODevice::ReadWrite)){
        serialPortOpenFlag = true;
    }else{
        ui->statusLabel->setText("Could not open Port at Startup");
    }

    /**
     * @brief Init Timer interrupt, used if serialPort interrupt is not working properly
     */
    connect(fuseTimer, &QTimer::timeout, this, &MainWindow::onReadyRead);

    /**
     * @brief Init SerialPort interrupt, used to interrupt as soon data arrived to read on serialPort
     */
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
    //Close active port
    serialPort.close();
    serialPortOpenFlag = false;

    //Set current Text from portSelect as PortName
    serialPort.setPortName(arg1);

    //open port with new PortName
    serialPort.open(QSerialPort::ReadWrite);

}

void MainWindow::on_baudSelect_currentTextChanged(const QString &arg1)
{
    //Close active port
    serialPort.close();
    serialPortOpenFlag = false;

    serialPort.setBaudRate(arg1.toInt());

    //open port with new Baudrate
    serialPort.open(QSerialPort::ReadWrite);


}

void MainWindow::onReadyRead()
{
    serialPort.read(buffer, 64) ? ui->statusLabel->setText("read success") : ui->statusLabel->setText("read fail");
    std::cout << "Buffer:" << buffer << std::endl;

    serialResponse = buffer;

    for(int i = 0; i < ProgrammUartResponse.size(); ++i){
        if(ProgrammUartResponse[i] == serialResponse){
            activeProgramm = i;
            break;

        }else{
            activeProgramm = 0;
        }

    }

    std::cout << "activeProgramm:" << activeProgramm << std::endl;

    if(activeProgramm){
        //updateStatusLabel();
        //updateButtons();
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

void MainWindow::updateStatusLabel()
{
    switch(activeProgramm){
    case 0:
        ui->statusLabel->setText("No active Programm");
        break;
    case 1:
        ui->statusLabel->setText(ui->programm1Button->text());
        break;
    case 2:
        ui->statusLabel->setText(ui->programm2Button->text());
        break;
    case 3:
        ui->statusLabel->setText(ui->programm3Button->text());
        break;
    case 4:
        ui->statusLabel->setText(ui->programm4Button->text());
        break;
    case 5:
        ui->statusLabel->setText(ui->programm5Button->text());
        break;
    case 6:
        ui->statusLabel->setText(ui->programm6Button->text());
        break;
    case 7:
        ui->statusLabel->setText(ui->programm7Button->text());
        break;
    case 8:
        ui->statusLabel->setText(ui->programm8Button->text());
        break;
    default:
        ui->statusLabel->setText("Running");
        break;
    }
}


void MainWindow::updateButtons()
{
    //this->setStyleSheet(colInactive);
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


