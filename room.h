#ifndef ROOM_H
#define ROOM_H

#include "exit.h"

#include <map>
#include <string>

#include <QGraphicsScene>
#include <QImage>

class Room : public QGraphicsScene {
private:
    Exit *northExit, *southExit, *eastExit, *westExit;
    string description;
    map<string, Room*> exits;

public:
   Room(string description, QImage background);
   void setExits(Room *north, Room *east, Room *south, Room *west);
   Room* nextRoom(string direction);
   ~Room();
};

#endif // ROOM_H
