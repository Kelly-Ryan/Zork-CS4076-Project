HEADERS += \
    enemy.h \
    exit.h \
    game.h \
    gameitem.h \
    healthbar.h \
    inventory.h \
    item.h \
    mainwindow.h \
    player.h \
    room.h \
    weapon.h

SOURCES += \
    WeaponException.cpp \
    enemy.cpp \
    exit.cpp \
    game.cpp \
    gameitem.cpp \
    healthbar.cpp \
    inventory.cpp \
    item.cpp \
    main.cpp \
    mainwindow.cpp \
    player.cpp \
    room.cpp \
    weapon.cpp

QT       += core gui \
         multimedia

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

RESOURCES += \
    res.qrc

DISTFILES +=

FORMS += \
    mainwindow.ui
