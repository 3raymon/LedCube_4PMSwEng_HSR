#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <QApplication>
#include <iostream>

/*
 * DOXYGEN HELP
@brief - kurze Beschreibung des folgenden Codes
@param abc - Beschreibung des Parameters abc einer Funktion
@return - Beschreibung des Rückgabewertes einer Funktion
@class abc - Beschreibung der Klasse abc
@file abc.de - Beschreibung der Datei abc.de
*/


/**
 * @brief get informations about attached serial port devices, its used only for debuggin.
 *
 * Function will write fallowing informations to cout
 * - port name
 * - desciption
 * - serial number
 * - system location
 * - vendor identifier
 * - product identifier
 */
void getSerialPortInfos();

int main(int argc, char *argv[])
{

    QApplication a(argc, argv);

    MainWindow w;
    w.show();

    return a.exec();
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
