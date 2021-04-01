#ifndef GAME_H
#define GAME_H

#include "Player.h"
#include "Room.h"
#include "Enemy.h"
#include "Inventory.h"
#include "Item.h"
#include "Weapon.h"

#include <QGraphicsView>
extern string gameTitle; // extern to allow use of var declared in another file
//QGraphicsView class provides a widget for displaying the contents of a QGraphicsScene.
class Game : public QGraphicsView  {
    Q_OBJECT
private:
    Room *a, *b, *c, *d, *e, *f, *g, *h, *i;
    Enemy *monster;
    Weapon *weapon;
    void createRooms();
    //populate rooms fn
    void printWelcome();
    void printHelp();

private slots:
    void removeEnemy(Enemy *enemy);
    void removeFromRoom(GameItem *item);

public:
    Player *player;
    Room *currentRoom;
    Inventory *inventory;
    Game(QWidget *parent = nullptr);
    ~Game();
};

#endif // GAME_H


