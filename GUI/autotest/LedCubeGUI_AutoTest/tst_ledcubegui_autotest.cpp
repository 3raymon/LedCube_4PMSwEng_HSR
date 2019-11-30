#include <QtTest>
//#include <QCoreApplication>
#include <QApplication>
#include "mainwindow.h"
#include "ui_mainwindow.h"

// add necessary includes here

class LedCubeGUI_AutoTest : public QObject
{
    Q_OBJECT

public:
    LedCubeGUI_AutoTest();
    ~LedCubeGUI_AutoTest();


private slots:
    /**
     * @brief test_programm1Button_buffer Test if Buffer is empty after programm1Button clicked
     */
    void test_programm1Button_buffer();

private:
    MainWindow testWindow;

};

LedCubeGUI_AutoTest::LedCubeGUI_AutoTest()
{

}

LedCubeGUI_AutoTest::~LedCubeGUI_AutoTest()
{

}


void LedCubeGUI_AutoTest::test_programm1Button_buffer()
{
    //Writing to buffer
    testWindow.buffer[12] = 'i';

    //Perform click acction
    testWindow.ui->programm1Button->click();

    //Check if buffer is empty
    for(int i = 0; i < 64; ++i){
        QCOMPARE(testWindow.buffer[i], 0);
    }

}

QTEST_MAIN(LedCubeGUI_AutoTest)
#include "tst_ledcubegui_autotest.moc"


