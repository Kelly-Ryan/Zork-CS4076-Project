#ifndef ROOM_H
#define ROOM_H

#include "exit.h"
#include "gameitem.h"

#include <map>
#include <string>

#include <QGraphicsScene>
#include <QImage>

class Room : public QGraphicsScene
{
private:
    Exit *northExit, *southExit, *eastExit, *westExit;
    string description;
    map<string, Room*> exits;

public:
   Room(string description, QImage background, bool isLocked);
   string getRoomName();
   ~Room();
   void setExits(Room *north, Room *east, Room *south, Room *west);
   Room* nextRoom(string direction);
   void populateRoom(GameItem *roomItems[],int numItems);
   bool isLocked;
};

#endif // ROOM_H
