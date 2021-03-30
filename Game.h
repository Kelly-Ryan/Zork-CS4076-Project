#ifndef GAME_H
#define GAME_H

#include <QGraphicsView>
#include <QGraphicsScene>
#include "Inventory.h"
#include "Weapon.h"

extern string gameTitle;

class Game : public QGraphicsView
{
  Q_OBJECT
public:
    Game();
    QGraphicsScene *scene;
    Inventory *inventory;

public slots:
    void removeFromScene(Item *item);
};

#endif // GAME_H
