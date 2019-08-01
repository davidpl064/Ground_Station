/****************************************************************************
** Meta object code from reading C++ file 'mavlink_interface.h'
**
** Created by: The Qt Meta Object Compiler version 67 (Qt 5.12.3)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "../../Ground_Station_source/mavlink_interface.h"
#include <QtCore/qbytearray.h>
#include <QtCore/qmetatype.h>
#include <QtCore/QList>
#include <QtCore/QVector>
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'mavlink_interface.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 67
#error "This file was generated using the moc from 5.12.3. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
QT_WARNING_PUSH
QT_WARNING_DISABLE_DEPRECATED
struct qt_meta_stringdata_MAVlink_interface_t {
    QByteArrayData data[22];
    char stringdata0[393];
};
#define QT_MOC_LITERAL(idx, ofs, len) \
    Q_STATIC_BYTE_ARRAY_DATA_HEADER_INITIALIZER_WITH_OFFSET(len, \
    qptrdiff(offsetof(qt_meta_stringdata_MAVlink_interface_t, stringdata0) + ofs \
        - idx * sizeof(QByteArrayData)) \
    )
static const qt_meta_stringdata_MAVlink_interface_t qt_meta_stringdata_MAVlink_interface = {
    {
QT_MOC_LITERAL(0, 0, 17), // "MAVlink_interface"
QT_MOC_LITERAL(1, 18, 16), // "setup_serialport"
QT_MOC_LITERAL(2, 35, 0), // ""
QT_MOC_LITERAL(3, 36, 23), // "start_timer_serial_comm"
QT_MOC_LITERAL(4, 60, 26), // "update_current_system_data"
QT_MOC_LITERAL(5, 87, 16), // "Mavlink_Messages"
QT_MOC_LITERAL(6, 104, 16), // "current_messages"
QT_MOC_LITERAL(7, 121, 23), // "send_data_visualization"
QT_MOC_LITERAL(8, 145, 26), // "QVector<QVector<QPointF> >"
QT_MOC_LITERAL(9, 172, 5), // "setup"
QT_MOC_LITERAL(10, 178, 8), // "portName"
QT_MOC_LITERAL(11, 187, 8), // "baudrate"
QT_MOC_LITERAL(12, 196, 22), // "switch_serialcomm_mode"
QT_MOC_LITERAL(13, 219, 12), // "read_message"
QT_MOC_LITERAL(14, 232, 12), // "send_message"
QT_MOC_LITERAL(15, 245, 23), // "update_gamepad_commands"
QT_MOC_LITERAL(16, 269, 13), // "QList<double>"
QT_MOC_LITERAL(17, 283, 25), // "gamepad_commandedcontrols"
QT_MOC_LITERAL(18, 309, 25), // "update_data_visualization"
QT_MOC_LITERAL(19, 335, 23), // "update_connected_system"
QT_MOC_LITERAL(20, 359, 16), // "QVector<uint8_t>"
QT_MOC_LITERAL(21, 376, 16) // "close_serialcomm"

    },
    "MAVlink_interface\0setup_serialport\0\0"
    "start_timer_serial_comm\0"
    "update_current_system_data\0Mavlink_Messages\0"
    "current_messages\0send_data_visualization\0"
    "QVector<QVector<QPointF> >\0setup\0"
    "portName\0baudrate\0switch_serialcomm_mode\0"
    "read_message\0send_message\0"
    "update_gamepad_commands\0QList<double>\0"
    "gamepad_commandedcontrols\0"
    "update_data_visualization\0"
    "update_connected_system\0QVector<uint8_t>\0"
    "close_serialcomm"
};
#undef QT_MOC_LITERAL

static const uint qt_meta_data_MAVlink_interface[] = {

 // content:
       8,       // revision
       0,       // classname
       0,    0, // classinfo
      12,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       4,       // signalCount

 // signals: name, argc, parameters, tag, flags
       1,    2,   74,    2, 0x06 /* Public */,
       3,    0,   79,    2, 0x06 /* Public */,
       4,    1,   80,    2, 0x06 /* Public */,
       7,    2,   83,    2, 0x06 /* Public */,

 // slots: name, argc, parameters, tag, flags
       9,    2,   88,    2, 0x0a /* Public */,
      12,    0,   93,    2, 0x0a /* Public */,
      13,    0,   94,    2, 0x0a /* Public */,
      14,    0,   95,    2, 0x0a /* Public */,
      15,    1,   96,    2, 0x0a /* Public */,
      18,    0,   99,    2, 0x0a /* Public */,
      19,    1,  100,    2, 0x0a /* Public */,
      21,    0,  103,    2, 0x0a /* Public */,

 // signals: parameters
    QMetaType::Void, QMetaType::QString, QMetaType::Int,    2,    2,
    QMetaType::Void,
    QMetaType::Void, 0x80000000 | 5,    6,
    QMetaType::Void, 0x80000000 | 8, 0x80000000 | 8,    2,    2,

 // slots: parameters
    QMetaType::Void, QMetaType::QString, QMetaType::Int,   10,   11,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void, 0x80000000 | 16,   17,
    QMetaType::Void,
    QMetaType::Void, 0x80000000 | 20,    2,
    QMetaType::Void,

       0        // eod
};

