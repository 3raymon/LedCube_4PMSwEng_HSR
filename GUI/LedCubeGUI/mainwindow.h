#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include "serialportwriter.h"
#include <QMainWindow>
#include <QSerialPort>
#include <QSerialPortInfo>
#include <QTimer>
#include <QPushButton>

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

    /**
     * @brief If programm button 1 is clicked, programmcode "01" is sent.
     *
     * 1. buffer is cleared
     * 2. Via serialPort programmcoe "01" is sent
     *
     */
    void on_portsReloadButton_clicked();

    void on_portSelect_currentTextChanged(const QString &arg1);

    void on_baudSelect_currentTextChanged(const QString &arg1);

    void onReadyRead();

    void updateStatusLabel();

    void updateButtons();

    void on_programm1Button_clicked();

    void on_programm2Button_clicked();

    void on_programm3Button_clicked();

    void on_programm4Button_clicked();

    void on_programm5Button_clicked();

    void on_programm6Button_clicked();

    void on_programm7Button_clicked();

    void on_programm8Button_clicked();

private:
    Ui::MainWindow *ui;
    QString serialPortName = nullptr;
    qint32 baudRate;
    QSerialPort serialPort;
    char buffer[64] = {0};
    QString serialResponse;
    int activeProgramm = 0;
    bool serialPortOpenFlag = false;

    //Fusetimer
    QTimer *fuseTimer = new QTimer(this);
    bool fuseTimerActive = false;

    int fuseTimerIterator = 0;

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
                                          "RAIN\n",
                                          "RANDOM\n",
                                          "PINGPONG\n",
                                          "STROBO\n",
                                          "AUFAB\n",
                                          "LINKSRECHTS\n",
                                          "SCHLANGE\n",
                                          "AUDIO\n",
                                          "MATRIX\n"
                                          };

    QList<QPushButton*> programmButtons;

};
#endif // MAINWINDOW_H
