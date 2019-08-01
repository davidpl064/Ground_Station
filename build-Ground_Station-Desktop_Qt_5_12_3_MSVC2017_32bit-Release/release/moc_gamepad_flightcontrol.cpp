/****************************************************************************
** Meta object code from reading C++ file 'gamepad_flightcontrol.h'
**
** Created by: The Qt Meta Object Compiler version 67 (Qt 5.12.3)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "../../Ground_Station_source/gamepad_flightcontrol.h"
#include <QtCore/qbytearray.h>
#include <QtCore/qmetatype.h>
#include <QtCore/QList>
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'gamepad_flightcontrol.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 67
#error "This file was generated using the moc from 5.12.3. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
QT_WARNING_PUSH
QT_WARNING_DISABLE_DEPRECATED
struct qt_meta_stringdata_Gamepad_FlightControl_t {
    QByteArrayData data[13];
    char stringdata0[190];
};
#define QT_MOC_LITERAL(idx, ofs, len) \
    Q_STATIC_BYTE_ARRAY_DATA_HEADER_INITIALIZER_WITH_OFFSET(len, \
    qptrdiff(offsetof(qt_meta_stringdata_Gamepad_FlightControl_t, stringdata0) + ofs \
        - idx * sizeof(QByteArrayData)) \
    )
static const qt_meta_stringdata_Gamepad_FlightControl_t qt_meta_stringdata_Gamepad_FlightControl = {
    {
QT_MOC_LITERAL(0, 0, 21), // "Gamepad_FlightControl"
QT_MOC_LITERAL(1, 22, 18), // "update_gamepadlist"
QT_MOC_LITERAL(2, 41, 0), // ""
QT_MOC_LITERAL(3, 42, 10), // "QList<int>"
QT_MOC_LITERAL(4, 53, 11), // "gamepadlist"
QT_MOC_LITERAL(5, 65, 24), // "update_commandedcontrols"
QT_MOC_LITERAL(6, 90, 13), // "QList<double>"
QT_MOC_LITERAL(7, 104, 18), // "commanded_controls"
QT_MOC_LITERAL(8, 123, 13), // "setup_gamepad"
QT_MOC_LITERAL(9, 137, 9), // "QGamepad*"
QT_MOC_LITERAL(10, 147, 23), // "dialog_selected_gamepad"
QT_MOC_LITERAL(11, 171, 11), // "run_gamepad"
QT_MOC_LITERAL(12, 183, 6) // "update"

    },
    "Gamepad_FlightControl\0update_gamepadlist\0"
    "\0QList<int>\0gamepadlist\0"
    "update_commandedcontrols\0QList<double>\0"
    "commanded_controls\0setup_gamepad\0"
    "QGamepad*\0dialog_selected_gamepad\0"
    "run_gamepad\0update"
};
#undef QT_MOC_LITERAL

static const uint qt_meta_data_Gamepad_FlightControl[] = {

 // content:
       8,       // revision
       0,       // classname
       0,    0, // classinfo
       5,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       2,       // signalCount

 // signals: name, argc, parameters, tag, flags
       1,    1,   39,    2, 0x06 /* Public */,
       5,    1,   42,    2, 0x06 /* Public */,

 // slots: name, argc, parameters, tag, flags
       8,    1,   45,    2, 0x0a /* Public */,
      11,    0,   48,    2, 0x0a /* Public */,
      12,    0,   49,    2, 0x0a /* Public */,

 // signals: parameters
    QMetaType::Void, 0x80000000 | 3,    4,
    QMetaType::Void, 0x80000000 | 6,    7,

 // slots: parameters
    QMetaType::Void, 0x80000000 | 9,   10,
    QMetaType::Void,
    QMetaType::Void,

       0        // eod
};

void Gamepad_FlightControl::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        auto *_t = static_cast<Gamepad_FlightControl *>(_o);
        Q_UNUSED(_t)
        switch (_id) {
        case 0: _t->update_gamepadlist((*reinterpret_cast< QList<int>(*)>(_a[1]))); break;
        case 1: _t->update_commandedcontrols((*reinterpret_cast< QList<double>(*)>(_a[1]))); break;
        case 2: _t->setup_gamepad((*reinterpret_cast< QGamepad*(*)>(_a[1]))); break;
        case 3: _t->run_gamepad(); break;
        case 4: _t->update(); break;
        default: ;
        }
    } else if (_c == QMetaObject::RegisterMethodArgumentMetaType) {
        switch (_id) {
        default: *reinterpret_cast<int*>(_a[0]) = -1; break;
        case 0:
            switch (*reinterpret_cast<int*>(_a[1])) {
            default: *reinterpret_cast<int*>(_a[0]) = -1; break;
            case 0:
                *reinterpret_cast<int*>(_a[0]) = qRegisterMetaType< QList<int> >(); break;
            }
            break;
        case 1:
            switch (*reinterpret_cast<int*>(_a[1])) {
            default: *reinterpret_cast<int*>(_a[0]) = -1; break;
            case 0:
                *reinterpret_cast<int*>(_a[0]) = qRegisterMetaType< QList<double> >(); break;
            }
            break;
        case 2:
            switch (*reinterpret_cast<int*>(_a[1])) {
            default: *reinterpret_cast<int*>(_a[0]) = -1; break;
            case 0:
                *reinterpret_cast<int*>(_a[0]) = qRegisterMetaType< QGamepad* >(); break;
            }
            break;
        }
    } else if (_c == QMetaObject::IndexOfMethod) {
        int *result = reinterpret_cast<int *>(_a[0]);
        {
            using _t = void (Gamepad_FlightControl::*)(QList<int> );
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&Gamepad_FlightControl::update_gamepadlist)) {
                *result = 0;
                return;
            }
        }
        {
            using _t = void (Gamepad_FlightControl::*)(QList<double> );
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&Gamepad_FlightControl::update_commandedcontrols)) {
                *result = 1;
                return;
            }
        }
    }
}

QT_INIT_METAOBJECT const QMetaObject Gamepad_FlightControl::staticMetaObject = { {
    &QObject::staticMetaObject,
    qt_meta_stringdata_Gamepad_FlightControl.data,
    qt_meta_data_Gamepad_FlightControl,
    qt_static_metacall,
    nullptr,
    nullptr
} };


const QMetaObject *Gamepad_FlightControl::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *Gamepad_FlightControl::qt_metacast(const char *_clname)
{
    if (!_clname) return nullptr;
    if (!strcmp(_clname, qt_meta_stringdata_Gamepad_FlightControl.stringdata0))
        return static_cast<void*>(this);
    return QObject::qt_metacast(_clname);
}

int Gamepad_FlightControl::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QObject::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        if (_id < 5)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 5;
    } else if (_c == QMetaObject::RegisterMethodArgumentMetaType) {
        if (_id < 5)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 5;
    }
    return _id;
}

// SIGNAL 0
void Gamepad_FlightControl::update_gamepadlist(QList<int> _t1)
{
    void *_a[] = { nullptr, const_cast<void*>(reinterpret_cast<const void*>(&_t1)) };
    QMetaObject::activate(this, &staticMetaObject, 0, _a);
}

// SIGNAL 1
void Gamepad_FlightControl::update_commandedcontrols(QList<double> _t1)
{
    void *_a[] = { nullptr, const_cast<void*>(reinterpret_cast<const void*>(&_t1)) };
    QMetaObject::activate(this, &staticMetaObject, 1, _a);
}
QT_WARNING_POP
QT_END_MOC_NAMESPACE
