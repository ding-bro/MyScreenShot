/****************************************************************************
** Meta object code from reading C++ file 'CQThreadCilck.h'
**
** Created by: The Qt Meta Object Compiler version 67 (Qt 5.9.1)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "../../../CQThreadCilck.h"
#include <QtCore/qbytearray.h>
#include <QtCore/qmetatype.h>
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'CQThreadCilck.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 67
#error "This file was generated using the moc from 5.9.1. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
QT_WARNING_PUSH
QT_WARNING_DISABLE_DEPRECATED
struct qt_meta_stringdata_CQThreadCilck_t {
    QByteArrayData data[12];
    char stringdata0[127];
};
#define QT_MOC_LITERAL(idx, ofs, len) \
    Q_STATIC_BYTE_ARRAY_DATA_HEADER_INITIALIZER_WITH_OFFSET(len, \
    qptrdiff(offsetof(qt_meta_stringdata_CQThreadCilck_t, stringdata0) + ofs \
        - idx * sizeof(QByteArrayData)) \
    )
static const qt_meta_stringdata_CQThreadCilck_t qt_meta_stringdata_CQThreadCilck = {
    {
QT_MOC_LITERAL(0, 0, 13), // "CQThreadCilck"
QT_MOC_LITERAL(1, 14, 14), // "signThreadQuit"
QT_MOC_LITERAL(2, 29, 0), // ""
QT_MOC_LITERAL(3, 30, 14), // "signDialogSave"
QT_MOC_LITERAL(4, 45, 8), // "CCanvas*"
QT_MOC_LITERAL(5, 54, 7), // "pCanvas"
QT_MOC_LITERAL(6, 62, 11), // "COptionBox*"
QT_MOC_LITERAL(7, 74, 7), // "pOption"
QT_MOC_LITERAL(8, 82, 8), // "QPixmap&"
QT_MOC_LITERAL(9, 91, 7), // "qPixmap"
QT_MOC_LITERAL(10, 99, 12), // "slotDownLoad"
QT_MOC_LITERAL(11, 112, 14) // "slotThreadQuit"

    },
    "CQThreadCilck\0signThreadQuit\0\0"
    "signDialogSave\0CCanvas*\0pCanvas\0"
    "COptionBox*\0pOption\0QPixmap&\0qPixmap\0"
    "slotDownLoad\0slotThreadQuit"
};
#undef QT_MOC_LITERAL

static const uint qt_meta_data_CQThreadCilck[] = {

 // content:
       7,       // revision
       0,       // classname
       0,    0, // classinfo
       4,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       2,       // signalCount

 // signals: name, argc, parameters, tag, flags
       1,    0,   34,    2, 0x06 /* Public */,
       3,    3,   35,    2, 0x06 /* Public */,

 // slots: name, argc, parameters, tag, flags
      10,    3,   42,    2, 0x0a /* Public */,
      11,    0,   49,    2, 0x0a /* Public */,

 // signals: parameters
    QMetaType::Void,
    QMetaType::Void, 0x80000000 | 4, 0x80000000 | 6, 0x80000000 | 8,    5,    7,    9,

 // slots: parameters
    QMetaType::Void, 0x80000000 | 4, 0x80000000 | 6, 0x80000000 | 8,    5,    7,    9,
    QMetaType::Void,

       0        // eod
};

void CQThreadCilck::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        CQThreadCilck *_t = static_cast<CQThreadCilck *>(_o);
        Q_UNUSED(_t)
        switch (_id) {
        case 0: _t->signThreadQuit(); break;
        case 1: _t->signDialogSave((*reinterpret_cast< CCanvas*(*)>(_a[1])),(*reinterpret_cast< COptionBox*(*)>(_a[2])),(*reinterpret_cast< QPixmap(*)>(_a[3]))); break;
        case 2: _t->slotDownLoad((*reinterpret_cast< CCanvas*(*)>(_a[1])),(*reinterpret_cast< COptionBox*(*)>(_a[2])),(*reinterpret_cast< QPixmap(*)>(_a[3]))); break;
        case 3: _t->slotThreadQuit(); break;
        default: ;
        }
    } else if (_c == QMetaObject::RegisterMethodArgumentMetaType) {
        switch (_id) {
        default: *reinterpret_cast<int*>(_a[0]) = -1; break;
        case 1:
            switch (*reinterpret_cast<int*>(_a[1])) {
            default: *reinterpret_cast<int*>(_a[0]) = -1; break;
            case 0:
                *reinterpret_cast<int*>(_a[0]) = qRegisterMetaType< CCanvas* >(); break;
            case 1:
                *reinterpret_cast<int*>(_a[0]) = qRegisterMetaType< COptionBox* >(); break;
            }
            break;
        case 2:
            switch (*reinterpret_cast<int*>(_a[1])) {
            default: *reinterpret_cast<int*>(_a[0]) = -1; break;
            case 0:
                *reinterpret_cast<int*>(_a[0]) = qRegisterMetaType< CCanvas* >(); break;
            case 1:
                *reinterpret_cast<int*>(_a[0]) = qRegisterMetaType< COptionBox* >(); break;
            }
            break;
        }
    } else if (_c == QMetaObject::IndexOfMethod) {
        int *result = reinterpret_cast<int *>(_a[0]);
        void **func = reinterpret_cast<void **>(_a[1]);
        {
            typedef void (CQThreadCilck::*_t)();
            if (*reinterpret_cast<_t *>(func) == static_cast<_t>(&CQThreadCilck::signThreadQuit)) {
                *result = 0;
                return;
            }
        }
        {
            typedef void (CQThreadCilck::*_t)(CCanvas * , COptionBox * , QPixmap & );
            if (*reinterpret_cast<_t *>(func) == static_cast<_t>(&CQThreadCilck::signDialogSave)) {
                *result = 1;
                return;
            }
        }
    }
}

const QMetaObject CQThreadCilck::staticMetaObject = {
    { &QObject::staticMetaObject, qt_meta_stringdata_CQThreadCilck.data,
      qt_meta_data_CQThreadCilck,  qt_static_metacall, nullptr, nullptr}
};


const QMetaObject *CQThreadCilck::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *CQThreadCilck::qt_metacast(const char *_clname)
{
    if (!_clname) return nullptr;
    if (!strcmp(_clname, qt_meta_stringdata_CQThreadCilck.stringdata0))
        return static_cast<void*>(const_cast< CQThreadCilck*>(this));
    return QObject::qt_metacast(_clname);
}

int CQThreadCilck::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QObject::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        if (_id < 4)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 4;
    } else if (_c == QMetaObject::RegisterMethodArgumentMetaType) {
        if (_id < 4)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 4;
    }
    return _id;
}

// SIGNAL 0
void CQThreadCilck::signThreadQuit()
{
    QMetaObject::activate(this, &staticMetaObject, 0, nullptr);
}

// SIGNAL 1
void CQThreadCilck::signDialogSave(CCanvas * _t1, COptionBox * _t2, QPixmap & _t3)
{
    void *_a[] = { nullptr, const_cast<void*>(reinterpret_cast<const void*>(&_t1)), const_cast<void*>(reinterpret_cast<const void*>(&_t2)), const_cast<void*>(reinterpret_cast<const void*>(&_t3)) };
    QMetaObject::activate(this, &staticMetaObject, 1, _a);
}
QT_WARNING_POP
QT_END_MOC_NAMESPACE
