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
        ui->portStatusLabel->setText("Could not open Port at Startup");
    }

    /**
     * @brief Init Timer interrupt, used if serialPort interrupt is not working properly
     */
    connect(fuseTimer, &QTimer::timeout, this, &MainWindow::onReadyRead);

    /**
     * @brief Init SerialPort interrupt, used to interrupt as soon data arrived to read on serialPort
     */
    connect(&serialPort, &QSerialPort::readyRead, this, &MainWindow::onReadyRead);

    /**
     * @brief List containing programmButtons
     *
     * Used for easyer handling with programmButton updates
     */
    programmButtons.append(ui->programm1Button);
    programmButtons.append(ui->programm2Button);
    programmButtons.append(ui->programm3Button);
    programmButtons.append(ui->programm4Button);
    programmButtons.append(ui->programm5Button);
    programmButtons.append(ui->programm6Button);
    programmButtons.append(ui->programm7Button);
    programmButtons.append(ui->programm8Button);



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
    serialPort.write(ProgrammUartRequests[1]);
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
    int oldActiveProgramm = activeProgramm;
    serialPort.read(buffer, 64);
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
    oldActiveProgramm == activeProgramm ? ui->portStatusLabel->setText("read fail, try again!") : ui->portStatusLabel->setText("read success");

    std::cout << "activeProgramm:" << activeProgramm << std::endl;

    //Update UI
    updateStatusLabel();
    updateButtons();

    if(activeProgramm){
        if(serialPortOpenFlag)serialPort.close();
    }else if(fuseTimerActive){
        fuseTimer->start(1000);
        ++fuseTimerIterator;
    }

    if(fuseTimerActive && (fuseTimerIterator > 10)){
        ui->portStatusLabel->setText("read timeout");
        fuseTimer->stop();
    }
}

void MainWindow::updateStatusLabel()
{
    switch(activeProgramm){
    case 0:
        ui->programmStatusLabel->setText("No active Programm");
        break;
    case 1:
        ui->programmStatusLabel->setText(ui->programm1Button->text());
        break;
    case 2:
        ui->programmStatusLabel->setText(ui->programm2Button->text());
        break;
    case 3:
        ui->programmStatusLabel->setText(ui->programm3Button->text());
        break;
    case 4:
        ui->programmStatusLabel->setText(ui->programm4Button->text());
        break;
    case 5:
        ui->programmStatusLabel->setText(ui->programm5Button->text());
        break;
    case 6:
        ui->programmStatusLabel->setText(ui->programm6Button->text());
        break;
    case 7:
        ui->programmStatusLabel->setText(ui->programm7Button->text());
        break;
    case 8:
        ui->programmStatusLabel->setText(ui->programm8Button->text());
        break;
    default:
        ui->programmStatusLabel->setText("Running");
        break;
    }
}


void MainWindow::updateButtons()
{
    for(QPushButton* elem: programmButtons){
        elem->setStyleSheet(colInactive);
    }

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



void MainWindow::on_programm2Button_clicked()
{
    //Clean Buffer before writeing
    for(int i = 0; i < 64; ++i) buffer[i] = 0;

    //Write
    serialPort.write(ProgrammUartRequests[2]) ? ui->portStatusLabel->setText("written successfully") : ui->portStatusLabel->setText("could not write to device, Try again");
    serialPort.waitForBytesWritten(100);
}

void MainWindow::on_programm3Button_clicked()
{
    //Clean Buffer before writeing
    for(int i = 0; i < 64; ++i) buffer[i] = 0;

    //Write
    serialPort.write(ProgrammUartRequests[3]) ? ui->portStatusLabel->setText("written successfully") : ui->portStatusLabel->setText("could not write to device, Try again");
    serialPort.waitForBytesWritten(100);
}

void MainWindow::on_programm4Button_clicked()
{
    //Clean Buffer before writeing
    for(int i = 0; i < 64; ++i) buffer[i] = 0;

    //Write
    serialPort.write(ProgrammUartRequests[4]) ? ui->portStatusLabel->setText("written successfully") : ui->portStatusLabel->setText("could not write to device, Try again");
    serialPort.waitForBytesWritten(100);
}

void MainWindow::on_programm5Button_clicked()
{
    //Clean Buffer before writeing
    for(int i = 0; i < 64; ++i) buffer[i] = 0;

    //Write
    serialPort.write(ProgrammUartRequests[5]) ? ui->portStatusLabel->setText("written successfully") : ui->portStatusLabel->setText("could not write to device, Try again");
    serialPort.waitForBytesWritten(100);
}

void MainWindow::on_programm6Button_clicked()
{
    //Clean Buffer before writeing
    for(int i = 0; i < 64; ++i) buffer[i] = 0;

    //Write
    serialPort.write(ProgrammUartRequests[6]) ? ui->portStatusLabel->setText("written successfully") : ui->portStatusLabel->setText("could not write to device, Try again");
    serialPort.waitForBytesWritten(100);
}

void MainWindow::on_programm7Button_clicked()
{
    //Clean Buffer before writeing
    for(int i = 0; i < 64; ++i) buffer[i] = 0;

    //Write
    serialPort.write(ProgrammUartRequests[7]) ? ui->portStatusLabel->setText("written successfully") : ui->portStatusLabel->setText("could not write to device, Try again");
    serialPort.waitForBytesWritten(100);
}

void MainWindow::on_programm8Button_clicked()
{
    //Clean Buffer before writeing
    for(int i = 0; i < 64; ++i) buffer[i] = 0;

    //Write
    serialPort.write(ProgrammUartRequests[8]) ? ui->portStatusLabel->setText("written successfully") : ui->portStatusLabel->setText("could not write to device, Try again");
    serialPort.waitForBytesWritten(100);
}
