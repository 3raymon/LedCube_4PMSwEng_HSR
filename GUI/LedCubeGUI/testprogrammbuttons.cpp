#include "testprogrammbuttons.h"

TestProgrammButtons::TestProgrammButtons(QObject *parent) : QObject(parent)
{

}

TestProgrammButtons::~TestProgrammButtons(){
    delete ui;
}

void TestProgrammButtons::initTestCase(){

}

void TestProgrammButtons::programm1(){
    ui->programm1Button->click();
}

QTEST_MAIN(TestProgrammButtons)
//#include "testprogrammbuttons.moc"
