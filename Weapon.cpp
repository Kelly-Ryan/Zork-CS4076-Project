#include "Weapon.h"

Weapon::Weapon()
{
}

Weapon::Weapon(string description, float weight, int usuageLimit, int damage,string imgPath):Item(description,weight, usuageLimit,imgPath)
{
    this->damage = damage;
}

