HEADERS += \
    enemy.h \
    exit.h \
    game.h \
    gameitem.h \
    inventory.h \
    item.h \
    player.h \
    room.h \
    weapon.h

SOURCES += \
    enemy.cpp \
    exit.cpp \
    game.cpp \
    gameitem.cpp \
    inventory.cpp \
    item.cpp \
    main.cpp \
    player.cpp \
    room.cpp \
    weapon.cpp

QT       += core gui \
         multimedia

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

RESOURCES += \
    res.qrc

DISTFILES +=
