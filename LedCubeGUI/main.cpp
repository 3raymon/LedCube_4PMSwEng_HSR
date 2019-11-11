#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <QApplication>
#include <iostream>

void getSerialPortInfos();

int main(int argc, char *argv[])
{

    QApplication a(argc, argv);

    MainWindow w;
    w.show();

    return a.exec();

/*
    QSerialPort test;
    test.setPortName("COM2");
    test.setBaudRate(9600);
    char *buffer = new char[64];
    QString buffer_string;

    test.open(QIODevice::ReadOnly);
    test.waitForReadyRead(10000) ? std::cout << "ready to read" << std::endl : std::cout << "timeout" << std::endl;
    test.read(buffer, 64) ? std::cout << "read success" << std::endl : std::cout << "ready fail" << std::endl;


    std::cout << "Buffer:" << std::endl << buffer << std::endl;

    return 0;
*/
}

void getSerialPortInfos()
{
    const auto portsInfos = QSerialPortInfo::availablePorts();
    for (const QSerialPortInfo &portsInfos : portsInfos) {
        QString s = portsInfos.portName();

        std::cout << "PortName: " << portsInfos.portName().toStdString() << std::endl;
        std::cout << "Description: " << portsInfos.description().toStdString() << std::endl;
        std::cout << "SerialNumber: " << portsInfos.serialNumber().toStdString() << std::endl;
        std::cout << "SystemLocation: " << portsInfos.systemLocation().toStdString() << std::endl;
        std::cout << "verndorIdentifier: " << portsInfos.vendorIdentifier() << std::endl;
        std::cout << "productIdentifier: " << portsInfos.productIdentifier() << std::endl;
    }
}
