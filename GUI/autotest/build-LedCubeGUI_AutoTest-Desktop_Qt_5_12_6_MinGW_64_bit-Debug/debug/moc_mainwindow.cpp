/****************************************************************************
** Meta object code from reading C++ file 'mainwindow.h'
**
** Created by: The Qt Meta Object Compiler version 67 (Qt 5.12.6)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "../../LedCubeGUI_AutoTest/mainwindow.h"
#include <QtCore/qbytearray.h>
#include <QtCore/qmetatype.h>
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'mainwindow.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 67
#error "This file was generated using the moc from 5.12.6. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
QT_WARNING_PUSH
QT_WARNING_DISABLE_DEPRECATED
struct qt_meta_stringdata_MainWindow_t {
    QByteArrayData data[17];
    char stringdata0[372];
};
#define QT_MOC_LITERAL(idx, ofs, len) \
    Q_STATIC_BYTE_ARRAY_DATA_HEADER_INITIALIZER_WITH_OFFSET(len, \
    qptrdiff(offsetof(qt_meta_stringdata_MainWindow_t, stringdata0) + ofs \
        - idx * sizeof(QByteArrayData)) \
    )
static const qt_meta_stringdata_MainWindow_t qt_meta_stringdata_MainWindow = {
    {
QT_MOC_LITERAL(0, 0, 10), // "MainWindow"
QT_MOC_LITERAL(1, 11, 28), // "on_portsReloadButton_clicked"
QT_MOC_LITERAL(2, 40, 0), // ""
QT_MOC_LITERAL(3, 41, 32), // "on_portSelect_currentTextChanged"
QT_MOC_LITERAL(4, 74, 4), // "arg1"
QT_MOC_LITERAL(5, 79, 32), // "on_baudSelect_currentTextChanged"
QT_MOC_LITERAL(6, 112, 11), // "onReadyRead"
QT_MOC_LITERAL(7, 124, 17), // "updateStatusLabel"
QT_MOC_LITERAL(8, 142, 13), // "updateButtons"
QT_MOC_LITERAL(9, 156, 26), // "on_programm1Button_clicked"
QT_MOC_LITERAL(10, 183, 26), // "on_programm2Button_clicked"
QT_MOC_LITERAL(11, 210, 26), // "on_programm3Button_clicked"
QT_MOC_LITERAL(12, 237, 26), // "on_programm4Button_clicked"
QT_MOC_LITERAL(13, 264, 26), // "on_programm5Button_clicked"
QT_MOC_LITERAL(14, 291, 26), // "on_programm6Button_clicked"
QT_MOC_LITERAL(15, 318, 26), // "on_programm7Button_clicked"
QT_MOC_LITERAL(16, 345, 26) // "on_programm8Button_clicked"

    },
    "MainWindow\0on_portsReloadButton_clicked\0"
    "\0on_portSelect_currentTextChanged\0"
    "arg1\0on_baudSelect_currentTextChanged\0"
    "onReadyRead\0updateStatusLabel\0"
    "updateButtons\0on_programm1Button_clicked\0"
    "on_programm2Button_clicked\0"
    "on_programm3Button_clicked\0"
    "on_programm4Button_clicked\0"
    "on_programm5Button_clicked\0"
    "on_programm6Button_clicked\0"
    "on_programm7Button_clicked\0"
    "on_programm8Button_clicked"
};
#undef QT_MOC_LITERAL

static const uint qt_meta_data_MainWindow[] = {

 // content:
       8,       // revision
       0,       // classname
       0,    0, // classinfo
      14,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       0,       // signalCount

 // slots: name, argc, parameters, tag, flags
       1,    0,   84,    2, 0x08 /* Private */,
       3,    1,   85,    2, 0x08 /* Private */,
       5,    1,   88,    2, 0x08 /* Private */,
       6,    0,   91,    2, 0x08 /* Private */,
       7,    0,   92,    2, 0x08 /* Private */,
       8,    0,   93,    2, 0x08 /* Private */,
       9,    0,   94,    2, 0x08 /* Private */,
      10,    0,   95,    2, 0x08 /* Private */,
      11,    0,   96,    2, 0x08 /* Private */,
      12,    0,   97,    2, 0x08 /* Private */,
      13,    0,   98,    2, 0x08 /* Private */,
      14,    0,   99,    2, 0x08 /* Private */,
      15,    0,  100,    2, 0x08 /* Private */,
      16,    0,  101,    2, 0x08 /* Private */,

 // slots: parameters
    QMetaType::Void,
    QMetaType::Void, QMetaType::QString,    4,
    QMetaType::Void, QMetaType::QString,    4,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,

       0        // eod
};

void MainWindow::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        auto *_t = static_cast<MainWindow *>(_o);
        Q_UNUSED(_t)
        switch (_id) {
        case 0: _t->on_portsReloadButton_clicked(); break;
        case 1: _t->on_portSelect_currentTextChanged((*reinterpret_cast< const QString(*)>(_a[1]))); break;
        case 2: _t->on_baudSelect_currentTextChanged((*reinterpret_cast< const QString(*)>(_a[1]))); break;
        case 3: _t->onReadyRead(); break;
        case 4: _t->updateStatusLabel(); break;
        case 5: _t->updateButtons(); break;
        case 6: _t->on_programm1Button_clicked(); break;
        case 7: _t->on_programm2Button_clicked(); break;
        case 8: _t->on_programm3Button_clicked(); break;
        case 9: _t->on_programm4Button_clicked(); break;
        case 10: _t->on_programm5Button_clicked(); break;
        case 11: _t->on_programm6Button_clicked(); break;
        case 12: _t->on_programm7Button_clicked(); break;
        case 13: _t->on_programm8Button_clicked(); break;
        default: ;
        }
    }
}

QT_INIT_METAOBJECT const QMetaObject MainWindow::staticMetaObject = { {
    &QMainWindow::staticMetaObject,
    qt_meta_stringdata_MainWindow.data,
    qt_meta_data_MainWindow,
    qt_static_metacall,
    nullptr,
    nullptr
} };


const QMetaObject *MainWindow::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *MainWindow::qt_metacast(const char *_clname)
{
    if (!_clname) return nullptr;
    if (!strcmp(_clname, qt_meta_stringdata_MainWindow.stringdata0))
        return static_cast<void*>(this);
    return QMainWindow::qt_metacast(_clname);
}

int MainWindow::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QMainWindow::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        if (_id < 14)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 14;
    } else if (_c == QMetaObject::RegisterMethodArgumentMetaType) {
        if (_id < 14)
            *reinterpret_cast<int*>(_a[0]) = -1;
        _id -= 14;
    }
    return _id;
}
QT_WARNING_POP
QT_END_MOC_NAMESPACE
