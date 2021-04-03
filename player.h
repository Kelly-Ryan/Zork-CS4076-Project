#ifndef PLAYER_H
#define PLAYER_H

#include <QGraphicsPixmapItem>
#include <QObject>

#include "exit.h"
#include "game.h"
#include "gameitem.h"
#include "healthbar.h"
class Game;

class Player : public QObject, public QGraphicsPixmapItem {
Q_OBJECT
private:
    int speed = 10;
    int health = 5;
    Game *game;
    Healthbar *lives;
    void keyPressEvent(QKeyEvent *event);
    void collision();
signals:
    void itemCollected(GameItem *item);
public:
    Player(QGraphicsItem * parent=0);
    Player(int xPos, int yPos, Game *game);
    ~Player();
    int getHealth();
    void takeDamage(int damage);
    Healthbar* getHealthbar();
};

#endif // PLAYER_H
