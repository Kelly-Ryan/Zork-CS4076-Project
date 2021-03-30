#ifndef ROOM_H
#define ROOM_H

#include "exit.h"
#include "player.h"

#include <QGraphicsScene>
#include <QImage>
#include <map>
#include <string>
#include <vector>

using namespace std;
using std::vector;

class Room : public QGraphicsScene {
private:
    QGraphicsScene *scene;
    Player *player;
    Exit *northExit, *southExit, *eastExit, *westExit;
    string description;
    map<string, Room*> exits;
    string exitString();
public:
   Room(string description, QImage background);
   void setExits(Room *north, Room *east, Room *south, Room *west);
   Room* nextRoom(string direction);
   ~Room();
};

#endif // ROOM_H
