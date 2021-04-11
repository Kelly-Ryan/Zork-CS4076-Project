#ifndef PLAYER_H
#define PLAYER_H

#include <QGraphicsPixmapItem>
#include <QObject>

#include "exit.h"
#include "game.h"
#include "gameitem.h"
#include "healthbar.h"
#include "weapon.h"
#include "roomkey.h"

#define SPEED 5
#define MAX_HEALTH 10

class Game;
class Enemy;

class Player : public QObject, public QGraphicsPixmapItem {
Q_OBJECT
    enum Type{WEAPON,KEY};

    /* ItemHolding is a tagged union, the enum above acts as the tag
     * Need the tag to do exception checking and also to prevent undefined behaviour
     */
    struct ItemHolding{
    Type type;

    union {
        Weapon *weapon;
        RoomKey *key;
    } inHand;

    void setType(Type t)
    {
        type = t;
    }

    Type getType()
    {
        return type;
    }

};

    friend void operator+(Enemy &enemy,Player &player);
private:
    int health = MAX_HEALTH;
    bool alive = true;
    Game *game;
    Healthbar *hitPoints;
    struct ItemHolding holding;
    void keyPressEvent(QKeyEvent *event);
    void collision();

signals:
    void itemCollected(GameItem *item);
    void healthPotion();

public slots:
    void equipPlayer(GameItem *itemSelected);

public:
    Player(QGraphicsItem * parent=0);
    Player(int xPos, int yPos, Game *game);
    ~Player();
    int getHealth();
    bool isAlive();
    Healthbar* getHealthbar();
    void defeated();
};

#endif // PLAYER_H
