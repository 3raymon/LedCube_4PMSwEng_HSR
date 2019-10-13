#include "mainwindow.h"
#include "ui_mainwindow.h"
#include<QSerialPortInfo>
#include<iostream>

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent), ui(new Ui::MainWindow)
{
    ui->setupUi(this);

    ui->portsReloadButton->click();
    ui->baudSelect->setCurrentText("9600");
    serialPortName = ui->portSelect->currentText();
    baudRate = ui->baudSelect->currentText().toInt();
}

MainWindow::~MainWindow()
{
    delete ui;
}


void MainWindow::on_programm1Button_clicked()
{
    QSerialPort serialPort;
    serialPort.setPortName(serialPortName);
    serialPort.setBaudRate(baudRate);

    if(!(serialPort.open(QIODevice::WriteOnly)))ui->statusLabel->setText("Could not open Port");
    serialPort.write("Programm1") ? ui->statusLabel->setText("written successfully") : ui->statusLabel->setText("could not write to device");
    serialPort.waitForBytesWritten() ? ui->statusLabel->setText("written successfully") : ui->statusLabel->setText("could not write to device (timeout)");
    serialPort.close();
    
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
    serialPortName = arg1;
}

void MainWindow::on_baudSelect_currentTextChanged(const QString &arg1)
{
    baudRate = arg1.toInt();
}
