#ifndef PLAYER_H
#define PLAYER_H

#include <QGraphicsPixmapItem>
#include <QObject>
#include "Room.h"
#include "Weapon.h"
#include "Enemy.h"

class Player : public QObject, public QGraphicsPixmapItem {
    Q_OBJECT
private:
    int speed = 10;
    Room *playerLocation;
    GameItem *itemHolding;
    void keyPressEvent(QKeyEvent *event);
    void exitCollision();

signals:
    void defeatedEnemy(Enemy *enemy);

public:
    Player(QGraphicsItem * parent=0);
    Player(int xPos, int yPos);
    ~Player();
    GameItem * getItemHolding(); // dont know if need

};

#endif // PLAYER_H