void MAVlink_interface::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        auto *_t = static_cast<MAVlink_interface *>(_o);
        Q_UNUSED(_t)
        switch (_id) {
        case 0: _t->setup_serialport((*reinterpret_cast< const QString(*)>(_a[1])),(*reinterpret_cast< int(*)>(_a[2]))); break;
        case 1: _t->start_timer_serial_comm(); break;
        case 2: _t->update_current_system_data((*reinterpret_cast< Mavlink_Messages(*)>(_a[1]))); break;
        case 3: _t->send_data_visualization((*reinterpret_cast< QVector<QVector<QPointF> >(*)>(_a[1])),(*reinterpret_cast< QVector<QVector<QPointF> >(*)>(_a[2]))); break;
        case 4: _t->setup((*reinterpret_cast< const QString(*)>(_a[1])),(*reinterpret_cast< int(*)>(_a[2]))); break;
        case 5: _t->switch_serialcomm_mode(); break;
        case 6: _t->read_message(); break;
        case 7: _t->send_message(); break;
        case 8: _t->update_gamepad_commands((*reinterpret_cast< QList<double>(*)>(_a[1]))); break;
        case 9: _t->update_data_visualization(); break;
        case 10: _t->update_connected_system((*reinterpret_cast< QVector<uint8_t>(*)>(_a[1]))); break;
        case 11: _t->close_serialcomm(); break;
        default: ;
        }
    } else if (_c == QMetaObject::RegisterMethodArgumentMetaType) {
        switch (_id) {
        default: *reinterpret_cast<int*>(_a[0]) = -1; break;
        case 2:
            switch (*reinterpret_cast<int*>(_a[1])) {
            default: *reinterpret_cast<int*>(_a[0]) = -1; break;
            case 0:
                *reinterpret_cast<int*>(_a[0]) = qRegisterMetaType< Mavlink_Messages >(); break;
            }
            break;
        case 3:
            switch (*reinterpret_cast<int*>(_a[1])) {
            default: *reinterpret_cast<int*>(_a[0]) = -1; break;
            case 1:
            case 0:
                *reinterpret_cast<int*>(_a[0]) = qRegisterMetaType< QVector<QVector<QPointF> > >(); break;
            }
            break;
        case 8:
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
            using _t = void (MAVlink_interface::*)(const QString , int );
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&MAVlink_interface::setup_serialport)) {
                *result = 0;
                return;
            }
        }
        {
            using _t = void (MAVlink_interface::*)();
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&MAVlink_interface::start_timer_serial_comm)) {
                *result = 1;
                return;
            }
        }
        {
            using _t = void (MAVlink_interface::*)(Mavlink_Messages );
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&MAVlink_interface::update_current_system_data)) {
                *result = 2;
                return;
            }
        }
        {
            using _t = void (MAVlink_interface::*)(QVector<QVector<QPointF>> , QVector<QVector<QPointF>> );
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&MAVlink_interface::send_data_visualization)) {
                *result = 3;
                return;
            }
        }
    }
}

QT_INIT_METAOBJECT const QMetaObject MAVlink_interface::staticMetaObject = { {
    &QObject::staticMetaObject,
    qt_meta_stringdata_MAVlink_interface.data,
    qt_meta_data_MAVlink_interface,
    qt_static_metacall,
    nullptr,
    nullptr
} };


const QMetaObject *MAVlink_interface::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *MAVlink_interface::qt_metacast(const char *_clname)
{
    if (!_clname) return nullptr;
    if (!strcmp(_clname, qt_meta_stringdata_MAVlink_interface.stringdata0))
        return static_cast<void*>(this);
    return QObject::qt_metacast(_clname);
}

int MAVlink_interface::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QObject::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        if (_id < 12)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 12;
    } else if (_c == QMetaObject::RegisterMethodArgumentMetaType) {
        if (_id < 12)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 12;
    }
    return _id;
}

// SIGNAL 0
void MAVlink_interface::setup_serialport(const QString _t1, int _t2)
{
    void *_a[] = { nullptr, const_cast<void*>(reinterpret_cast<const void*>(&_t1)), const_cast<void*>(reinterpret_cast<const void*>(&_t2)) };
    QMetaObject::activate(this, &staticMetaObject, 0, _a);
}

// SIGNAL 1
void MAVlink_interface::start_timer_serial_comm()
{
    QMetaObject::activate(this, &staticMetaObject, 1, nullptr);
}

// SIGNAL 2
void MAVlink_interface::update_current_system_data(Mavlink_Messages _t1)
{
    void *_a[] = { nullptr, const_cast<void*>(reinterpret_cast<const void*>(&_t1)) };
    QMetaObject::activate(this, &staticMetaObject, 2, _a);
}

// SIGNAL 3
void MAVlink_interface::send_data_visualization(QVector<QVector<QPointF>> _t1, QVector<QVector<QPointF>> _t2)
{
    void *_a[] = { nullptr, const_cast<void*>(reinterpret_cast<const void*>(&_t1)), const_cast<void*>(reinterpret_cast<const void*>(&_t2)) };
    QMetaObject::activate(this, &staticMetaObject, 3, _a);
}
QT_WARNING_POP
QT_END_MOC_NAMESPACE
