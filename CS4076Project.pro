HEADERS += \
    customlistwidget.h \
    enemy.h \
    exit.h \
    game.h \
    gamePopup.h \
    gameitem.h \
    healthbar.h \
    inventory.h \
    item.h \
    mainwindow.h \
    player.h \
    room.h \
    treasure.h \
    weapon.h

SOURCES += \
    enemy.cpp \
    exit.cpp \
    game.cpp \
    gamePopup.cpp \
    gameitem.cpp \
    healthbar.cpp \
    item.cpp \
    main.cpp \
    mainwindow.cpp \
    player.cpp \
    room.cpp \
    treasure.cpp \
    weapon.cpp \
    weaponException.cpp

QT       += core gui \
         multimedia

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

RESOURCES += \
    res.qrc

DISTFILES +=

FORMS += \
    mainwindow.ui
