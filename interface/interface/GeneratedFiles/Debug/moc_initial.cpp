/****************************************************************************
** Meta object code from reading C++ file 'initial.h'
**
** Created by: The Qt Meta Object Compiler version 63 (Qt 4.8.6)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "../../initial.h"
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'initial.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 63
#error "This file was generated using the moc from 4.8.6. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
static const uint qt_meta_data_initial[] = {

 // content:
       6,       // revision
       0,       // classname
       0,    0, // classinfo
      10,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       0,       // signalCount

 // slots: signature, parameters, type, tag, flags
      16,    8,    9,    8, 0x08,
      26,    8,    9,    8, 0x08,
      36,    8,    9,    8, 0x08,
      50,    8,   46,    8, 0x08,
      60,    8,   46,    8, 0x08,
      70,    8,   46,    8, 0x08,
      80,    8,    9,    8, 0x08,
      92,    8,    9,    8, 0x08,
     102,    8,   46,    8, 0x08,
     111,    8,    8,    8, 0x08,

       0        // eod
};

static const char qt_meta_stringdata_initial[] = {
    "initial\0\0double\0ongkjkd()\0ongkjhd()\0"
    "ongkjmd()\0int\0oncyzgs()\0onhyzgs()\0"
    "onoyzgs()\0ondzsrsnl()\0ondzsbj()\0"
    "ondzgs()\0onstart()\0"
};

void initial::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        Q_ASSERT(staticMetaObject.cast(_o));
        initial *_t = static_cast<initial *>(_o);
        switch (_id) {
        case 0: { double _r = _t->ongkjkd();
            if (_a[0]) *reinterpret_cast< double*>(_a[0]) = _r; }  break;
        case 1: { double _r = _t->ongkjhd();
            if (_a[0]) *reinterpret_cast< double*>(_a[0]) = _r; }  break;
        case 2: { double _r = _t->ongkjmd();
            if (_a[0]) *reinterpret_cast< double*>(_a[0]) = _r; }  break;
        case 3: { int _r = _t->oncyzgs();
            if (_a[0]) *reinterpret_cast< int*>(_a[0]) = _r; }  break;
        case 4: { int _r = _t->onhyzgs();
            if (_a[0]) *reinterpret_cast< int*>(_a[0]) = _r; }  break;
        case 5: { int _r = _t->onoyzgs();
            if (_a[0]) *reinterpret_cast< int*>(_a[0]) = _r; }  break;
        case 6: { double _r = _t->ondzsrsnl();
            if (_a[0]) *reinterpret_cast< double*>(_a[0]) = _r; }  break;
        case 7: { double _r = _t->ondzsbj();
            if (_a[0]) *reinterpret_cast< double*>(_a[0]) = _r; }  break;
        case 8: { int _r = _t->ondzgs();
            if (_a[0]) *reinterpret_cast< int*>(_a[0]) = _r; }  break;
        case 9: _t->onstart(); break;
        default: ;
        }
    }
}

const QMetaObjectExtraData initial::staticMetaObjectExtraData = {
    0,  qt_static_metacall 
};

const QMetaObject initial::staticMetaObject = {
    { &QMainWindow::staticMetaObject, qt_meta_stringdata_initial,
      qt_meta_data_initial, &staticMetaObjectExtraData }
};

#ifdef Q_NO_DATA_RELOCATION
const QMetaObject &initial::getStaticMetaObject() { return staticMetaObject; }
#endif //Q_NO_DATA_RELOCATION

const QMetaObject *initial::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->metaObject : &staticMetaObject;
}

void *initial::qt_metacast(const char *_clname)
{
    if (!_clname) return 0;
    if (!strcmp(_clname, qt_meta_stringdata_initial))
        return static_cast<void*>(const_cast< initial*>(this));
    return QMainWindow::qt_metacast(_clname);
}

int initial::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QMainWindow::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        if (_id < 10)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 10;
    }
    return _id;
}
QT_END_MOC_NAMESPACE
