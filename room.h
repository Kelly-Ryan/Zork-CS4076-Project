#ifndef ROOM_H
#define ROOM_H

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
    map<string, Room*> exits;
    string exitString();
public:
   Room();
   void setExits(Room *north, Room *east, Room *south, Room *west);
   Room* nextRoom(string direction);
   ~Room();
};

#endif // ROOM_H
