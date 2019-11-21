/********************************************************************************
** Form generated from reading UI file 'mainwindow.ui'
**
** Created by: Qt User Interface Compiler version 5.13.1
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_MAINWINDOW_H
#define UI_MAINWINDOW_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QComboBox>
#include <QtWidgets/QFrame>
#include <QtWidgets/QGridLayout>
#include <QtWidgets/QGroupBox>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QLabel>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QMenuBar>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QStatusBar>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_MainWindow
{
public:
    QWidget *centralwidget;
    QFrame *frame;
    QGridLayout *gridLayout;
    QPushButton *programm1Button;
    QPushButton *programm5Button;
    QPushButton *programm2Button;
    QPushButton *programm6Button;
    QPushButton *programm3Button;
    QPushButton *programm7Button;
    QPushButton *programm4Button;
    QPushButton *programm8Button;
    QGroupBox *groupBox;
    QVBoxLayout *verticalLayout;
    QHBoxLayout *settingsGroup;
    QHBoxLayout *portGroup;
    QPushButton *portsReloadButton;
    QLabel *portLabel;
    QComboBox *portSelect;
    QHBoxLayout *baudrateGroup;
    QLabel *baudrateLabel;
    QComboBox *baudSelect;
    QHBoxLayout *statusGroup;
    QLabel *showStatusLabel;
    QLabel *programmStatusLabel;
    QLabel *portStatusLabel;
    QMenuBar *menubar;
    QStatusBar *statusbar;

    void setupUi(QMainWindow *MainWindow)
    {
        if (MainWindow->objectName().isEmpty())
            MainWindow->setObjectName(QString::fromUtf8("MainWindow"));
        MainWindow->resize(696, 688);
        QSizePolicy sizePolicy(QSizePolicy::Fixed, QSizePolicy::Fixed);
        sizePolicy.setHorizontalStretch(0);
        sizePolicy.setVerticalStretch(0);
        sizePolicy.setHeightForWidth(MainWindow->sizePolicy().hasHeightForWidth());
        MainWindow->setSizePolicy(sizePolicy);
        MainWindow->setAnimated(true);
        centralwidget = new QWidget(MainWindow);
        centralwidget->setObjectName(QString::fromUtf8("centralwidget"));
        centralwidget->setEnabled(true);
        frame = new QFrame(centralwidget);
        frame->setObjectName(QString::fromUtf8("frame"));
        frame->setGeometry(QRect(30, 120, 641, 521));
        gridLayout = new QGridLayout(frame);
        gridLayout->setObjectName(QString::fromUtf8("gridLayout"));
        gridLayout->setContentsMargins(1, -1, 1, 1);
        programm1Button = new QPushButton(frame);
        programm1Button->setObjectName(QString::fromUtf8("programm1Button"));
        QSizePolicy sizePolicy1(QSizePolicy::Minimum, QSizePolicy::Preferred);
        sizePolicy1.setHorizontalStretch(0);
        sizePolicy1.setVerticalStretch(0);
        sizePolicy1.setHeightForWidth(programm1Button->sizePolicy().hasHeightForWidth());
        programm1Button->setSizePolicy(sizePolicy1);
        programm1Button->setStyleSheet(QString::fromUtf8(""));

        gridLayout->addWidget(programm1Button, 0, 0, 1, 1);

        programm5Button = new QPushButton(frame);
        programm5Button->setObjectName(QString::fromUtf8("programm5Button"));
        programm5Button->setStyleSheet(QString::fromUtf8(""));

        gridLayout->addWidget(programm5Button, 0, 1, 1, 1);

        programm2Button = new QPushButton(frame);
        programm2Button->setObjectName(QString::fromUtf8("programm2Button"));
        programm2Button->setStyleSheet(QString::fromUtf8(""));

        gridLayout->addWidget(programm2Button, 1, 0, 1, 1);

        programm6Button = new QPushButton(frame);
        programm6Button->setObjectName(QString::fromUtf8("programm6Button"));
        programm6Button->setStyleSheet(QString::fromUtf8(""));

        gridLayout->addWidget(programm6Button, 1, 1, 1, 1);

        programm3Button = new QPushButton(frame);
        programm3Button->setObjectName(QString::fromUtf8("programm3Button"));
        programm3Button->setStyleSheet(QString::fromUtf8(""));

        gridLayout->addWidget(programm3Button, 2, 0, 1, 1);

        programm7Button = new QPushButton(frame);
        programm7Button->setObjectName(QString::fromUtf8("programm7Button"));
        programm7Button->setStyleSheet(QString::fromUtf8(""));

        gridLayout->addWidget(programm7Button, 2, 1, 1, 1);

        programm4Button = new QPushButton(frame);
        programm4Button->setObjectName(QString::fromUtf8("programm4Button"));
        programm4Button->setStyleSheet(QString::fromUtf8(""));

        gridLayout->addWidget(programm4Button, 3, 0, 1, 1);

        programm8Button = new QPushButton(frame);
        programm8Button->setObjectName(QString::fromUtf8("programm8Button"));
        programm8Button->setStyleSheet(QString::fromUtf8(""));

        gridLayout->addWidget(programm8Button, 3, 1, 1, 1);

        groupBox = new QGroupBox(centralwidget);
        groupBox->setObjectName(QString::fromUtf8("groupBox"));
        groupBox->setGeometry(QRect(30, 10, 641, 101));
        verticalLayout = new QVBoxLayout(groupBox);
        verticalLayout->setObjectName(QString::fromUtf8("verticalLayout"));
        settingsGroup = new QHBoxLayout();
        settingsGroup->setObjectName(QString::fromUtf8("settingsGroup"));
        portGroup = new QHBoxLayout();
        portGroup->setObjectName(QString::fromUtf8("portGroup"));
        portsReloadButton = new QPushButton(groupBox);
        portsReloadButton->setObjectName(QString::fromUtf8("portsReloadButton"));

        portGroup->addWidget(portsReloadButton);

        portLabel = new QLabel(groupBox);
        portLabel->setObjectName(QString::fromUtf8("portLabel"));

        portGroup->addWidget(portLabel);

        portSelect = new QComboBox(groupBox);
        portSelect->setObjectName(QString::fromUtf8("portSelect"));
        portSelect->setEnabled(true);
        portSelect->setStyleSheet(QString::fromUtf8(""));
        portSelect->setEditable(true);

        portGroup->addWidget(portSelect);


        settingsGroup->addLayout(portGroup);

        baudrateGroup = new QHBoxLayout();
        baudrateGroup->setObjectName(QString::fromUtf8("baudrateGroup"));
        baudrateLabel = new QLabel(groupBox);
        baudrateLabel->setObjectName(QString::fromUtf8("baudrateLabel"));

        baudrateGroup->addWidget(baudrateLabel);

        baudSelect = new QComboBox(groupBox);
        baudSelect->addItem(QString());
        baudSelect->addItem(QString());
        baudSelect->addItem(QString());
        baudSelect->addItem(QString());
        baudSelect->addItem(QString());
        baudSelect->addItem(QString());
        baudSelect->addItem(QString());
        baudSelect->addItem(QString());
        baudSelect->setObjectName(QString::fromUtf8("baudSelect"));
        baudSelect->setEnabled(true);
        baudSelect->setStyleSheet(QString::fromUtf8(""));
        baudSelect->setEditable(false);

        baudrateGroup->addWidget(baudSelect);


        settingsGroup->addLayout(baudrateGroup);


        verticalLayout->addLayout(settingsGroup);

        statusGroup = new QHBoxLayout();
        statusGroup->setObjectName(QString::fromUtf8("statusGroup"));
        showStatusLabel = new QLabel(groupBox);
        showStatusLabel->setObjectName(QString::fromUtf8("showStatusLabel"));
        QSizePolicy sizePolicy2(QSizePolicy::Preferred, QSizePolicy::Maximum);
        sizePolicy2.setHorizontalStretch(0);
        sizePolicy2.setVerticalStretch(0);
        sizePolicy2.setHeightForWidth(showStatusLabel->sizePolicy().hasHeightForWidth());
        showStatusLabel->setSizePolicy(sizePolicy2);

        statusGroup->addWidget(showStatusLabel);

        programmStatusLabel = new QLabel(groupBox);
        programmStatusLabel->setObjectName(QString::fromUtf8("programmStatusLabel"));

        statusGroup->addWidget(programmStatusLabel);

        portStatusLabel = new QLabel(groupBox);
        portStatusLabel->setObjectName(QString::fromUtf8("portStatusLabel"));

        statusGroup->addWidget(portStatusLabel);


        verticalLayout->addLayout(statusGroup);

        MainWindow->setCentralWidget(centralwidget);
        menubar = new QMenuBar(MainWindow);
        menubar->setObjectName(QString::fromUtf8("menubar"));
        menubar->setGeometry(QRect(0, 0, 696, 21));
        MainWindow->setMenuBar(menubar);
        statusbar = new QStatusBar(MainWindow);
        statusbar->setObjectName(QString::fromUtf8("statusbar"));
        MainWindow->setStatusBar(statusbar);

        retranslateUi(MainWindow);

        QMetaObject::connectSlotsByName(MainWindow);
    } // setupUi

    void retranslateUi(QMainWindow *MainWindow)
    {
        MainWindow->setWindowTitle(QCoreApplication::translate("MainWindow", "LedCube Control Center", nullptr));
        programm1Button->setText(QCoreApplication::translate("MainWindow", "Rain", nullptr));
        programm5Button->setText(QCoreApplication::translate("MainWindow", "Auf/Ab", nullptr));
        programm2Button->setText(QCoreApplication::translate("MainWindow", "Random", nullptr));
        programm6Button->setText(QCoreApplication::translate("MainWindow", "Links/Rechts", nullptr));
        programm3Button->setText(QCoreApplication::translate("MainWindow", "Pingpong", nullptr));
        programm7Button->setText(QCoreApplication::translate("MainWindow", "Schlange", nullptr));
        programm4Button->setText(QCoreApplication::translate("MainWindow", "Strobo", nullptr));
        programm8Button->setText(QCoreApplication::translate("MainWindow", "Audio", nullptr));
        portsReloadButton->setText(QCoreApplication::translate("MainWindow", "Ports Reload", nullptr));
        portLabel->setText(QCoreApplication::translate("MainWindow", "Port:", nullptr));
#if QT_CONFIG(accessibility)
        portSelect->setAccessibleName(QString());
#endif // QT_CONFIG(accessibility)
        portSelect->setCurrentText(QCoreApplication::translate("MainWindow", "Port", nullptr));
        baudrateLabel->setText(QCoreApplication::translate("MainWindow", "Baudrate:", nullptr));
        baudSelect->setItemText(0, QCoreApplication::translate("MainWindow", "1200", nullptr));
        baudSelect->setItemText(1, QCoreApplication::translate("MainWindow", "2400", nullptr));
        baudSelect->setItemText(2, QCoreApplication::translate("MainWindow", "4800", nullptr));
        baudSelect->setItemText(3, QCoreApplication::translate("MainWindow", "9600", nullptr));
        baudSelect->setItemText(4, QCoreApplication::translate("MainWindow", "19200", nullptr));
        baudSelect->setItemText(5, QCoreApplication::translate("MainWindow", "38400", nullptr));
        baudSelect->setItemText(6, QCoreApplication::translate("MainWindow", "57600", nullptr));
        baudSelect->setItemText(7, QCoreApplication::translate("MainWindow", "115200", nullptr));

#if QT_CONFIG(accessibility)
        baudSelect->setAccessibleName(QString());
#endif // QT_CONFIG(accessibility)
        showStatusLabel->setText(QCoreApplication::translate("MainWindow", "Status:", nullptr));
        programmStatusLabel->setText(QCoreApplication::translate("MainWindow", "*Inacive*", nullptr));
        portStatusLabel->setText(QCoreApplication::translate("MainWindow", "*Inacive*", nullptr));
    } // retranslateUi

};

namespace Ui {
    class MainWindow: public Ui_MainWindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MAINWINDOW_H
