/****************************************************************************
** Meta object code from reading C++ file 'dialog_graphics.h'
**
** Created by: The Qt Meta Object Compiler version 67 (Qt 5.12.3)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "../../Ground_Station_source/dialog_graphics.h"
#include <QtCore/qbytearray.h>
#include <QtCore/qmetatype.h>
#include <QtCore/QVector>
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'dialog_graphics.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 67
#error "This file was generated using the moc from 5.12.3. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
QT_WARNING_PUSH
QT_WARNING_DISABLE_DEPRECATED
struct qt_meta_stringdata_Dialog_Graphics_t {
    QByteArrayData data[8];
    char stringdata0[136];
};
#define QT_MOC_LITERAL(idx, ofs, len) \
    Q_STATIC_BYTE_ARRAY_DATA_HEADER_INITIALIZER_WITH_OFFSET(len, \
    qptrdiff(offsetof(qt_meta_stringdata_Dialog_Graphics_t, stringdata0) + ofs \
        - idx * sizeof(QByteArrayData)) \
    )
static const qt_meta_stringdata_Dialog_Graphics_t qt_meta_stringdata_Dialog_Graphics = {
    {
QT_MOC_LITERAL(0, 0, 15), // "Dialog_Graphics"
QT_MOC_LITERAL(1, 16, 12), // "setup_dialog"
QT_MOC_LITERAL(2, 29, 0), // ""
QT_MOC_LITERAL(3, 30, 9), // "read_data"
QT_MOC_LITERAL(4, 40, 26), // "QVector<QVector<QPointF> >"
QT_MOC_LITERAL(5, 67, 13), // "update_charts"
QT_MOC_LITERAL(6, 81, 17), // "commands_tracking"
QT_MOC_LITERAL(7, 99, 36) // "on_pushButton_start_graphics_..."

    },
    "Dialog_Graphics\0setup_dialog\0\0read_data\0"
    "QVector<QVector<QPointF> >\0update_charts\0"
    "commands_tracking\0"
    "on_pushButton_start_graphics_clicked"
};
#undef QT_MOC_LITERAL

static const uint qt_meta_data_Dialog_Graphics[] = {

 // content:
       8,       // revision
       0,       // classname
       0,    0, // classinfo
       5,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       0,       // signalCount

 // slots: name, argc, parameters, tag, flags
       1,    0,   39,    2, 0x0a /* Public */,
       3,    2,   40,    2, 0x0a /* Public */,
       5,    0,   45,    2, 0x0a /* Public */,
       6,    0,   46,    2, 0x0a /* Public */,
       7,    0,   47,    2, 0x08 /* Private */,

 // slots: parameters
    QMetaType::Void,
    QMetaType::Void, 0x80000000 | 4, 0x80000000 | 4,    2,    2,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,

       0        // eod
};

void Dialog_Graphics::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        auto *_t = static_cast<Dialog_Graphics *>(_o);
        Q_UNUSED(_t)
        switch (_id) {
        case 0: _t->setup_dialog(); break;
        case 1: _t->read_data((*reinterpret_cast< QVector<QVector<QPointF> >(*)>(_a[1])),(*reinterpret_cast< QVector<QVector<QPointF> >(*)>(_a[2]))); break;
        case 2: _t->update_charts(); break;
        case 3: _t->commands_tracking(); break;
        case 4: _t->on_pushButton_start_graphics_clicked(); break;
        default: ;
        }
    } else if (_c == QMetaObject::RegisterMethodArgumentMetaType) {
        switch (_id) {
        default: *reinterpret_cast<int*>(_a[0]) = -1; break;
        case 1:
            switch (*reinterpret_cast<int*>(_a[1])) {
            default: *reinterpret_cast<int*>(_a[0]) = -1; break;
            case 1:
            case 0:
                *reinterpret_cast<int*>(_a[0]) = qRegisterMetaType< QVector<QVector<QPointF> > >(); break;
            }
            break;
        }
    }
}

QT_INIT_METAOBJECT const QMetaObject Dialog_Graphics::staticMetaObject = { {
    &QDialog::staticMetaObject,
    qt_meta_stringdata_Dialog_Graphics.data,
    qt_meta_data_Dialog_Graphics,
    qt_static_metacall,
    nullptr,
    nullptr
} };


const QMetaObject *Dialog_Graphics::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *Dialog_Graphics::qt_metacast(const char *_clname)
{
    if (!_clname) return nullptr;
    if (!strcmp(_clname, qt_meta_stringdata_Dialog_Graphics.stringdata0))
        return static_cast<void*>(this);
    return QDialog::qt_metacast(_clname);
}

int Dialog_Graphics::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QDialog::qt_metacall(_c, _id, _a);
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
QT_WARNING_POP
QT_END_MOC_NAMESPACE
