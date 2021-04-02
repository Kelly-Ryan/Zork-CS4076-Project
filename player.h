#ifndef PLAYER_H
#define PLAYER_H

#include <QGraphicsPixmapItem>
#include <QObject>

#include "exit.h"
#include "game.h"

class Game;

class Player : public QObject, public QGraphicsPixmapItem {
private:
    int speed = 10;
    Game *game;
    void keyPressEvent(QKeyEvent *event);
    void collision();

public:
    Player(QGraphicsItem * parent=0);
    Player(int xPos, int yPos, Game *game);
    ~Player();
};

#endif // PLAYER_H
