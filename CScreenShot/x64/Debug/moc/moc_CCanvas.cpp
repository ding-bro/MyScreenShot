/****************************************************************************
** Meta object code from reading C++ file 'CCanvas.h'
**
** Created by: The Qt Meta Object Compiler version 67 (Qt 5.9.1)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "../../../CCanvas.h"
#include <QtCore/qbytearray.h>
#include <QtCore/qmetatype.h>
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'CCanvas.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 67
#error "This file was generated using the moc from 5.9.1. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
QT_WARNING_PUSH
QT_WARNING_DISABLE_DEPRECATED
struct qt_meta_stringdata_CCanvas_t {
    QByteArrayData data[18];
    char stringdata0[193];
};
#define QT_MOC_LITERAL(idx, ofs, len) \
    Q_STATIC_BYTE_ARRAY_DATA_HEADER_INITIALIZER_WITH_OFFSET(len, \
    qptrdiff(offsetof(qt_meta_stringdata_CCanvas_t, stringdata0) + ofs \
        - idx * sizeof(QByteArrayData)) \
    )
static const qt_meta_stringdata_CCanvas_t qt_meta_stringdata_CCanvas = {
    {
QT_MOC_LITERAL(0, 0, 7), // "CCanvas"
QT_MOC_LITERAL(1, 8, 18), // "signMainwindowShow"
QT_MOC_LITERAL(2, 27, 0), // ""
QT_MOC_LITERAL(3, 28, 12), // "signDownLoad"
QT_MOC_LITERAL(4, 41, 8), // "CCanvas*"
QT_MOC_LITERAL(5, 50, 7), // "pCanvas"
QT_MOC_LITERAL(6, 58, 11), // "COptionBox*"
QT_MOC_LITERAL(7, 70, 7), // "pOption"
QT_MOC_LITERAL(8, 78, 8), // "QPixmap&"
QT_MOC_LITERAL(9, 87, 7), // "qPixmap"
QT_MOC_LITERAL(10, 95, 14), // "slotFullScreen"
QT_MOC_LITERAL(11, 110, 15), // "slotCanvasClose"
QT_MOC_LITERAL(12, 126, 11), // "slotPenType"
QT_MOC_LITERAL(13, 138, 9), // "SPenType&"
QT_MOC_LITERAL(14, 148, 8), // "sPentype"
QT_MOC_LITERAL(15, 157, 13), // "slotShapeType"
QT_MOC_LITERAL(16, 171, 9), // "ShapeType"
QT_MOC_LITERAL(17, 181, 11) // "enShapetype"

    },
    "CCanvas\0signMainwindowShow\0\0signDownLoad\0"
    "CCanvas*\0pCanvas\0COptionBox*\0pOption\0"
    "QPixmap&\0qPixmap\0slotFullScreen\0"
    "slotCanvasClose\0slotPenType\0SPenType&\0"
    "sPentype\0slotShapeType\0ShapeType\0"
    "enShapetype"
};
#undef QT_MOC_LITERAL

static const uint qt_meta_data_CCanvas[] = {

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
       3,    3,   45,    2, 0x06 /* Public */,

 // slots: name, argc, parameters, tag, flags
      10,    0,   52,    2, 0x0a /* Public */,
      11,    0,   53,    2, 0x0a /* Public */,
      12,    1,   54,    2, 0x0a /* Public */,
      15,    1,   57,    2, 0x0a /* Public */,

 // signals: parameters
    QMetaType::Void,
    QMetaType::Void, 0x80000000 | 4, 0x80000000 | 6, 0x80000000 | 8,    5,    7,    9,

 // slots: parameters
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void, 0x80000000 | 13,   14,
    QMetaType::Void, 0x80000000 | 16,   17,

       0        // eod
};

void CCanvas::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        CCanvas *_t = static_cast<CCanvas *>(_o);
        Q_UNUSED(_t)
        switch (_id) {
        case 0: _t->signMainwindowShow(); break;
        case 1: _t->signDownLoad((*reinterpret_cast< CCanvas*(*)>(_a[1])),(*reinterpret_cast< COptionBox*(*)>(_a[2])),(*reinterpret_cast< QPixmap(*)>(_a[3]))); break;
        case 2: _t->slotFullScreen(); break;
        case 3: _t->slotCanvasClose(); break;
        case 4: _t->slotPenType((*reinterpret_cast< SPenType(*)>(_a[1]))); break;
        case 5: _t->slotShapeType((*reinterpret_cast< ShapeType(*)>(_a[1]))); break;
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
        }
    } else if (_c == QMetaObject::IndexOfMethod) {
        int *result = reinterpret_cast<int *>(_a[0]);
        void **func = reinterpret_cast<void **>(_a[1]);
        {
            typedef void (CCanvas::*_t)();
            if (*reinterpret_cast<_t *>(func) == static_cast<_t>(&CCanvas::signMainwindowShow)) {
                *result = 0;
                return;
            }
        }
        {
            typedef void (CCanvas::*_t)(CCanvas * , COptionBox * , QPixmap & );
            if (*reinterpret_cast<_t *>(func) == static_cast<_t>(&CCanvas::signDownLoad)) {
                *result = 1;
                return;
            }
        }
    }
}

const QMetaObject CCanvas::staticMetaObject = {
    { &QWidget::staticMetaObject, qt_meta_stringdata_CCanvas.data,
      qt_meta_data_CCanvas,  qt_static_metacall, nullptr, nullptr}
};


const QMetaObject *CCanvas::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *CCanvas::qt_metacast(const char *_clname)
{
    if (!_clname) return nullptr;
    if (!strcmp(_clname, qt_meta_stringdata_CCanvas.stringdata0))
        return static_cast<void*>(const_cast< CCanvas*>(this));
    if (!strcmp(_clname, "enable_shared_from_this<CCanvas>"))
        return static_cast< enable_shared_from_this<CCanvas>*>(const_cast< CCanvas*>(this));
    if (!strcmp(_clname, "CAbstract"))
        return static_cast< CAbstract*>(const_cast< CCanvas*>(this));
    return QWidget::qt_metacast(_clname);
}

int CCanvas::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QWidget::qt_metacall(_c, _id, _a);
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
void CCanvas::signMainwindowShow()
{
    QMetaObject::activate(this, &staticMetaObject, 0, nullptr);
}

// SIGNAL 1
void CCanvas::signDownLoad(CCanvas * _t1, COptionBox * _t2, QPixmap & _t3)
{
    void *_a[] = { nullptr, const_cast<void*>(reinterpret_cast<const void*>(&_t1)), const_cast<void*>(reinterpret_cast<const void*>(&_t2)), const_cast<void*>(reinterpret_cast<const void*>(&_t3)) };
    QMetaObject::activate(this, &staticMetaObject, 1, _a);
}
QT_WARNING_POP
QT_END_MOC_NAMESPACE
