#ifndef ROOMKEY_H
#define ROOMKEY_H

#include "gameitem.h"

class RoomKey: public GameItem
{
public:
    RoomKey();
    string description;
    RoomKey(string description, string imgPath);
    virtual QString itemInfo();
};

#endif // ROOMKEY_H
