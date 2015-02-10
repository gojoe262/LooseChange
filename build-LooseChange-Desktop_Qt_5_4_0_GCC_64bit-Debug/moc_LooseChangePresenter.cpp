/****************************************************************************
** Meta object code from reading C++ file 'LooseChangePresenter.h'
**
** Created by: The Qt Meta Object Compiler version 67 (Qt 5.4.0)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "../LooseChange_Src/UI/Presenter/LooseChangePresenter.h"
#include <QtCore/qbytearray.h>
#include <QtCore/qmetatype.h>
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'LooseChangePresenter.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 67
#error "This file was generated using the moc from 5.4.0. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
struct qt_meta_stringdata_LooseChangePresenter_t {
    QByteArrayData data[11];
    char stringdata[247];
};
#define QT_MOC_LITERAL(idx, ofs, len) \
    Q_STATIC_BYTE_ARRAY_DATA_HEADER_INITIALIZER_WITH_OFFSET(len, \
    qptrdiff(offsetof(qt_meta_stringdata_LooseChangePresenter_t, stringdata) + ofs \
        - idx * sizeof(QByteArrayData)) \
    )
static const qt_meta_stringdata_LooseChangePresenter_t qt_meta_stringdata_LooseChangePresenter = {
    {
QT_MOC_LITERAL(0, 0, 20), // "LooseChangePresenter"
QT_MOC_LITERAL(1, 21, 25), // "on_toolButtonOpen_clicked"
QT_MOC_LITERAL(2, 47, 0), // ""
QT_MOC_LITERAL(3, 48, 25), // "on_toolButtonSave_clicked"
QT_MOC_LITERAL(4, 74, 23), // "on_actionOpen_triggered"
QT_MOC_LITERAL(5, 98, 23), // "on_actionSave_triggered"
QT_MOC_LITERAL(6, 122, 34), // "on_actionEdit_Categories_trig..."
QT_MOC_LITERAL(7, 157, 10), // "EnableSave"
QT_MOC_LITERAL(8, 168, 11), // "DisableSave"
QT_MOC_LITERAL(9, 180, 41), // "on_toolButtonShowRawViewPrese..."
QT_MOC_LITERAL(10, 222, 24) // "on_actionE_xit_triggered"

    },
    "LooseChangePresenter\0on_toolButtonOpen_clicked\0"
    "\0on_toolButtonSave_clicked\0"
    "on_actionOpen_triggered\0on_actionSave_triggered\0"
    "on_actionEdit_Categories_triggered\0"
    "EnableSave\0DisableSave\0"
    "on_toolButtonShowRawViewPresenter_clicked\0"
    "on_actionE_xit_triggered"
};
#undef QT_MOC_LITERAL

static const uint qt_meta_data_LooseChangePresenter[] = {

 // content:
       7,       // revision
       0,       // classname
       0,    0, // classinfo
       9,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       0,       // signalCount

 // slots: name, argc, parameters, tag, flags
       1,    0,   59,    2, 0x08 /* Private */,
       3,    0,   60,    2, 0x08 /* Private */,
       4,    0,   61,    2, 0x08 /* Private */,
       5,    0,   62,    2, 0x08 /* Private */,
       6,    0,   63,    2, 0x08 /* Private */,
       7,    0,   64,    2, 0x08 /* Private */,
       8,    0,   65,    2, 0x08 /* Private */,
       9,    0,   66,    2, 0x08 /* Private */,
      10,    0,   67,    2, 0x08 /* Private */,

 // slots: parameters
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

void LooseChangePresenter::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        LooseChangePresenter *_t = static_cast<LooseChangePresenter *>(_o);
        switch (_id) {
        case 0: _t->on_toolButtonOpen_clicked(); break;
        case 1: _t->on_toolButtonSave_clicked(); break;
        case 2: _t->on_actionOpen_triggered(); break;
        case 3: _t->on_actionSave_triggered(); break;
        case 4: _t->on_actionEdit_Categories_triggered(); break;
        case 5: _t->EnableSave(); break;
        case 6: _t->DisableSave(); break;
        case 7: _t->on_toolButtonShowRawViewPresenter_clicked(); break;
        case 8: _t->on_actionE_xit_triggered(); break;
        default: ;
        }
    }
    Q_UNUSED(_a);
}

const QMetaObject LooseChangePresenter::staticMetaObject = {
    { &QMainWindow::staticMetaObject, qt_meta_stringdata_LooseChangePresenter.data,
      qt_meta_data_LooseChangePresenter,  qt_static_metacall, Q_NULLPTR, Q_NULLPTR}
};


const QMetaObject *LooseChangePresenter::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *LooseChangePresenter::qt_metacast(const char *_clname)
{
    if (!_clname) return Q_NULLPTR;
    if (!strcmp(_clname, qt_meta_stringdata_LooseChangePresenter.stringdata))
        return static_cast<void*>(const_cast< LooseChangePresenter*>(this));
    return QMainWindow::qt_metacast(_clname);
}

int LooseChangePresenter::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QMainWindow::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        if (_id < 9)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 9;
    } else if (_c == QMetaObject::RegisterMethodArgumentMetaType) {
        if (_id < 9)
            *reinterpret_cast<int*>(_a[0]) = -1;
        _id -= 9;
    }
    return _id;
}
QT_END_MOC_NAMESPACE
