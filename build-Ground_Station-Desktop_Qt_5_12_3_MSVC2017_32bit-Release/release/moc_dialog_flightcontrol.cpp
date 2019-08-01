/****************************************************************************
** Meta object code from reading C++ file 'dialog_flightcontrol.h'
**
** Created by: The Qt Meta Object Compiler version 67 (Qt 5.12.3)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "../../Ground_Station_source/dialog_flightcontrol.h"
#include <QtCore/qbytearray.h>
#include <QtCore/qmetatype.h>
#include <QtCore/QList>
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'dialog_flightcontrol.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 67
#error "This file was generated using the moc from 5.12.3. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
QT_WARNING_PUSH
QT_WARNING_DISABLE_DEPRECATED
struct qt_meta_stringdata_Dialog_FlightControl_t {
    QByteArrayData data[14];
    char stringdata0[287];
};
#define QT_MOC_LITERAL(idx, ofs, len) \
    Q_STATIC_BYTE_ARRAY_DATA_HEADER_INITIALIZER_WITH_OFFSET(len, \
    qptrdiff(offsetof(qt_meta_stringdata_Dialog_FlightControl_t, stringdata0) + ofs \
        - idx * sizeof(QByteArrayData)) \
    )
static const qt_meta_stringdata_Dialog_FlightControl_t qt_meta_stringdata_Dialog_FlightControl = {
    {
QT_MOC_LITERAL(0, 0, 20), // "Dialog_FlightControl"
QT_MOC_LITERAL(1, 21, 11), // "show_dialog"
QT_MOC_LITERAL(2, 33, 0), // ""
QT_MOC_LITERAL(3, 34, 13), // "setup_gamepad"
QT_MOC_LITERAL(4, 48, 9), // "QGamepad*"
QT_MOC_LITERAL(5, 58, 33), // "send_mainwindow_commandedcont..."
QT_MOC_LITERAL(6, 92, 13), // "QList<double>"
QT_MOC_LITERAL(7, 106, 23), // "last_commanded_controls"
QT_MOC_LITERAL(8, 130, 20), // "setup_gamepad_dialog"
QT_MOC_LITERAL(9, 151, 36), // "on_pushButton_updategamepads_..."
QT_MOC_LITERAL(10, 188, 19), // "update_gamepadslist"
QT_MOC_LITERAL(11, 208, 22), // "read_commandedcontrols"
QT_MOC_LITERAL(12, 231, 18), // "commanded_controls"
QT_MOC_LITERAL(13, 250, 36) // "on_pushButton_connectgamepad_..."

    },
    "Dialog_FlightControl\0show_dialog\0\0"
    "setup_gamepad\0QGamepad*\0"
    "send_mainwindow_commandedcontrols\0"
    "QList<double>\0last_commanded_controls\0"
    "setup_gamepad_dialog\0"
    "on_pushButton_updategamepads_clicked\0"
    "update_gamepadslist\0read_commandedcontrols\0"
    "commanded_controls\0"
    "on_pushButton_connectgamepad_clicked"
};
#undef QT_MOC_LITERAL

static const uint qt_meta_data_Dialog_FlightControl[] = {

 // content:
       8,       // revision
       0,       // classname
       0,    0, // classinfo
       8,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       3,       // signalCount

 // signals: name, argc, parameters, tag, flags
       1,    0,   54,    2, 0x06 /* Public */,
       3,    1,   55,    2, 0x06 /* Public */,
       5,    1,   58,    2, 0x06 /* Public */,

 // slots: name, argc, parameters, tag, flags
       8,    0,   61,    2, 0x08 /* Private */,
       9,    0,   62,    2, 0x08 /* Private */,
      10,    0,   63,    2, 0x08 /* Private */,
      11,    1,   64,    2, 0x08 /* Private */,
      13,    0,   67,    2, 0x08 /* Private */,

 // signals: parameters
    QMetaType::Void,
    QMetaType::Void, 0x80000000 | 4,    2,
    QMetaType::Void, 0x80000000 | 6,    7,

 // slots: parameters
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void, 0x80000000 | 6,   12,
    QMetaType::Void,

       0        // eod
};

