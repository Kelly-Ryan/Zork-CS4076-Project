#ifndef ITEM_H_
#define ITEM_H_

#include "gameitem.h"

class Item:public GameItem
{
private:
    const int usuageLimit;
    int uses = 0;
    int usesRemaining();

public:

    Item (string description, float weight, int usuageLimit, string imgPath);
    Item();
    void useItem();
    virtual QString itemInfo();
    int getUsuageLimit() const;
    int numberOfUses();
    Item operator++(int);
};


#endif /*ITEM_H_*/
