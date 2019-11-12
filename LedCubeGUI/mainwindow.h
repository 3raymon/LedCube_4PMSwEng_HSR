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

    void onReadyRead();

    void updateStatusLabel();

    void updateButtons();

private:
    Ui::MainWindow *ui;
    QString serialPortName;
    qint32 baudRate;
    QSerialPort serialPort;
    char buffer[64] = {0};
    QString serialResponse;
    int activeProgramm = 0;
    bool serialPortOpenFlag = false;
    QTimer *timer = new QTimer(this);

    QString colActive = QString("background-color: green");
    QString colInactive = QString("background-color: 0");

    QList<QByteArray> ProgrammUartRequests= {"\x00",
                                           "\x01",
                                           "\x02",
                                           "\x03",
                                           "\x04",
                                           "\x05",
                                           "\x06",
                                           "\x07",
                                           "\x08",
                                           ""
                                          };

    QList<QString> ProgrammUartResponse= {"",
                                          "RAIN",
                                           "RANDOM",
                                           "PYRAMID",
                                           "STROBO",
                                           "AUF/AB",
                                           "LINKS/RECHTS",
                                           "SCHLANGE",
                                           "AUDIO",
                                           "MATRIX"
                                          };

};
#endif // MAINWINDOW_H
