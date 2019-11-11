#ifndef TESTPROGRAMM1_H
#define TESTPROGRAMM1_H

#include <QObject>
#include <QtWidgets>
#include <QtTest/QtTest>
#include "mainwindow.h"
#include "ui_mainwindow.h"

class TestProgrammButtons : public QObject
{
    Q_OBJECT
public:
    explicit TestProgrammButtons(QObject *parent = nullptr);
    ~TestProgrammButtons();

signals:

private slots:
    void initTestCase();
    void programm1();

private:
 Ui::MainWindow *ui = new Ui::MainWindow;

 };

#endif // TESTPROGRAMM1_H
