#ifndef GAME_H
#define GAME_H

#include "player.h"
#include "room.h"

#include <QWidget>
#include <QGraphicsView>
#include <QGraphicsScene>

//QGraphicsView class provides a widget for displaying the contents of a QGraphicsScene.
class Game : public QGraphicsView  {        //inheritance
    Q_OBJECT

private:
    Room *currentRoom;
    void createRooms();
    void printWelcome();
    void printHelp();
    void go(string direction);


public:
    Game(QWidget *parent = nullptr);
    Player *player;
    QGraphicsScene *room1scene, *room2scene;
    void changeRoom(QGraphicsScene *room);
    ~Game();
};

#endif // GAME_H
