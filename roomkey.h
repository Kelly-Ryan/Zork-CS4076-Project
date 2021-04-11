#ifndef ROOMKEY_H
#define ROOMKEY_H

#include "gameitem.h"

class RoomKey: public GameItem
{
public:
    RoomKey();

    RoomKey(string description, string imgPath);

};

#endif // ROOMKEY_H
