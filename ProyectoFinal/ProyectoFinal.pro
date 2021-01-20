QT       += core gui

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

CONFIG += c++11

# You can make your code fail to compile if it uses deprecated APIs.
# In order to do so, uncomment the following line.
#DEFINES += QT_DISABLE_DEPRECATED_BEFORE=0x060000    # disables all the APIs deprecated before Qt 6.0.0

SOURCES += \
    bala.cpp \
    cuerpopersonajejugador.cpp \
    frutaburbuja.cpp \
    main.cpp \
    mainwindow.cpp \
    nave.cpp \
    plataforma.cpp \
    score.cpp \
    spritegusano.cpp \
    vida.cpp

HEADERS += \
    bala.h \
    cuerpopersonajejugador.h \
    frutaburbuja.h \
    mainwindow.h \
    nave.h \
    plataforma.h \
    score.h \
    spritegusano.h \
    vida.h

FORMS += \
    mainwindow.ui

# Default rules for deployment.
qnx: target.path = /tmp/$${TARGET}/bin
else: unix:!android: target.path = /opt/$${TARGET}/bin
!isEmpty(target.path): INSTALLS += target

RESOURCES += \
    Imagenes.qrc \
    Imagenes.qrc

DISTFILES +=
