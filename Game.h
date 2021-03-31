#ifndef GAME_H
#define GAME_H

#include <QGraphicsView>
#include <QGraphicsScene>
#include "Inventory.h"
#include "Weapon.h"
#include "Item.h"
#include "Enemy.h"

extern string gameTitle; // extern to allow use of var declared in another file

class Game : public QGraphicsView
{
  Q_OBJECT
public:
    Game();
    QGraphicsScene *scene;
    Inventory *inventory;

public slots:
    void removeFromScene(GameItem *item);
};

#endif // GAME_H
