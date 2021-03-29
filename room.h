#ifndef ROOM_H
#define ROOM_H

#include <QGraphicsScene>
#include <QImage>
#include <map>
#include <string>
#include <vector>

using namespace std;
using std::vector;

class Room {
private:
    string roomName;
    QImage bgBrush;
//    vector <Item> itemsInRoom;
    QGraphicsScene *scene;
    map<string, Room*> exits;
    string exitString();
public:
   Room(string description, QImage bgBrush);
   int numberOfItems();
   void setExits(Room *north, Room *east, Room *south, Room *west);
   string shortDescription();
   string longDescription();
   Room* nextRoom(string direction);
//   void addItem(Item *inItem);
//   string displayItem();
//   int isItemInRoom(string inString);
//   void removeItemFromRoom(int location);
   ~Room();
};

#endif // ROOM_H
