/****************************************************************************
** Meta object code from reading C++ file 'CScreenShot.h'
**
** Created by: The Qt Meta Object Compiler version 67 (Qt 5.9.1)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "../../../CScreenShot.h"
#include <QtCore/qbytearray.h>
#include <QtCore/qmetatype.h>
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'CScreenShot.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 67
#error "This file was generated using the moc from 5.9.1. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
QT_WARNING_PUSH
QT_WARNING_DISABLE_DEPRECATED
struct qt_meta_stringdata_CScreenShot_t {
    QByteArrayData data[16];
    char stringdata0[174];
};
#define QT_MOC_LITERAL(idx, ofs, len) \
    Q_STATIC_BYTE_ARRAY_DATA_HEADER_INITIALIZER_WITH_OFFSET(len, \
    qptrdiff(offsetof(qt_meta_stringdata_CScreenShot_t, stringdata0) + ofs \
        - idx * sizeof(QByteArrayData)) \
    )
static const qt_meta_stringdata_CScreenShot_t qt_meta_stringdata_CScreenShot = {
    {
QT_MOC_LITERAL(0, 0, 11), // "CScreenShot"
QT_MOC_LITERAL(1, 12, 14), // "signScreenShot"
QT_MOC_LITERAL(2, 27, 0), // ""
QT_MOC_LITERAL(3, 28, 14), // "signThreadQuit"
QT_MOC_LITERAL(4, 43, 17), // "slotMainwidowShow"
QT_MOC_LITERAL(5, 61, 19), // "slotStartScreenShot"
QT_MOC_LITERAL(6, 81, 12), // "slotDownLoad"
QT_MOC_LITERAL(7, 94, 8), // "CCanvas*"
QT_MOC_LITERAL(8, 103, 7), // "pCanvas"
QT_MOC_LITERAL(9, 111, 11), // "COptionBox*"
QT_MOC_LITERAL(10, 123, 7), // "pOption"
QT_MOC_LITERAL(11, 131, 8), // "QPixmap&"
QT_MOC_LITERAL(12, 140, 7), // "qPixmap"
QT_MOC_LITERAL(13, 148, 8), // "slotTest"
QT_MOC_LITERAL(14, 157, 8), // "CSetPen*"
QT_MOC_LITERAL(15, 166, 7) // "pSetpen"

    },
    "CScreenShot\0signScreenShot\0\0signThreadQuit\0"
    "slotMainwidowShow\0slotStartScreenShot\0"
    "slotDownLoad\0CCanvas*\0pCanvas\0COptionBox*\0"
    "pOption\0QPixmap&\0qPixmap\0slotTest\0"
    "CSetPen*\0pSetpen"
};
#undef QT_MOC_LITERAL

static const uint qt_meta_data_CScreenShot[] = {

 // content:
       7,       // revision
       0,       // classname
       0,    0, // classinfo
       6,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       2,       // signalCount

 // signals: name, argc, parameters, tag, flags
       1,    0,   44,    2, 0x06 /* Public */,
       3,    0,   45,    2, 0x06 /* Public */,

 // slots: name, argc, parameters, tag, flags
       4,    0,   46,    2, 0x0a /* Public */,
       5,    0,   47,    2, 0x0a /* Public */,
       6,    3,   48,    2, 0x0a /* Public */,
      13,    1,   55,    2, 0x0a /* Public */,

 // signals: parameters
    QMetaType::Void,
    QMetaType::Void,

 // slots: parameters
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void, 0x80000000 | 7, 0x80000000 | 9, 0x80000000 | 11,    8,   10,   12,
    QMetaType::Void, 0x80000000 | 14,   15,

       0        // eod
};

void CScreenShot::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        CScreenShot *_t = static_cast<CScreenShot *>(_o);
        Q_UNUSED(_t)
        switch (_id) {
        case 0: _t->signScreenShot(); break;
        case 1: _t->signThreadQuit(); break;
        case 2: _t->slotMainwidowShow(); break;
        case 3: _t->slotStartScreenShot(); break;
        case 4: _t->slotDownLoad((*reinterpret_cast< CCanvas*(*)>(_a[1])),(*reinterpret_cast< COptionBox*(*)>(_a[2])),(*reinterpret_cast< QPixmap(*)>(_a[3]))); break;
        case 5: _t->slotTest((*reinterpret_cast< CSetPen*(*)>(_a[1]))); break;
        default: ;
        }
    } else if (_c == QMetaObject::RegisterMethodArgumentMetaType) {
        switch (_id) {
        default: *reinterpret_cast<int*>(_a[0]) = -1; break;
        case 4:
            switch (*reinterpret_cast<int*>(_a[1])) {
            default: *reinterpret_cast<int*>(_a[0]) = -1; break;
            case 0:
                *reinterpret_cast<int*>(_a[0]) = qRegisterMetaType< CCanvas* >(); break;
            case 1:
                *reinterpret_cast<int*>(_a[0]) = qRegisterMetaType< COptionBox* >(); break;
            }
            break;
        case 5:
            switch (*reinterpret_cast<int*>(_a[1])) {
            default: *reinterpret_cast<int*>(_a[0]) = -1; break;
            case 0:
                *reinterpret_cast<int*>(_a[0]) = qRegisterMetaType< CSetPen* >(); break;
            }
            break;
        }
    } else if (_c == QMetaObject::IndexOfMethod) {
        int *result = reinterpret_cast<int *>(_a[0]);
        void **func = reinterpret_cast<void **>(_a[1]);
        {
            typedef void (CScreenShot::*_t)();
            if (*reinterpret_cast<_t *>(func) == static_cast<_t>(&CScreenShot::signScreenShot)) {
                *result = 0;
                return;
            }
        }
        {
            typedef void (CScreenShot::*_t)();
            if (*reinterpret_cast<_t *>(func) == static_cast<_t>(&CScreenShot::signThreadQuit)) {
                *result = 1;
                return;
            }
        }
    }
}

const QMetaObject CScreenShot::staticMetaObject = {
    { &QMainWindow::staticMetaObject, qt_meta_stringdata_CScreenShot.data,
      qt_meta_data_CScreenShot,  qt_static_metacall, nullptr, nullptr}
};


const QMetaObject *CScreenShot::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *CScreenShot::qt_metacast(const char *_clname)
{
    if (!_clname) return nullptr;
    if (!strcmp(_clname, qt_meta_stringdata_CScreenShot.stringdata0))
        return static_cast<void*>(const_cast< CScreenShot*>(this));
    return QMainWindow::qt_metacast(_clname);
}

int CScreenShot::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QMainWindow::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        if (_id < 6)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 6;
    } else if (_c == QMetaObject::RegisterMethodArgumentMetaType) {
        if (_id < 6)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 6;
    }
    return _id;
}

// SIGNAL 0
void CScreenShot::signScreenShot()
{
    QMetaObject::activate(this, &staticMetaObject, 0, nullptr);
}

// SIGNAL 1
void CScreenShot::signThreadQuit()
{
    QMetaObject::activate(this, &staticMetaObject, 1, nullptr);
}
QT_WARNING_POP
QT_END_MOC_NAMESPACE
