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
    bool isLocked;
public:
   Room(string description, QImage background, bool isLocked);
   void setExits(Room *north, Room *east, Room *south, Room *west);
   Room* nextRoom(string direction);
   void populateRoom(GameItem *roomItems[],int numItems);
   string getRoomName();
   void setIsLocked(bool b);
   bool getIsLocked();
   ~Room();
};

#endif // ROOM_H
