#ifndef GAME_H
#define GAME_H

#include <QGraphicsView>

#include "player.h"
#include "room.h"

class Player;

//QGraphicsView class provides a widget for displaying the contents of a QGraphicsScene.
class Game : public QGraphicsView  {
    Q_OBJECT
private:
    Room *a, *b, *c, *d, *e, *f, *g, *h, *i;
    void createRooms();
    void printWelcome();
    void printHelp();
public:
    Player *player;
    Room *currentRoom;
    Game(QWidget *parent = nullptr);
    ~Game();
};

#endif // GAME_H
