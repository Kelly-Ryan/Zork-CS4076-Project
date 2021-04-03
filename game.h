#ifndef GAME_H
#define GAME_H

#include <QGraphicsView>
#include "player.h"
#include "enemy.h"
#include "room.h"
#include "inventory.h"
#include "item.h"
#include "gameitem.h"
#include "weapon.h"

class Player;
class Enemy;
extern string gameTitle; // extern to allow use of var declared in another file
//QGraphicsView class provides a widget for displaying the contents of a QGraphicsScene.
class Game : public QGraphicsView  {
    Q_OBJECT
private:
    Room *a, *b, *c, *d, *e, *f, *g, *h, *i;
    Enemy *monster;
    Inventory *inventory;
    void createRooms();
    void printWelcome();
    void printHelp();
private slots:
    void removeFromRoom(GameItem *item);
public:
    Player *player;
    Room *currentRoom;
    Game(QWidget *parent = nullptr);
    ~Game();
};

#endif // GAME_H
