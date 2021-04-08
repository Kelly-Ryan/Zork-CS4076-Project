#include "weapon.h"
#include <QtDebug>

Weapon::Weapon()
{
}


Weapon::~Weapon()
{
    delete d;
}

Weapon::Weapon(string description, float weight, int damage,string imgPath):GameItem(description,weight,imgPath)
{
    d = new int;
    *d = damage;
}

Weapon::Weapon(string description, int damage):GameItem(description)
{
    d = new int;
    *d = damage;
}

Weapon::Weapon(const Weapon &weapon):GameItem(weapon)
{
    d = new int;
    *d = *(weapon.d);
}

QString Weapon::itemInfo()
{
    return qtDescription + QString::fromStdString("\tDamage Inflicted:") + QString::number(getDamage());
}

int Weapon::getDamage()
{
    return *d;
}

