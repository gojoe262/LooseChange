/****************************************************************************
** Meta object code from reading C++ file 'EditCategoriesPresenter.h'
**
** Created by: The Qt Meta Object Compiler version 67 (Qt 5.4.0)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "../LooseChange_Src/UI/Presenter/EditCategoriesPresenter.h"
#include <QtCore/qbytearray.h>
#include <QtCore/qmetatype.h>
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'EditCategoriesPresenter.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 67
#error "This file was generated using the moc from 5.4.0. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
struct qt_meta_stringdata_EditCategoriesPresenter_t {
    QByteArrayData data[8];
    char stringdata[154];
};
#define QT_MOC_LITERAL(idx, ofs, len) \
    Q_STATIC_BYTE_ARRAY_DATA_HEADER_INITIALIZER_WITH_OFFSET(len, \
    qptrdiff(offsetof(qt_meta_stringdata_EditCategoriesPresenter_t, stringdata) + ofs \
        - idx * sizeof(QByteArrayData)) \
    )
static const qt_meta_stringdata_EditCategoriesPresenter_t qt_meta_stringdata_EditCategoriesPresenter = {
    {
QT_MOC_LITERAL(0, 0, 23), // "EditCategoriesPresenter"
QT_MOC_LITERAL(1, 24, 11), // "DataChanged"
QT_MOC_LITERAL(2, 36, 0), // ""
QT_MOC_LITERAL(3, 37, 25), // "on_pushButtonSave_clicked"
QT_MOC_LITERAL(4, 63, 27), // "on_pushButtonCancel_clicked"
QT_MOC_LITERAL(5, 91, 9), // "MarkDirty"
QT_MOC_LITERAL(6, 101, 24), // "on_pushButtonAdd_clicked"
QT_MOC_LITERAL(7, 126, 27) // "on_pushButtonRemove_clicked"

    },
    "EditCategoriesPresenter\0DataChanged\0"
    "\0on_pushButtonSave_clicked\0"
    "on_pushButtonCancel_clicked\0MarkDirty\0"
    "on_pushButtonAdd_clicked\0"
    "on_pushButtonRemove_clicked"
};
#undef QT_MOC_LITERAL

static const uint qt_meta_data_EditCategoriesPresenter[] = {

 // content:
       7,       // revision
       0,       // classname
       0,    0, // classinfo
       6,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       1,       // signalCount

 // signals: name, argc, parameters, tag, flags
       1,    0,   44,    2, 0x06 /* Public */,

 // slots: name, argc, parameters, tag, flags
       3,    0,   45,    2, 0x08 /* Private */,
       4,    0,   46,    2, 0x08 /* Private */,
       5,    0,   47,    2, 0x08 /* Private */,
       6,    0,   48,    2, 0x08 /* Private */,
       7,    0,   49,    2, 0x08 /* Private */,

 // signals: parameters
    QMetaType::Void,

 // slots: parameters
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,

       0        // eod
};

void EditCategoriesPresenter::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        EditCategoriesPresenter *_t = static_cast<EditCategoriesPresenter *>(_o);
        switch (_id) {
        case 0: _t->DataChanged(); break;
        case 1: _t->on_pushButtonSave_clicked(); break;
        case 2: _t->on_pushButtonCancel_clicked(); break;
        case 3: _t->MarkDirty(); break;
        case 4: _t->on_pushButtonAdd_clicked(); break;
        case 5: _t->on_pushButtonRemove_clicked(); break;
        default: ;
        }
    } else if (_c == QMetaObject::IndexOfMethod) {
        int *result = reinterpret_cast<int *>(_a[0]);
        void **func = reinterpret_cast<void **>(_a[1]);
        {
            typedef void (EditCategoriesPresenter::*_t)() const;
            if (*reinterpret_cast<_t *>(func) == static_cast<_t>(&EditCategoriesPresenter::DataChanged)) {
                *result = 0;
            }
        }
    }
    Q_UNUSED(_a);
}

const QMetaObject EditCategoriesPresenter::staticMetaObject = {
    { &QDialog::staticMetaObject, qt_meta_stringdata_EditCategoriesPresenter.data,
      qt_meta_data_EditCategoriesPresenter,  qt_static_metacall, Q_NULLPTR, Q_NULLPTR}
};


const QMetaObject *EditCategoriesPresenter::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *EditCategoriesPresenter::qt_metacast(const char *_clname)
{
    if (!_clname) return Q_NULLPTR;
    if (!strcmp(_clname, qt_meta_stringdata_EditCategoriesPresenter.stringdata))
        return static_cast<void*>(const_cast< EditCategoriesPresenter*>(this));
    return QDialog::qt_metacast(_clname);
}

int EditCategoriesPresenter::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QDialog::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        if (_id < 6)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 6;
    } else if (_c == QMetaObject::RegisterMethodArgumentMetaType) {
        if (_id < 6)
            *reinterpret_cast<int*>(_a[0]) = -1;
        _id -= 6;
    }
    return _id;
}

// SIGNAL 0
void EditCategoriesPresenter::DataChanged()const
{
    QMetaObject::activate(const_cast< EditCategoriesPresenter *>(this), &staticMetaObject, 0, Q_NULLPTR);
}
QT_END_MOC_NAMESPACE
