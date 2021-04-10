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
<<<<<<< HEAD
    roomkey.h \
=======
    treasure.h \
>>>>>>> main
    weapon.h

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
<<<<<<< HEAD
    roomkey.cpp \
=======
    treasure.cpp \
>>>>>>> main
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
