#ifndef HEALTHPOTION_H
#define HEALTHPOTION_H

#include "gameitem.h"

class HealthPotion: public GameItem
{
private:
    struct{
      unsigned int bonus : 2; //Allows to store values between 0-2
    };
public:
    HealthPotion(string imgPath,int bonus);
    virtual QString itemInfo();
    int getBonus();
};

#endif // HEALTHPOTION_H
