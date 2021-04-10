#ifndef ROOMKEY_H
#define ROOMKEY_H

#include "gameitem.h"

class RoomKey: public GameItem
{
public:
    RoomKey();
    virtual QString itemInfo();
};

#endif // ROOMKEY_H
