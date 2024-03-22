/****************************************************************************
** Meta object code from reading C++ file 'sudokumainwindow.h'
**
** Created by: The Qt Meta Object Compiler version 68 (Qt 6.6.2)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "../../Sudoku/sudokumainwindow.h"
#include <QtCore/qmetatype.h>

#if __has_include(<QtCore/qtmochelpers.h>)
#include <QtCore/qtmochelpers.h>
#else
QT_BEGIN_MOC_NAMESPACE
#endif


#include <memory>

#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'sudokumainwindow.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 68
#error "This file was generated using the moc from 6.6.2. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

#ifndef Q_CONSTINIT
#define Q_CONSTINIT
#endif

QT_WARNING_PUSH
QT_WARNING_DISABLE_DEPRECATED
QT_WARNING_DISABLE_GCC("-Wuseless-cast")
namespace {

#ifdef QT_MOC_HAS_STRINGDATA
struct qt_meta_stringdata_CLASSSudokuMainWindowENDCLASS_t {};
constexpr auto qt_meta_stringdata_CLASSSudokuMainWindowENDCLASS = QtMocHelpers::stringData(
    "SudokuMainWindow",
    "reset_Btn",
    "",
    "on_StartBtn_clicked",
    "on_QuitBtn_clicked",
    "showWindow",
    "on_VEasyBtn_clicked",
    "on_EasyBtn_clicked"
);
#else  // !QT_MOC_HAS_STRING_DATA
struct qt_meta_stringdata_CLASSSudokuMainWindowENDCLASS_t {
    uint offsetsAndSizes[16];
    char stringdata0[17];
    char stringdata1[10];
    char stringdata2[1];
    char stringdata3[20];
    char stringdata4[19];
    char stringdata5[11];
    char stringdata6[20];
    char stringdata7[19];
};
#define QT_MOC_LITERAL(ofs, len) \
    uint(sizeof(qt_meta_stringdata_CLASSSudokuMainWindowENDCLASS_t::offsetsAndSizes) + ofs), len 
Q_CONSTINIT static const qt_meta_stringdata_CLASSSudokuMainWindowENDCLASS_t qt_meta_stringdata_CLASSSudokuMainWindowENDCLASS = {
    {
        QT_MOC_LITERAL(0, 16),  // "SudokuMainWindow"
        QT_MOC_LITERAL(17, 9),  // "reset_Btn"
        QT_MOC_LITERAL(27, 0),  // ""
        QT_MOC_LITERAL(28, 19),  // "on_StartBtn_clicked"
        QT_MOC_LITERAL(48, 18),  // "on_QuitBtn_clicked"
        QT_MOC_LITERAL(67, 10),  // "showWindow"
        QT_MOC_LITERAL(78, 19),  // "on_VEasyBtn_clicked"
        QT_MOC_LITERAL(98, 18)   // "on_EasyBtn_clicked"
    },
    "SudokuMainWindow",
    "reset_Btn",
    "",
    "on_StartBtn_clicked",
    "on_QuitBtn_clicked",
    "showWindow",
    "on_VEasyBtn_clicked",
    "on_EasyBtn_clicked"
};
#undef QT_MOC_LITERAL
#endif // !QT_MOC_HAS_STRING_DATA
} // unnamed namespace

Q_CONSTINIT static const uint qt_meta_data_CLASSSudokuMainWindowENDCLASS[] = {

 // content:
      12,       // revision
       0,       // classname
       0,    0, // classinfo
       6,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       0,       // signalCount

 // slots: name, argc, parameters, tag, flags, initial metatype offsets
       1,    0,   50,    2, 0x08,    1 /* Private */,
       3,    0,   51,    2, 0x08,    2 /* Private */,
       4,    0,   52,    2, 0x08,    3 /* Private */,
       5,    0,   53,    2, 0x08,    4 /* Private */,
       6,    0,   54,    2, 0x08,    5 /* Private */,
       7,    0,   55,    2, 0x08,    6 /* Private */,

 // slots: parameters
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,

       0        // eod
};

Q_CONSTINIT const QMetaObject SudokuMainWindow::staticMetaObject = { {
    QMetaObject::SuperData::link<QMainWindow::staticMetaObject>(),
    qt_meta_stringdata_CLASSSudokuMainWindowENDCLASS.offsetsAndSizes,
    qt_meta_data_CLASSSudokuMainWindowENDCLASS,
    qt_static_metacall,
    nullptr,
    qt_incomplete_metaTypeArray<qt_meta_stringdata_CLASSSudokuMainWindowENDCLASS_t,
        // Q_OBJECT / Q_GADGET
        QtPrivate::TypeAndForceComplete<SudokuMainWindow, std::true_type>,
        // method 'reset_Btn'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        // method 'on_StartBtn_clicked'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        // method 'on_QuitBtn_clicked'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        // method 'showWindow'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        // method 'on_VEasyBtn_clicked'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        // method 'on_EasyBtn_clicked'
        QtPrivate::TypeAndForceComplete<void, std::false_type>
    >,
    nullptr
} };

void SudokuMainWindow::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        auto *_t = static_cast<SudokuMainWindow *>(_o);
        (void)_t;
        switch (_id) {
        case 0: _t->reset_Btn(); break;
        case 1: _t->on_StartBtn_clicked(); break;
        case 2: _t->on_QuitBtn_clicked(); break;
        case 3: _t->showWindow(); break;
        case 4: _t->on_VEasyBtn_clicked(); break;
        case 5: _t->on_EasyBtn_clicked(); break;
        default: ;
        }
    }
    (void)_a;
}

const QMetaObject *SudokuMainWindow::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *SudokuMainWindow::qt_metacast(const char *_clname)
{
    if (!_clname) return nullptr;
    if (!strcmp(_clname, qt_meta_stringdata_CLASSSudokuMainWindowENDCLASS.stringdata0))
        return static_cast<void*>(this);
    return QMainWindow::qt_metacast(_clname);
}

int SudokuMainWindow::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
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
            *reinterpret_cast<QMetaType *>(_a[0]) = QMetaType();
        _id -= 6;
    }
    return _id;
}
QT_WARNING_POP
