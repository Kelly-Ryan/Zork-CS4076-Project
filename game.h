#ifndef GAME_H
#define GAME_H

#include "player.h"
#include "room.h"

#include <QWidget>
#include <QGraphicsView>
#include <QGraphicsScene>

//QGraphicsView class provides a widget for displaying the contents of a QGraphicsScene.
class Game : public QGraphicsView  {
    Q_OBJECT
private:
    void createRooms();
    void printWelcome();
    void printHelp();
public:
    Game(QWidget *parent = nullptr);
    Player *player;
    Room *a, *b, *c, *d, *e, *f, *g, *h, *i, *currentRoom;
    ~Game();
};

#endif // GAME_H
