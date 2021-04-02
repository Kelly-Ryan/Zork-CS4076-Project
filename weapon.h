#ifndef WEAPON_H
#define WEAPON_H

#include "gameitem.h"
class Weapon : public GameItem
{
private:
    int damage;

public:
    Weapon();
    Weapon(string description, float weight, int damage, string imgPath);
    void useItem();
    virtual QString itemInfo();
    int getDamage();
};

#endif // WEAPON_H


