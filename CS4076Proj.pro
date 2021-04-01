QT       += core gui

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

CONFIG += c++11

# You can make your code fail to compile if it uses deprecated APIs.
# In order to do so, uncomment the following line.
#DEFINES += QT_DISABLE_DEPRECATED_BEFORE=0x060000    # disables all the APIs deprecated before Qt 6.0.0

SOURCES += \
    Enemy.cpp \
    Exit.cpp \
    Game.cpp \
    Gameitem.cpp \
    Inventory.cpp \
    Item.cpp \
    Player.cpp \
    Room.cpp \
    Weapon.cpp \
    main.cpp

HEADERS += \
    Enemy.h \
    Exit.h \
    Game.h \
    Gameitem.h \
    Inventory.h \
    Item.h \
    Player.h \
    Room.h \
    Weapon.h

FORMS +=

# Default rules for deployment.
qnx: target.path = /tmp/$${TARGET}/bin
else: unix:!android: target.path = /opt/$${TARGET}/bin
!isEmpty(target.path): INSTALLS += target

RESOURCES += \
    resources.qrc
