/****************************************************************************
** Meta object code from reading C++ file 'COptionBox.h'
**
** Created by: The Qt Meta Object Compiler version 67 (Qt 5.9.1)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "../../../COptionBox.h"
#include <QtCore/qbytearray.h>
#include <QtCore/qmetatype.h>
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'COptionBox.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 67
#error "This file was generated using the moc from 5.9.1. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
QT_WARNING_PUSH
QT_WARNING_DISABLE_DEPRECATED
struct qt_meta_stringdata_COptionBox_t {
    QByteArrayData data[8];
    char stringdata0[79];
};
#define QT_MOC_LITERAL(idx, ofs, len) \
    Q_STATIC_BYTE_ARRAY_DATA_HEADER_INITIALIZER_WITH_OFFSET(len, \
    qptrdiff(offsetof(qt_meta_stringdata_COptionBox_t, stringdata0) + ofs \
        - idx * sizeof(QByteArrayData)) \
    )
static const qt_meta_stringdata_COptionBox_t qt_meta_stringdata_COptionBox = {
    {
QT_MOC_LITERAL(0, 0, 10), // "COptionBox"
QT_MOC_LITERAL(1, 11, 8), // "signQuit"
QT_MOC_LITERAL(2, 20, 0), // ""
QT_MOC_LITERAL(3, 21, 8), // "signDone"
QT_MOC_LITERAL(4, 30, 12), // "signDownLoad"
QT_MOC_LITERAL(5, 43, 13), // "signShapeType"
QT_MOC_LITERAL(6, 57, 9), // "ShapeType"
QT_MOC_LITERAL(7, 67, 11) // "enShapetype"

    },
    "COptionBox\0signQuit\0\0signDone\0"
    "signDownLoad\0signShapeType\0ShapeType\0"
    "enShapetype"
};
#undef QT_MOC_LITERAL

static const uint qt_meta_data_COptionBox[] = {

 // content:
       7,       // revision
       0,       // classname
       0,    0, // classinfo
       4,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       4,       // signalCount

 // signals: name, argc, parameters, tag, flags
       1,    0,   34,    2, 0x06 /* Public */,
       3,    0,   35,    2, 0x06 /* Public */,
       4,    0,   36,    2, 0x06 /* Public */,
       5,    1,   37,    2, 0x06 /* Public */,

 // signals: parameters
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void, 0x80000000 | 6,    7,

       0        // eod
};

void COptionBox::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        COptionBox *_t = static_cast<COptionBox *>(_o);
        Q_UNUSED(_t)
        switch (_id) {
        case 0: _t->signQuit(); break;
        case 1: _t->signDone(); break;
        case 2: _t->signDownLoad(); break;
        case 3: _t->signShapeType((*reinterpret_cast< ShapeType(*)>(_a[1]))); break;
        default: ;
        }
    } else if (_c == QMetaObject::IndexOfMethod) {
        int *result = reinterpret_cast<int *>(_a[0]);
        void **func = reinterpret_cast<void **>(_a[1]);
        {
            typedef void (COptionBox::*_t)();
            if (*reinterpret_cast<_t *>(func) == static_cast<_t>(&COptionBox::signQuit)) {
                *result = 0;
                return;
            }
        }
        {
            typedef void (COptionBox::*_t)();
            if (*reinterpret_cast<_t *>(func) == static_cast<_t>(&COptionBox::signDone)) {
                *result = 1;
                return;
            }
        }
        {
            typedef void (COptionBox::*_t)();
            if (*reinterpret_cast<_t *>(func) == static_cast<_t>(&COptionBox::signDownLoad)) {
                *result = 2;
                return;
            }
        }
        {
            typedef void (COptionBox::*_t)(ShapeType );
            if (*reinterpret_cast<_t *>(func) == static_cast<_t>(&COptionBox::signShapeType)) {
                *result = 3;
                return;
            }
        }
    }
}

const QMetaObject COptionBox::staticMetaObject = {
    { &QWidget::staticMetaObject, qt_meta_stringdata_COptionBox.data,
      qt_meta_data_COptionBox,  qt_static_metacall, nullptr, nullptr}
};


const QMetaObject *COptionBox::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *COptionBox::qt_metacast(const char *_clname)
{
    if (!_clname) return nullptr;
    if (!strcmp(_clname, qt_meta_stringdata_COptionBox.stringdata0))
        return static_cast<void*>(const_cast< COptionBox*>(this));
    return QWidget::qt_metacast(_clname);
}

int COptionBox::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QWidget::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        if (_id < 4)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 4;
    } else if (_c == QMetaObject::RegisterMethodArgumentMetaType) {
        if (_id < 4)
            *reinterpret_cast<int*>(_a[0]) = -1;
        _id -= 4;
    }
    return _id;
}

// SIGNAL 0
void COptionBox::signQuit()
{
    QMetaObject::activate(this, &staticMetaObject, 0, nullptr);
}

// SIGNAL 1
void COptionBox::signDone()
{
    QMetaObject::activate(this, &staticMetaObject, 1, nullptr);
}

// SIGNAL 2
void COptionBox::signDownLoad()
{
    QMetaObject::activate(this, &staticMetaObject, 2, nullptr);
}

// SIGNAL 3
void COptionBox::signShapeType(ShapeType _t1)
{
    void *_a[] = { nullptr, const_cast<void*>(reinterpret_cast<const void*>(&_t1)) };
    QMetaObject::activate(this, &staticMetaObject, 3, _a);
}
QT_WARNING_POP
QT_END_MOC_NAMESPACE
