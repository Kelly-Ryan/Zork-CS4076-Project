#include "room.h"

#include <cstdlib>
#include <cctype>
#include <time.h>

Room::Room(string description, QImage background, bool isLocked)
{
    this->description = description;                    //set room description
    this->isLocked = isLocked;                          //set locked status
    setSceneRect(0,0,1000,600);                         //set scene dimensions
    setBackgroundBrush(QBrush(QImage(background)));     //set scene image

    QGraphicsTextItem *roomName = new QGraphicsTextItem(QString::fromStdString(description));
    QFont roomFont ("Adventure", 25);
    roomName->setFont(roomFont);
    roomName->setDefaultTextColor("white");
    roomName->setPos(25,25);
    addItem(roomName);
}

void Room::setExits(Room *north, Room *south, Room *east, Room *west) {
    if (north != NULL){
        exits["north"] = north;
        northExit = new Exit("north");
        addItem(northExit);
    }

    if (south != NULL){
        exits["south"] = south;
        southExit = new Exit("south");
        addItem(southExit);
    }

    if (east != NULL){
        exits["east"] = east;
        eastExit = new Exit("east");
        addItem(eastExit);
    }

    if (west != NULL){
        exits["west"] = west;
        westExit = new Exit("west");
        addItem(westExit);
    }
}

Room* Room::nextRoom(string direction) {
    map<string, Room*>::iterator next = exits.find(direction); //returns an iterator for the "pair"
    if (next == exits.end()){
        return NULL; // if exits.end() was returned, there's no room in that direction.
    } else {
    return next->second; // If there is a room, remove the "second" (Room*) part of the "pair" (<string, Room*>) and return it.
    }
}

void Room::populateRoom(GameItem *roomItems[],int numItems)
{
    srand(time(NULL));
    for(int i=0;i<numItems;i++)
    {
      roomItems[i]->setPos(rand()%(700-300+1)+300,rand()%(500-100+1)+100);
      addItem(roomItems[i]);
    }

}

string Room::getRoomName(){
    return description;
}

Room::~Room(){
    delete northExit;
    delete southExit;
    delete eastExit;
    delete westExit;
}

