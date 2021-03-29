HEADERS += \
    exit.h \
    game.h \
    player.h \
    room.h

SOURCES += \
    exit.cpp \
    game.cpp \
    main.cpp \
    player.cpp \
    room.cpp

QT       += core gui \
         multimedia

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

RESOURCES += \
    res.qrc

DISTFILES +=