void Dialog_FlightControl::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        auto *_t = static_cast<Dialog_FlightControl *>(_o);
        Q_UNUSED(_t)
        switch (_id) {
        case 0: _t->show_dialog(); break;
        case 1: _t->setup_gamepad((*reinterpret_cast< QGamepad*(*)>(_a[1]))); break;
        case 2: _t->send_mainwindow_commandedcontrols((*reinterpret_cast< QList<double>(*)>(_a[1]))); break;
        case 3: _t->setup_gamepad_dialog(); break;
        case 4: _t->on_pushButton_updategamepads_clicked(); break;
        case 5: _t->update_gamepadslist(); break;
        case 6: _t->read_commandedcontrols((*reinterpret_cast< QList<double>(*)>(_a[1]))); break;
        case 7: _t->on_pushButton_connectgamepad_clicked(); break;
        default: ;
        }
    } else if (_c == QMetaObject::RegisterMethodArgumentMetaType) {
        switch (_id) {
        default: *reinterpret_cast<int*>(_a[0]) = -1; break;
        case 1:
            switch (*reinterpret_cast<int*>(_a[1])) {
            default: *reinterpret_cast<int*>(_a[0]) = -1; break;
            case 0:
                *reinterpret_cast<int*>(_a[0]) = qRegisterMetaType< QGamepad* >(); break;
            }
            break;
        case 2:
            switch (*reinterpret_cast<int*>(_a[1])) {
            default: *reinterpret_cast<int*>(_a[0]) = -1; break;
            case 0:
                *reinterpret_cast<int*>(_a[0]) = qRegisterMetaType< QList<double> >(); break;
            }
            break;
        case 6:
            switch (*reinterpret_cast<int*>(_a[1])) {
            default: *reinterpret_cast<int*>(_a[0]) = -1; break;
            case 0:
                *reinterpret_cast<int*>(_a[0]) = qRegisterMetaType< QList<double> >(); break;
            }
            break;
        }
    } else if (_c == QMetaObject::IndexOfMethod) {
        int *result = reinterpret_cast<int *>(_a[0]);
        {
            using _t = void (Dialog_FlightControl::*)();
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&Dialog_FlightControl::show_dialog)) {
                *result = 0;
                return;
            }
        }
        {
            using _t = void (Dialog_FlightControl::*)(QGamepad * );
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&Dialog_FlightControl::setup_gamepad)) {
                *result = 1;
                return;
            }
        }
        {
            using _t = void (Dialog_FlightControl::*)(QList<double> );
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&Dialog_FlightControl::send_mainwindow_commandedcontrols)) {
                *result = 2;
                return;
            }
        }
    }
}

QT_INIT_METAOBJECT const QMetaObject Dialog_FlightControl::staticMetaObject = { {
    &QDialog::staticMetaObject,
    qt_meta_stringdata_Dialog_FlightControl.data,
    qt_meta_data_Dialog_FlightControl,
    qt_static_metacall,
    nullptr,
    nullptr
} };


const QMetaObject *Dialog_FlightControl::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *Dialog_FlightControl::qt_metacast(const char *_clname)
{
    if (!_clname) return nullptr;
    if (!strcmp(_clname, qt_meta_stringdata_Dialog_FlightControl.stringdata0))
        return static_cast<void*>(this);
    return QDialog::qt_metacast(_clname);
}

int Dialog_FlightControl::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QDialog::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        if (_id < 8)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 8;
    } else if (_c == QMetaObject::RegisterMethodArgumentMetaType) {
        if (_id < 8)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 8;
    }
    return _id;
}

// SIGNAL 0
void Dialog_FlightControl::show_dialog()
{
    QMetaObject::activate(this, &staticMetaObject, 0, nullptr);
}

// SIGNAL 1
void Dialog_FlightControl::setup_gamepad(QGamepad * _t1)
{
    void *_a[] = { nullptr, const_cast<void*>(reinterpret_cast<const void*>(&_t1)) };
    QMetaObject::activate(this, &staticMetaObject, 1, _a);
}

// SIGNAL 2
void Dialog_FlightControl::send_mainwindow_commandedcontrols(QList<double> _t1)
{
    void *_a[] = { nullptr, const_cast<void*>(reinterpret_cast<const void*>(&_t1)) };
    QMetaObject::activate(this, &staticMetaObject, 2, _a);
}
QT_WARNING_POP
QT_END_MOC_NAMESPACE
