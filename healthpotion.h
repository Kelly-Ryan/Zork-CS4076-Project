#ifndef HEALTHPOTION_H
#define HEALTHPOTION_H

#include "gameitem.h"

class HealthPotion: public GameItem
{
private:
    int bonus;
public:
    HealthPotion(string imgPath,int bonus);
    virtual QString itemInfo();
    int getBonus();
};

#endif // HEALTHPOTION_H
