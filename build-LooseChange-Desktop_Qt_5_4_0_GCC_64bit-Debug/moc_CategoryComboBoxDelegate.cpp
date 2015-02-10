/****************************************************************************
** Meta object code from reading C++ file 'CategoryComboBoxDelegate.h'
**
** Created by: The Qt Meta Object Compiler version 67 (Qt 5.4.0)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "../LooseChange_Src/UI/Delegates/CategoryComboBoxDelegate.h"
#include <QtCore/qbytearray.h>
#include <QtCore/qmetatype.h>
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'CategoryComboBoxDelegate.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 67
#error "This file was generated using the moc from 5.4.0. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
struct qt_meta_stringdata_CategoryComboBoxDelegate_t {
    QByteArrayData data[4];
    char stringdata[53];
};
#define QT_MOC_LITERAL(idx, ofs, len) \
    Q_STATIC_BYTE_ARRAY_DATA_HEADER_INITIALIZER_WITH_OFFSET(len, \
    qptrdiff(offsetof(qt_meta_stringdata_CategoryComboBoxDelegate_t, stringdata) + ofs \
        - idx * sizeof(QByteArrayData)) \
    )
static const qt_meta_stringdata_CategoryComboBoxDelegate_t qt_meta_stringdata_CategoryComboBoxDelegate = {
    {
QT_MOC_LITERAL(0, 0, 24), // "CategoryComboBoxDelegate"
QT_MOC_LITERAL(1, 25, 20), // "AddCategoryRequested"
QT_MOC_LITERAL(2, 46, 0), // ""
QT_MOC_LITERAL(3, 47, 5) // "index"

    },
    "CategoryComboBoxDelegate\0AddCategoryRequested\0"
    "\0index"
};
#undef QT_MOC_LITERAL

static const uint qt_meta_data_CategoryComboBoxDelegate[] = {

 // content:
       7,       // revision
       0,       // classname
       0,    0, // classinfo
       1,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       1,       // signalCount

 // signals: name, argc, parameters, tag, flags
       1,    1,   19,    2, 0x06 /* Public */,

 // signals: parameters
    QMetaType::Void, QMetaType::QModelIndex,    3,

       0        // eod
};

void CategoryComboBoxDelegate::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        CategoryComboBoxDelegate *_t = static_cast<CategoryComboBoxDelegate *>(_o);
        switch (_id) {
        case 0: _t->AddCategoryRequested((*reinterpret_cast< QModelIndex(*)>(_a[1]))); break;
        default: ;
        }
    } else if (_c == QMetaObject::IndexOfMethod) {
        int *result = reinterpret_cast<int *>(_a[0]);
        void **func = reinterpret_cast<void **>(_a[1]);
        {
            typedef void (CategoryComboBoxDelegate::*_t)(QModelIndex ) const;
            if (*reinterpret_cast<_t *>(func) == static_cast<_t>(&CategoryComboBoxDelegate::AddCategoryRequested)) {
                *result = 0;
            }
        }
    }
}

const QMetaObject CategoryComboBoxDelegate::staticMetaObject = {
    { &QItemDelegate::staticMetaObject, qt_meta_stringdata_CategoryComboBoxDelegate.data,
      qt_meta_data_CategoryComboBoxDelegate,  qt_static_metacall, Q_NULLPTR, Q_NULLPTR}
};


const QMetaObject *CategoryComboBoxDelegate::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *CategoryComboBoxDelegate::qt_metacast(const char *_clname)
{
    if (!_clname) return Q_NULLPTR;
    if (!strcmp(_clname, qt_meta_stringdata_CategoryComboBoxDelegate.stringdata))
        return static_cast<void*>(const_cast< CategoryComboBoxDelegate*>(this));
    return QItemDelegate::qt_metacast(_clname);
}

int CategoryComboBoxDelegate::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QItemDelegate::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        if (_id < 1)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 1;
    } else if (_c == QMetaObject::RegisterMethodArgumentMetaType) {
        if (_id < 1)
            *reinterpret_cast<int*>(_a[0]) = -1;
        _id -= 1;
    }
    return _id;
}

// SIGNAL 0
void CategoryComboBoxDelegate::AddCategoryRequested(QModelIndex _t1)const
{
    void *_a[] = { Q_NULLPTR, const_cast<void*>(reinterpret_cast<const void*>(&_t1)) };
    QMetaObject::activate(const_cast< CategoryComboBoxDelegate *>(this), &staticMetaObject, 0, _a);
}
QT_END_MOC_NAMESPACE
