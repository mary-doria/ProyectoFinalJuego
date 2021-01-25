/****************************************************************************
** Meta object code from reading C++ file 'mainwindow.h'
**
** Created by: The Qt Meta Object Compiler version 67 (Qt 5.12.9)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "../../ProyectoFinal/mainwindow.h"
#include <QtCore/qbytearray.h>
#include <QtCore/qmetatype.h>
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'mainwindow.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 67
#error "This file was generated using the moc from 5.12.9. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
QT_WARNING_PUSH
QT_WARNING_DISABLE_DEPRECATED
struct qt_meta_stringdata_MainWindow_t {
    QByteArrayData data[17];
    char stringdata0[295];
};
#define QT_MOC_LITERAL(idx, ofs, len) \
    Q_STATIC_BYTE_ARRAY_DATA_HEADER_INITIALIZER_WITH_OFFSET(len, \
    qptrdiff(offsetof(qt_meta_stringdata_MainWindow_t, stringdata0) + ofs \
        - idx * sizeof(QByteArrayData)) \
    )
static const qt_meta_stringdata_MainWindow_t qt_meta_stringdata_MainWindow = {
    {
QT_MOC_LITERAL(0, 0, 10), // "MainWindow"
QT_MOC_LITERAL(1, 11, 9), // "moveEnemy"
QT_MOC_LITERAL(2, 21, 0), // ""
QT_MOC_LITERAL(3, 22, 7), // "activaG"
QT_MOC_LITERAL(4, 30, 11), // "activaSalto"
QT_MOC_LITERAL(5, 42, 23), // "actualizar_frutaburbuja"
QT_MOC_LITERAL(6, 66, 15), // "actualizar_vida"
QT_MOC_LITERAL(7, 82, 17), // "actualizar_portal"
QT_MOC_LITERAL(8, 100, 11), // "crearMoscas"
QT_MOC_LITERAL(9, 112, 16), // "actualizarMoscas"
QT_MOC_LITERAL(10, 129, 22), // "on_bottonJugar_clicked"
QT_MOC_LITERAL(11, 152, 30), // "on_bottonInstrucciones_clicked"
QT_MOC_LITERAL(12, 183, 29), // "on_bottonMultijugador_clicked"
QT_MOC_LITERAL(13, 213, 24), // "on_radioButton_2_clicked"
QT_MOC_LITERAL(14, 238, 22), // "on_radioButton_clicked"
QT_MOC_LITERAL(15, 261, 27), // "on_label_windowTitleChanged"
QT_MOC_LITERAL(16, 289, 5) // "title"

    },
    "MainWindow\0moveEnemy\0\0activaG\0activaSalto\0"
    "actualizar_frutaburbuja\0actualizar_vida\0"
    "actualizar_portal\0crearMoscas\0"
    "actualizarMoscas\0on_bottonJugar_clicked\0"
    "on_bottonInstrucciones_clicked\0"
    "on_bottonMultijugador_clicked\0"
    "on_radioButton_2_clicked\0"
    "on_radioButton_clicked\0"
    "on_label_windowTitleChanged\0title"
};
#undef QT_MOC_LITERAL

static const uint qt_meta_data_MainWindow[] = {

 // content:
       8,       // revision
       0,       // classname
       0,    0, // classinfo
      14,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       0,       // signalCount

 // slots: name, argc, parameters, tag, flags
       1,    0,   84,    2, 0x0a /* Public */,
       3,    0,   85,    2, 0x0a /* Public */,
       4,    0,   86,    2, 0x0a /* Public */,
       5,    0,   87,    2, 0x0a /* Public */,
       6,    0,   88,    2, 0x0a /* Public */,
       7,    0,   89,    2, 0x0a /* Public */,
       8,    0,   90,    2, 0x0a /* Public */,
       9,    0,   91,    2, 0x0a /* Public */,
      10,    0,   92,    2, 0x08 /* Private */,
      11,    0,   93,    2, 0x08 /* Private */,
      12,    0,   94,    2, 0x08 /* Private */,
      13,    0,   95,    2, 0x08 /* Private */,
      14,    0,   96,    2, 0x08 /* Private */,
      15,    1,   97,    2, 0x08 /* Private */,

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
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void, QMetaType::QString,   16,

       0        // eod
};

void MainWindow::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        auto *_t = static_cast<MainWindow *>(_o);
        Q_UNUSED(_t)
        switch (_id) {
        case 0: _t->moveEnemy(); break;
        case 1: _t->activaG(); break;
        case 2: _t->activaSalto(); break;
        case 3: _t->actualizar_frutaburbuja(); break;
        case 4: _t->actualizar_vida(); break;
        case 5: _t->actualizar_portal(); break;
        case 6: _t->crearMoscas(); break;
        case 7: _t->actualizarMoscas(); break;
        case 8: _t->on_bottonJugar_clicked(); break;
        case 9: _t->on_bottonInstrucciones_clicked(); break;
        case 10: _t->on_bottonMultijugador_clicked(); break;
        case 11: _t->on_radioButton_2_clicked(); break;
        case 12: _t->on_radioButton_clicked(); break;
        case 13: _t->on_label_windowTitleChanged((*reinterpret_cast< const QString(*)>(_a[1]))); break;
        default: ;
        }
    }
}

QT_INIT_METAOBJECT const QMetaObject MainWindow::staticMetaObject = { {
    &QMainWindow::staticMetaObject,
    qt_meta_stringdata_MainWindow.data,
    qt_meta_data_MainWindow,
    qt_static_metacall,
    nullptr,
    nullptr
} };


const QMetaObject *MainWindow::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *MainWindow::qt_metacast(const char *_clname)
{
    if (!_clname) return nullptr;
    if (!strcmp(_clname, qt_meta_stringdata_MainWindow.stringdata0))
        return static_cast<void*>(this);
    return QMainWindow::qt_metacast(_clname);
}

int MainWindow::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QMainWindow::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        if (_id < 14)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 14;
    } else if (_c == QMetaObject::RegisterMethodArgumentMetaType) {
        if (_id < 14)
            *reinterpret_cast<int*>(_a[0]) = -1;
        _id -= 14;
    }
    return _id;
}
QT_WARNING_POP
QT_END_MOC_NAMESPACE
