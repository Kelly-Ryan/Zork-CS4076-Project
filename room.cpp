#include "room.h"
#include "game.h"
#include "exit.h"
#include <QGraphicsScene>

using namespace std;

Room::Room(){
    setSceneRect(0,0,1000,600);              //set scene dimensions
    setBackgroundBrush(QBrush(QImage(":images/images/room1bg.png")));

    //set exits

    Player *player = new Player(450,450);
    addItem(player);
}

void Room::setExits(Room *north, Room *south, Room *east, Room *west) {
    if (north != NULL)
        exits["north"] = north;
    if (east != NULL)
        exits["east"] = east;
    if (south != NULL)
        exits["south"] = south;
    if (west != NULL)
        exits["west"] = west;
}

Room* Room::nextRoom(string direction) {
    map<string, Room*>::iterator next = exits.find(direction); //returns an iterator for the "pair"
    if (next == exits.end())
        return NULL; // if exits.end() was returned, there's no room in that direction.
    return next->second; // If there is a room, remove the "second" (Room*)
                // part of the "pair" (<string, Room*>) and return it.
}

Room::~Room(){

}

