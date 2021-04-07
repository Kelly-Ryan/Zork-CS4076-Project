#ifndef PLAYER_H
#define PLAYER_H

#include <QGraphicsPixmapItem>
#include <QObject>

#include "exit.h"
#include "game.h"
#include "gameitem.h"
#include "healthbar.h"
#include "weapon.h" //can remove after

class Game;

class Player : public QObject, public QGraphicsPixmapItem {
Q_OBJECT
    friend void operator+(Enemy &enemy,Player &player);
private:
    int speed = 10;
    int health = 5;
    bool alive = true;
    Game *game;
    Healthbar *hitPoints;
    GameItem *itemHolding = 0;
    void keyPressEvent(QKeyEvent *event);
    void collision();
signals:
    void itemCollected(GameItem *item);
public slots:
    void equipPlayer(GameItem *item);
public:
    Player(QGraphicsItem * parent=0);
    Player(int xPos, int yPos, Game *game);
    ~Player();
    int getHealth();
    bool isAlive();
    Healthbar* getHealthbar();
    GameItem* getItemHolding();
};

#endif // PLAYER_H
