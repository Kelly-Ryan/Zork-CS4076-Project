#include "weapon.h"
#include <QtDebug>

Weapon::Weapon()
{
}


Weapon::~Weapon()
{
    delete damage;
}

Weapon::Weapon(string description, int destruction,string imgPath):GameItem(description,imgPath)
{
    damage = new int;
    *damage = destruction;
}

Weapon::Weapon(const Weapon &weapon):GameItem(weapon)
{
    damage = new int;
    *damage = *(weapon.damage);
}

QString Weapon::itemInfo()
{
    return qtDescription + QString::fromStdString(" Damage:") + QString::number(getDamage());
}

int Weapon::getDamage()
{
    return *damage;
}

