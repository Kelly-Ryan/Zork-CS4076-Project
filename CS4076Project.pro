HEADERS += \
    customlistwidget.h \
    enemy.h \
    exit.h \
    game.h \
    gamePopup.h \
    gameitem.h \
    healthbar.h \
    healthpotion.h \
    inventory.h \
    mainwindow.h \
    player.h \
    room.h \
    roomkey.h \
    treasure.h \
    weapon.h \
    zorknamespace.h

SOURCES += \
    enemy.cpp \
    exit.cpp \
    game.cpp \
    gamePopup.cpp \
    gameitem.cpp \
    healthbar.cpp \
    healthpotion.cpp \
    main.cpp \
    mainwindow.cpp \
    player.cpp \
    room.cpp \
    roomkey.cpp \
    treasure.cpp \
    weapon.cpp \
    weaponException.cpp \
    zorknamespace.cpp

QT       += core gui \
         multimedia

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

RESOURCES += \
    res.qrc

DISTFILES +=

FORMS += \
    mainwindow.ui
