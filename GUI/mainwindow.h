#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include "serialportwriter.h"
#include <QMainWindow>
#include <QSerialPort>
#include <QSerialPortInfo>

QT_BEGIN_NAMESPACE
namespace Ui { class MainWindow; }
QT_END_NAMESPACE

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();

private slots:
    void on_programm1Button_clicked();

    void on_portsReloadButton_clicked();

    void on_portSelect_currentTextChanged(const QString &arg1);

    void on_baudSelect_currentTextChanged(const QString &arg1);

private:
    Ui::MainWindow *ui;
    QString serialPortName;
    qint32 baudRate;
};
#endif // MAINWINDOW_H
