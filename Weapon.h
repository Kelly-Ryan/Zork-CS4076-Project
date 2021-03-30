#ifndef WEAPON_H
#define WEAPON_H

#include "Item.h"
class Weapon : public Item
{
private:
    int damage;

public:
    Weapon();
    Weapon(string description, float weight, int usuageLimit, int damage, string imgPath);
};

#endif // WEAPON_H

//override useItem or make an attack fn
